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

    printf (" cap = %d \n", stk.capacity);
        StackPush(&stk, i);
    }
    StackDump (&stk);
    double a = -0;
    double b = 0;
    if (b > a)
        printf ("GOVNOGOVNOGOVNOGOVOGOnsidjf");


     /*while (stk.size_of_stack)
        {
        printf ("\n|| cap = %d ||", stk.capacity);
        printf ("%lg ", StackPop(&stk));
        }*/

    return 0;
}








