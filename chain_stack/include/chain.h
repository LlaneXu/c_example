#ifndef _CHAIN_H_
#define _CHAIN_H_

typedef struct Node
{
    void* p_data;
    struct Node* p_prev;
    struct Node* p_next;
}S_node, *P_node;

/***
 * 初始化链表。第一环不作数据存储使用。永远存在。防止链表指针丢失。
 * @return
 */
P_node chain_malloc();
/***
 * 从任意一环获得链表头（不含数据的一环）
 * @param p_any_link
 * @return
 */
P_node chain_get_head(P_node p_any_link);
/***
 * 从任意一环获得链表头（包含数据的一环）
 * @param p_any_link
 * @return
 */
P_node chain_get_first_data_link(P_node p_any_link);
/**
 * 从任意一环获得最后一环
 * @param p_any_link
 * @return
 */
P_node chain_get_end(P_node p_any_link);
/***
 * 从任意位置，获取前面或者后面的第任意环
 * @param p_chain
 * @param position 正数为往后数，负数往前数。
 * @return
 */
P_node chain_get_position(P_node p_chain, int position);
/***
 * 指定位置的后面增加一环
 * @param p_head
 * @param p_data
 * @param position
 */
P_node chain_add(P_node p_chain, void* p_data);
/***
 * 链表尾部插入
 * @param p_chain 链表中间任意一环均可
 * @param p_data 需要插入的数据
 * @return 插入的一环链接
 */
P_node chain_add_end(P_node p_chain, void* p_data);
/***
 * 链条头加一环
 * @param p_chain
 * @param p_data
 * @return
 */
P_node chain_add_head(P_node p_chain, void* p_data);
/***
 * 链表弹出一环，并读取数据
 * @param p_chain 需要弹出的环链接
 * @param pp_data 通过指针的指针返回数据指针。
 * @return 返回前一环的
 */
P_node chain_remove(P_node p_chain, void** pp_data);
/***
 * 释放链表所有存储空间。链表内data数据不释放。慎用。
 * @param p_chain
 */
void chain_free(P_node p_chain);
/***
 * 获取某一环的值
 * @param p_chain
 * @return
 */
void* chain_get_value(P_node p_chain);
#endif