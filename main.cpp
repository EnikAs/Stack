#include "functions.h"

//using namespace std;

int main()
{
    int correct_check = 0;
    Stack stk = {};
    correct_check = StackCtor(&stk, 3);

    if (correct_check == MEMORY_LEAK)
    {
        printf ("Memory leak");
        return 0;
    }

    for (int i = 500 ; i > 0 ; i--)
    {
        StackPush(&stk, i);
    }

    for (int i = 250 ; i > 0 ; i--)
    {
        StackPop(&stk);
    }

    $StackDump(&stk);

    StackDtor (&stk);

    return 0;
}








