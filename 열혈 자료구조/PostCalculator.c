#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]){//Return Evaluated value by int Reverse Polish Notation Expression
	Stack stack;
	int expLen=strlen(exp);
	int i;
	char tok, op1, op2;
	
	StackInit(&stack);
	
	for(i=0; i<expLen; i++){
		tok=exp[i];//tokneize
		
		if(isdigit(tok)){//if digit, push stack
			SPush(&stack, tok-'0');
		} else{//if operator
			op2=SPop(&stack);//get operands
			op1=SPop(&stack);
			
			switch(tok){
				case '+':
					SPush(&stack, op1+op2);//push evaluated value
					break;
				
				case '-':
					SPush(&stack, op1-op2);
					break;
					
				case '*':
					SPush(&stack, op1*op2);
					break;
				
				case '/':
					SPush(&stack, op1/op2);
					break;
			}
		}
	}
	
	return SPop(&stack);
}
