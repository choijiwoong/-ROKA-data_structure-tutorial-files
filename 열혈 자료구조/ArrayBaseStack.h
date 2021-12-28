#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#defien STACK_LEN 100//enough

typedef int Data;

typedef struct _arrayStack{
	Data stackArr[STACK_LEN];//we can get advantage of Array by knowing floor of stack by index 0.
	int topIndex;//get top Index location. maximum point of data in STACK_LEN.
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif
