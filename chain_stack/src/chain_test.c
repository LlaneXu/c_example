#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "../include/chain.h"

void test_chain(){
    P_node chain = chain_malloc();
    P_node temp;
    assert(NULL != chain);

    struct Student{
        int id;
        char name[16];
        double score;
    }d = {4, "Xiao Ming", 98.0};
    char a = 'a';
    int b = 2;
    float c = 3.1;

    chain_add_head(chain, (void*)&a);
    temp = chain_get_first_data_link(chain);
    assert('a' == *(char*)(chain_get_value(temp)));

    chain_add_end(chain, (void*)&d);
    temp = chain_get_end(chain);
    struct Student* s = (struct Student*)(chain_get_value(temp));
    assert(4 == s->id);
    assert(0 == strcmp("Xiao Ming", s->name));
    assert(98.0 == s->score);

    temp = chain_add(chain->p_next, (void*)&b);
    chain_add(temp, (void*)&c);

    temp = chain_get_position(chain, 2);
    assert(2 == *(int*)(temp->p_data));

    temp = chain_get_position(temp, 1);
    assert(fabs(3.1 - *(float*)(temp->p_data)) < 1e-4);

    void* p_data;
    temp = chain_remove(chain, &p_data);
    assert(0 == temp);

    temp = chain_get_position(chain, 1);
    chain_remove(temp, &p_data);
    assert('a' == *(char*)(p_data));

    chain_free(chain);
}