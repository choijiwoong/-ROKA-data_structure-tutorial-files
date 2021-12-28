//계산기 프로그램 작성에 앞서, 몇가지 주의할 특징을 요약하면 stack을 이용하여 연산자를 쌓을 때 연산자의 우선순위가 같다면 먼저 들어온 연산자가 우위,
//(는 )이 등장하기 전까지 스택에 남아있어야 하므로 모든 연산자보다 우선순위가 낮을것, )을 만나면 (부터 전부 POP할 것 
#include <stdio.h>
#include "InfixToPostfix.h"

int main(){
	char exp1[]="1+2*3";
	char exp2[]="(1+2)*3";
	char exp3[]="((1-2)+3)*(5-2)";
	
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);
	
	printf("%s \n", exp1);//print Converted Expression to Postfix(Reverse Polish Notation)
	printf("%s \n", exp2);
	printf("%s \n", exp3);
	
	return 0;
}
