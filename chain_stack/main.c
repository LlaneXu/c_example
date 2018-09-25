#include <stdio.h>

extern void test_chain();
extern void test_stack();

int main() {
    test_chain();
    test_stack();
    return 0;
}