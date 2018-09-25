#include <mem.h>
#include <malloc.h>
#include "chain.h"

/***
 * 初始化链表。第一环不作数据存储使用。永远存在。防止链表指针丢失。
 * @return
 */
P_node chain_malloc() {
    P_node p_head = malloc(sizeof(S_node));
    memset(p_head, 0, sizeof(S_node));
    return p_head;
}

/***
 * 从任意一环获得链表头（不包含数据的一环）
 * @param p_any_link
 * @return
 */
P_node chain_get_head(P_node p_any_link) {
    if(!p_any_link){
        return NULL;
    }
    P_node p_head = p_any_link;
    while (p_head->p_prev){
        p_head = p_head->p_prev;
    }
    return p_head;
}

/***
 * 从任意一环获得链表头（包含数据的一环）
 * @param p_any_link
 * @return
 */
P_node chain_get_first_data_link(P_node p_any_link) {
    P_node p_head = chain_get_head(p_any_link);
    return p_head->p_next;
}

/**
 * 从任意一环获得最后一环
 * @param p_any_link
 * @return
 */
P_node chain_get_end(P_node p_any_link) {
    if(!p_any_link){
        return NULL;
    }
    P_node p_end = p_any_link;
    while (p_end->p_next){
        p_end = p_end->p_next;
    }
    return p_end;
}

/***
 * 从任意位置，获取前面或者后面的第任意环
 * @param p_chain
 * @param position 正数为往后数，负数往前数。
 * @return
 */
P_node chain_get_position(P_node p_chain, int position){
    if(!p_chain){
        return NULL;
    }
    P_node p_ret = p_chain;
    if (position>=0){
        while ( (position>0) && (p_ret->p_next) ){
            p_ret = p_ret->p_next;
            position--;
        }
    } else {
        while ( (position<0) && (p_ret->p_prev) ){
            p_ret = p_ret->p_prev;
            position++;
        }
    }
    /* 如果找到头了。就返回第一个有数据环 */
    if (!p_ret->p_prev) {
        p_ret = p_ret->p_next;
    }
    return p_ret;
}
/***
 * 指定位置的后面增加一环
 * 返回增加的这环链接
 * @param p_head
 * @param p_data
 * @param position
 */
P_node chain_add(P_node p_chain, void* p_data) {
    if(!p_chain) {
        return;
    }
    P_node p_temp = malloc(sizeof(S_node));
    p_temp->p_data = p_data;
    p_temp->p_prev = p_chain;
    p_temp->p_next = p_chain->p_next;

    if (p_chain->p_next) {
        p_chain->p_next->p_prev = p_temp;
    }
    p_chain->p_next = p_temp;
    return p_temp;
}

/***
 * 链表尾部插入
 * @param p_chain 链表中间任意一环均可
 * @param p_data 需要插入的数据
 * @return 插入的一环链接
 */
P_node chain_add_end(P_node p_chain, void* p_data) {
    if(!p_chain) {
        return;
    }
    P_node p_end = chain_get_end(p_chain);
    return chain_add(p_end, p_data);
}

/***
 * 链条头加一环
 * @param p_chain
 * @param p_data
 * @return
 */
P_node chain_add_head(P_node p_chain, void* p_data) {
    if(!p_chain) {
        return;
    }
    P_node p_head = chain_get_head(p_chain);
    return chain_add(p_head, p_data);
}

/***
 * 链表弹出一环，并读取数据
 * @param p_chain 需要弹出的环链接
 * @param pp_data 通过指针的指针返回数据指针。
 * @return 返回前一环的
 */
P_node chain_remove(P_node p_chain, void** pp_data) {
    if(!p_chain || !(p_chain->p_prev)) {
        return NULL;
    }
    *(pp_data) = p_chain->p_data;
    P_node p_prev = p_chain->p_prev;

    p_prev->p_next = p_chain->p_next;
    if (p_chain->p_next){
        p_chain->p_next->p_prev = p_prev;
    }
    free(p_chain);
    return p_prev;
}

/***
 * 释放链表所有存储空间。链表内data数据不释放。慎用。
 * @param p_chain
 */
void chain_free(P_node p_chain){
    P_node p_end = chain_get_end(p_chain);
    P_node p_temp;
    while(p_end){
        p_temp = p_end->p_prev;
        free(p_end);
        p_end = p_temp;
    }
}

/***
 * 获取某一环的值
 * @param p_chain
 * @return
 */
void* chain_get_value(P_node p_chain){
    return p_chain->p_data;
}