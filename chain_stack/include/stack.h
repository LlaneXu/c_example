#ifndef _STACK_H_
#define _STACK_H_

#include "chain.h"

typedef P_node  Stack;

/**
 * 初始化堆栈
 * @return
 */
Stack stack_malloc();

void stack_free(Stack stack);
/***
 * 堆栈推入数据。
 * @param p_data
 */
void stack_push(Stack stack, void* p_data);

/***
 * 堆栈读取数据
 * @return
 */
void* stack_pop(Stack stack);

#endif