#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"//include both!

int EvalInfixExp(char exp[]){
	int len=strlen(exp);
	int ret;
	char* expcpy=(char*)malloc(len+1);
	strcpy(expcpy, exp);//copy exp
	
	ConvToRPNExp(expcpy);//convert to Postfix expression
	ret=EvalRPNExp(expcpy);//save Evaluated value of expcpy
	
	free(expcpy);
	return ret;
}
