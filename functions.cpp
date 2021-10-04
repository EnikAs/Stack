#include "functions.h"

FILE* log_file = fopen("log.txt", "w");

void* my_recalloc(void* stk, size_t sz) // sz - ������ � ������
{
    stk = (void*) realloc(stk, sz);
    memset (stk, 0, sz);
    return stk;
}

int StackCtor (Stack* stk, int capacity)
{
    stk->data = (elem*) calloc(capacity, sizeof(elem));

    StackOKCheck(stk);

    stk->capacity = capacity;

    return CORRECT;
}

int StackCtor (Stack* stk, int capacity)
{
    stk->data = (elem*) calloc(capacity, sizeof(elem));

    StackOKCheck(stk);

    stk->capacity = capacity;

    return CORRECT;
}

int StackReSize (Stack* stk)//resize ������� �����������
{
    stk->capacity *= CONST_FOR_MR_DANIIL; // CONST_FOR_MR_DANIIL = 2
    stk->data = (elem*) realloc(stk->data, sizeof(elem) * stk->capacity);

    StackOKCheck(stk);

    return CORRECT;
}

int StackPush (Stack* stk, elem value)
{
    if (stk->size_of_stack == stk->capacity)
    {
        StackReSize(stk);
        StackOKCheck(stk);
    }

    //stk->data[stk->size_of_stack++] = value;

    *((elem*)( (char*)(stk->data) + sizeof(elem) * (stk->size_of_stack ++) )) = value;

    return 0;
}


elem StackPop (Stack* stk)
{
    if (stk->size_of_stack - 1  == stk->capacity/3)
    {
        stk->data = (elem*) realloc(stk->data, stk->capacity * 2 / 3 * sizeof(elem));

        StackOKCheck(stk);

        stk->capacity = stk->capacity /3 * 2;// ������������ god bless MR.DANIIL

        StackOKCheck(stk);
    }
    elem tmp = stk->data[stk->size_of_stack - 1];

    if (tmp == POISON666)
        $StackDump(stk);

    stk->data[--stk->size_of_stack] = POISON666;
    return tmp;// ���� ���� unsigned, �� -- ��� ����� ������ ��������))!!!

}

void StackDtor (Stack* stk)
{
    stk->size_of_stack = 0;
    stk->capacity = 0;
    //&(stk->data) = POISON666;
    stk->if_destructed = true;
    free(stk->data);
    free(stk);
}

void StackDump (const Stack* stk, const int str_num, const char* func_name, const char* file_name)
{

    $printf ("\nIn file %s, in function |%s| on line %d\n", file_name, func_name, str_num);
    if (stk)
    {
        $printf("-------------------------------------\n");
        $printf("Stack got some problems)))\n");
        $printf("Stack is destructed = ");
        $printf(stk->if_destructed ? "true" : "false");
        $printf("\nsize = %d\n", stk->size_of_stack);
        $printf("capacity = %d\n", stk->capacity);
        for (int i = 0 ; i < stk->capacity ; i++)
        {
            $printf("data[%d] = %d ", i, stk->data[i]);
            $printf("|| ptr = %p\n", &stk->data[i]);
        }
    }
    else
    {
        $printf("stk = NULL!!!");


    }

    assert(ERROR && "Bad stk");

}

int StackOKCheck (const Stack* stk)
{
    if (stk->size_of_stack == 0 && stk->capacity == 0)
        return CORRECT;

    if (stk == NULL)
        $StackDump(stk);

    if (stk->capacity < stk->size_of_stack)
        $StackDump(stk);

    if (stk->data == NULL)
        $StackDump(stk);

    if (stk->if_destructed == true)
        $StackDump(stk);


    return CORRECT;
}
