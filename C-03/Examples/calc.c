//калькулятор верс 0.3
#include<stdio.h>
#include<locale.h>

int main()
{
	double a, b, c;
	char op1, op2, op3;
	int err;

	setlocale(LC_CTYPE, "");

	printf("Введите формулу:\n");
//---------------------------------------------------
	err = 0;
	for (a = 0., op1 = '+'; op1 != '='; op1 = op2)
	{
		for (scanf_s("%lg %c", &b, &op2, sizeof(char));
			op2 == '*' || op2 == '/';
			op2 = op3)
		{
			scanf_s("%lg %c", &c, &op3, sizeof(char));
			switch (op2)
			{
			case '*': b *= c; break;
			case '/': b /= c; break;
				//		default: err = 1; goto finish;
			}
		}
		switch (op1)
		{
		case '+': a += b; break;
		case '-': a -= b; break;
//		default: err = 1; goto finish;
		}
	}
//---------------------------------------------------
finish: 
	if(!err)
		printf("%lg\n", a);
	else
		printf("%c - неизвестная операция\n", op1);
}


