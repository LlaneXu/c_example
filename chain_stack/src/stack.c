#include <stdio.h>
#include "stack.h"

/**
 * 初始化堆栈
 * @return
 */
Stack stack_malloc() {
    return chain_malloc();
}

void stack_free(Stack stack) {
    chain_free(stack);
}
/***
 * 堆栈推入数据。
 * @param p_data
 */
void stack_push(Stack stack, void* p_data) {
    chain_add_end(stack, p_data);
}

/***
 * 堆栈读取数据
 * @return
 */
void* stack_pop(Stack stack) {
    if (!stack) {
        return NULL;
    }
    void * p_data;
    P_node temp = chain_get_end(stack);
    chain_remove(temp, &p_data);
    return p_data;
}