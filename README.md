**Руководство по взлому ~~жопы~~ стека Эрика**
-----------------------------------------
1 ошибка: 
	На строчке 118 в stack.cpp можно заметить, что после realloc нет проверки на stk.data == NULL
	Это означает, что в случае, если реаллок не сможет найти нужный по размеру блок памяти и вернет NULL, стек упадет
	так как он попытается обратится по адресу NULL. 
2 ошибка:
	Нету проверки на bad ptr, для stk.data (значения, зарезервированные системой, обращение к которым ведет к ошибке)
	пример main.cpp, ломающий стек:

 	#include <stdio.h>
	#include "stack.h"

	int main()
	{

	Stack stk = {};	
	stk.data = (val_t*)21;

	for (int i = 0 ; i < 12 ; i++)
	{
		StackPush(&stk, 228 * i);
	}

	StackDump(&stk);
	return 0;
	}
3 ошибка: 
	В строчке 291 неверно считается 3*sizeof(stack), так как stack - указатель на структуру Stack, поэтому 3*sizeof(stack) = 12. (А не нужные в этом месте 32 байта)
	Значит хеш считается только для первых 12 байт структуры, в эти 12 байт входит 8 байт канарейки и 4 байта переменной, в которой лежит стек
	Значит хеш никак не проверяет значения capacity и size. Пример main.cpp, при котором стек работает неверно, но не понимает этого.  
#include <stdio.h>
#include "stack.h"

int main()
{
	
	int a[2] = {};
	Stack stk = {};
	int b[2] = {};
		
	StackCtor(&stk, 10);
	printf("sizeof Stack = %d\n", sizeof(Stack));
	printf("sizeof uint64_t = %d\n", sizeof(uint64_t));
	printf("sizeof uint32_t = %d\n", sizeof(uint32_t));
	printf("sizeof val_t* = %d\n", sizeof(val_t*));
	printf("sizeof size_t = %d\n", sizeof(size_t));
	printf("sizeof int = %d\n", sizeof(int));
	printf("sizeof uint64_t = %d\n", sizeof(uint64_t));
	stk.data = (val_t*)21;
	for (int i = 0 ; i < 12 ; i++)
	{
		StackPush(&stk, 228 * i);
	}
	stk.size -= 2; 
	printf("\n%d\n", StackPop(&stk));
	//stk.data = (val_t *)1000;
	a[1] = 12312;
	b[1] = 21352;
	a[0] = 12312;
	b[0] = 21352;
	printf("ADS");

	StackDump(&stk);
}
