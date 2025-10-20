#include <iostream>
#include "implement_stack_int.h"

int main() {
    stack s;
    StackNew(&s);

    std::cout << "Pushing 10, 20, 30 onto the stack." << std::endl;
    StackPush(&s, 10);
    StackPush(&s, 20);
    StackPush(&s, 30);

    std::cout << "Popping from stack: " << StackPop(&s) << std::endl;
    std::cout << "Popping from stack: " << StackPop(&s) << std::endl;

    std::cout << "Pushing 40 onto the stack." << std::endl;
    StackPush(&s, 40);

    std::cout << "Popping from stack: " << StackPop(&s) << std::endl;
    std::cout << "Popping from stack: " << StackPop(&s) << std::endl;

    StackDispose(&s);

    return 0;
}
