#include "functions.h"

using namespace std;

int main()
{
    int correct_check = 0;
    Stack stk = {};
    correct_check = StackCtor(&stk, 1);

    if (correct_check == MEMORY_LEAK)
    {
        printf ("Memory leak");
        return 0;
    }

    for (int i = 500 ; i > 0 ; i--)
    {

    printf (" cap = %d \n", stk.capasity);
        StackPush(&stk, i);
    }
     while (stk.size_of_stack)
        {
        printf ("\n|| cap = %d ||", stk.capasity);
        printf ("%d ", StackPop(&stk));
        }

    return 0;
}








