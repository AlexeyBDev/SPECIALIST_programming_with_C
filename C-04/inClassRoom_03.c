// Директивы препроцессора

// "C:\\ntw\\vers1\\test\\backup\\my.h"
// "\\ntw\\vers1\\test\\backup\\my.h" - от корневой папки
// "\\test\\backup\\my.h" - текущая папка
// "..\\..\\backup\\my.h" - два шага назад

//#include <stdio.h>
//#include <math.h>
//#include "my_function.h"


//int main()
//{
//	my_function();
//	return 0;
//}


// Калькулятор (версия 0.3)

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "rus");

	double a, b, c;
	a = b = c = 0.0;
	char op1, op2, op3;
	int err = 0;

	printf("Введите формулу с двумя значениями: ");
//-------------------------------------------------------------
	for (a = 0.0, op1 = '+'; op1 != '=' && err != 1; op1 = op2)
	{
		scanf_s("%lg %c", &b, &op2, sizeof(char));
		//-------------------------------------------------------------
		//err = 0;
		for(c = 0.0; (op2 == '*' || op2 == '/') && op2 != '=' && err != 1; op2 = op3)
		{
			scanf_s("%lg %c", &c, &op3, sizeof(char));
			switch (op2)
			{
			case '*': b *= c; break;
			case '/': b /= c; break;
			default: err = 1; break;
			}
		}
		switch (op1)
		{
		case '+': a += b; break;
		case '-': a -= b; break;
		
		default: err = 1; break; /*goto finish;*/
		}
	}
//-----------------------------------------------------------
//finish:
	if (!err)
		printf("%lg\n", a);
	else
		printf("%c - неизвестная операция!\n", op1);

	return 0;
}

//0+1*2+3