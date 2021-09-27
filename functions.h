#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int tmpn;

enum for_memory_allocation_check
{
    CORRECT,
    INCORRECT,
    MEMORY_LEAK
};

struct Stack
{
    tmpn* data;
    int size_of_stack;
    int capasity;

};

int StackCtor(Stack* stk, int capasity);

int StackReCtor (Stack* stk, int capasity);

int StackPush (Stack* stk, tmpn value);

tmpn StackPop (Stack* stk);

#endif // FUNCTIONS_H_INCLUDED
