#include <string.c>//For isdigit. has useful functions for char*
#include <stdlib.h>
#include <ctype.h>//For memset(Initialization of list)
#include "ListBaseStack.h"//use stack

int GetOpPrec(char op){//get argument's opertation priority
	switch(op){
		case '*':
		case '/':
			return 5;
			
		case '+':
		case '-':
			return 3;
		
		case '('://( must get lowest priority because it muse ramain in stack util )
			return 1;
			
		default:
			return -1;//operand! go to converted array directly.
	}
}

int WhoPrecOp(char op1, char op2){
	int op1Prec=GetOpPrec(op1);//op1's priority
	int op2Prec=GetOpPrec(op2);
	
	if(op1Prec>op2Prec)//calculate result of comparing
		return 1;
	else if(op1prec<op2Prec)
		return -1;
	else
		return 0;
}

//PostFix is also called as Reverse Polish Notation(RPN)
void ConvToRPNExp(char exp[]){//(갑자기 생각난것! C++에서는 reference로 배열과 똑같이 움직이게 할 수 있다!) 
	Stack stack;
	int expLen=strlen(exp);//get length
	char* convExp=(char*)malloc(expLen+1);//converted expression to RPN
	
	int i, idx=0;//for
	char tok, popOp;//token, operation
	
	memset(convExp, 0, sizeof(char)*expLen+1);//initialize convExp(converted array) to ZERO
	StackInit(&stack);//initialization
	
	for(i=0; i<expLen; i++){//for each element's index
		tok=exp[i];//get one char(token)
		if(isdigit(tok)){//if it's digit, directly add to convExp
			convExp[idx++]=tok;
		} else{
			switch(tok){//if tok is operation,
				case '(':
					SPush(&stack, tok);//push to operation stack
					break;
				
				case ')':
					while(1){
						popOp=SPop(&stack);
						if(popOp=='(')
							break;
						convExp[idx++]=popOp;//pop until (, add to convExp
					}
					break;
					
				case '+': case '-':
				case '*': case '/':
					while(!SIsEmpty(&stack)&&WhoPrecOp(SPeek(&stack), tok)>=0)//compare priority with tok, stack's top element by peek
						convExp[idx++]=SPop(stack);//if tok is lower than stack's top, pop & add all to convExp
					
					SPush(&stack, tok);//push tok to stack
					break;
					
				default://exception handling by exit_Wrong operation
					printf("Wrong operation! we cannot read %c\n", tok);
					exit(-1);
			}
		}
	}
	
	while(!SIsEmpty(&stack))//pop & add to stack left element on stack.
		convExp[idx++]=SPop(&stack);
		
	strcpy(exp, convExp);//copy to exp(argument)
	free(convExp);//free
}
