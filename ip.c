#include <stdio.h>
#include <string.h>

#define MAX 20

int stack[MAX], top = -1;
char expres[MAX], post[MAX];

void Push(char s)
{
	top = top + 1;
	stack[top] = s;
}
char Pop()
{
	char e;
	e = stack[top];
	top = top - 1;
	return e;
}
char Top()
{
	return stack[top];;
}
int Priority(char s)
{
	int p = 0;
	switch(s)
	{
	case '(':
		p = 0;
		break;
	case '+':
	case '-':
		p = 1;
		break;
	case '*':
	case '/':
	case '%':
		p = 2;
		break;
	case '^':
		p = 3;
		break;
	}
	return p;
}

int main()
	{
	int i;
	printf("Enter the infix expression : ");
	gets(expres);
	for(i = 0; i < strlen(expres); i++)
		{
		if(expres[i] >= 'a' && expres[i] <= 'z')
		printf("%c", expres[i]);
		else if(expres[i] == '(')
		Push(expres[i]);
		else if(expres[i] == ')')
		{
			while(Top() != '(')
			printf("%c", Pop());
			Pop();
		}
		else
		{
			while(Priority(expres[i])<=Priority(Top()) && top!=-1)
			printf("%c", Pop());
			Push(expres[i]);
		}
		}
	for(i = top; i >= 0; i--)
		printf("%c", Pop());
	return 0;
}