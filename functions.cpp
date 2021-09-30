#include "functions.h"

int StackCtor (Stack* stk, int capacity)
{
    stk->data = (elem*) calloc(capacity, sizeof(elem));
    if (stk->data == NULL)
    {
        printf("WHAT ARE U DOING? YOUR MEMORY SAID U GOODBYE");
        return MEMORY_LEAK;
    }
    stk->capacity = capacity;
    return CORRECT;
}

int StackReSize (Stack* stk)//resize сделать статической
{
    stk->capacity *= CONST_FOR_MR_DANIIL;
    stk->data = (elem*) realloc(stk->data, sizeof(elem) * stk->capacity);
    if (stk->data == NULL)
    {
        printf("\nWHAT ARE U DOING? YOUR MEMORY SAID U GOODBYE\n");
        return MEMORY_LEAK;
    }

    return CORRECT;
}

int StackPush (Stack* stk, elem value)
{
    if (stk->size_of_stack == stk->capacity)
    {
        int correck_check = 0;
        correck_check = StackReSize(stk);
        if (correck_check == MEMORY_LEAK)
            return MEMORY_LEAK;
    }

    stk->data[stk->size_of_stack++] = value;

    return 0;
}


elem StackPop (Stack* stk)
{
    if (stk->size_of_stack - 1  == stk->capacity/3)
    {
        stk->data = (elem*) realloc(stk->data, stk->capacity * 2 / 3 * sizeof(elem));
        if (stk->data == NULL)
        {
            printf("WHAT ARE U DOING? YOUR MEMORY SAID U GOODBYE");
            return MEMORY_LEAK;
        }
        stk->capacity = stk->capacity /3 * 2;// переполнение god bless MR.DANIIL - можно этим ломать

    }
    elem tmp = stk->data[stk->size_of_stack - 1];
    (stk->data[--stk->size_of_stack]) = POISON666;
    return tmp;// если сайз unsigned, то -- все свалит в пизду !!!

}

void StackDtor (Stack* stk)
{
    stk->size_of_stack = 0;
    stk->capacity = 0;
    (stk->data) = (elem*)POISON666;
    free(stk);
}

void StackDump (int stk_correct_check, const Stack* stk, const int str_num, const char* func_name, const char* file_name )
{

    printf ("In file %s, in function %s on line %d", file_name, func_name, str_num);
    if (stk)
    {
        printf ("\n\n-------------------------------------\n\n");
        printf ("size = %d\n", stk->size_of_stack);
        printf ("capacity = %d\n", stk->capacity);
        for (int i = 0 ; i < stk->capacity ; i++)
        {
            printf ("data[%d] = %d", i, stk->data[i]);
            printf (" ptr = %p\n", &stk->data[i]);
        }
    }
    else
    {
        printf ("stk = NULL!!!");


    }
    assert(0);

}

int StackOKCheck (const Stack* stk)
{
    if (stk->size_of_stack == 0 && stk->capacity == 0)
        return CORRECT;

    if (stk == NULL)
        $StackDump(stk);

    if (stk->capacity > stk->size_of_stack)
        $StackDump(stk);

    if (stk->data == NULL);
        $StackDump(stk);




    return CORRECT;
}






