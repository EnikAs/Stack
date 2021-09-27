#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int elem;

const int CONST_FOR_MR_DANIIL = 2;

enum for_memory_allocation_check
{
    CORRECT,
    INCORRECT,
    MEMORY_LEAK
};

struct Stack
{
    elem* data;

    int size_of_stack;
    int capacity;

};

int StackCtor(Stack* stk, int capacity);

void StackDump (const Stack* stk);

int StackReCtor (Stack* stk);

int StackPush (Stack* stk, elem value);

elem StackPop (Stack* stk);

#endif // FUNCTIONS_H_INCLUDED
