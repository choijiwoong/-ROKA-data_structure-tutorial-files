//���� ���α׷� �ۼ��� �ռ�, ��� ������ Ư¡�� ����ϸ� stack�� �̿��Ͽ� �����ڸ� ���� �� �������� �켱������ ���ٸ� ���� ���� �����ڰ� ����,
//(�� )�� �����ϱ� ������ ���ÿ� �����־�� �ϹǷ� ��� �����ں��� �켱������ ������, )�� ������ (���� ���� POP�� �� 
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
