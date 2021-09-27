#include "functions.h"

int StackCtor (Stack* stk, int capasity)
{
    stk->data = (tmpn*) calloc(capasity, sizeof(tmpn));
    if (stk->data == NULL)
    {
        printf("WHAT ARE U DOING? YOUR MEMORY SAID U GOODBYE");
        return MEMORY_LEAK;
    }
    stk->capasity += capasity;
    return CORRECT;
}

int StackReCtor (Stack* stk, int capasity)
{
    stk->capasity += capasity;
    stk->data = (tmpn*) realloc(stk->data, sizeof(tmpn) * stk->capasity);
    if (stk->data == NULL)
    {
        printf("\nWHAT ARE U DOING? YOUR MEMORY SAID U GOODBYE\n");
        return MEMORY_LEAK;
    }

    return CORRECT;
}

int StackPush (Stack* stk, tmpn value)
{
    if (stk->size_of_stack == stk->capasity)
    {
        int correck_check = 0;
        correck_check = StackReCtor(stk, stk->capasity);
        if (correck_check == MEMORY_LEAK)
            return MEMORY_LEAK;
    }

    stk->data[stk->size_of_stack++] = value;

    return 0;
}


tmpn StackPop (Stack* stk)
{
    if (stk->size_of_stack - 1  == stk->capasity/3)
    {
        stk->data = (tmpn*) realloc(stk->data, stk->capasity * 2 / 3 * sizeof(tmpn));
        if (stk->data == NULL)
        {
            printf("WHAT ARE U DOING? YOUR MEMORY SAID U GOODBYE");
            return MEMORY_LEAK;
        }
        stk->capasity = stk->capasity * 2 / 3;

    }

    return stk->data[--stk->size_of_stack];

}

void StackDump (const Stack* stk)
{







}


















