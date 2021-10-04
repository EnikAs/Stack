#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cassert>

#define DEBUG

#ifdef DEBUG

#define $StackDump(stk) StackDump(stk, __LINE__, __func__, __FILE__)

#else

#define $StackDump(stk)

#endif

#define $printf(...) fprintf(log_file, ##__VA_ARGS__)
//#define $printf(...) printf( ##__VA_ARGS__)

typedef int elem;

extern FILE* log_file;  //Да, глобальная переменная, но без нее код ужасно некрасивый))))

const int ERROR = 0;

const double POISON666 = 1000-7;//0xDED32DED;

const int CONST_FOR_MR_DANIIL = 2;

enum for_memory_allocation_check
{
    CORRECT,
    INCORRECT,
    MEMORY_LEAK
};

struct Stack
{

    long long canary1 = POISON666;
    elem* data;
    int size_of_stack;
    int capacity;
    bool if_destructed = false;
    long long canary2 = POISON666;
};

int        StackCtor           (Stack* stk, int capacity);

void*      my_recalloc         (void* stk, size_t sz); // sz - размер в байтах

int        StackOKCheck        (const Stack* stk);

void       StackDump           (const Stack* stk, const int str_num, const char* func_name, const char* file_name );

void       StackDtor           (Stack* stk);

int        StackReSize         (Stack* stk);

int        StackPush           (Stack* stk, elem value);

elem       StackPop            (Stack* stk);

#endif // FUNCTIONS_H_INCLUDED
