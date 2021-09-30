#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cassert>

#define $StackDump(stk) StackDump(stk, __LINE__, __func__, __FILE__)


typedef int elem;

const int POISON666 = 0xDEADBEEF;

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

int StackOkCheck (const Stack* stk);

void StackDump (const Stack* stk, const int str_num = 0, const char* func_name = NULL, const char* file_name = NULL );

void StackDtor (Stack* stk);

int StackReSize (Stack* stk);

int StackPush (Stack* stk, elem value);

elem StackPop (Stack* stk);

#endif // FUNCTIONS_H_INCLUDED
