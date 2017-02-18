// Директивы препроцессора

// "C:\\ntw\\vers1\\test\\backup\\my.h"
// "\\ntw\\vers1\\test\\backup\\my.h" - от корневой папки
// "\\test\\backup\\my.h" - текущая папка
// "..\\..\\backup\\my.h" - два шага назад

#include <stdio.h>
#include <math.h>
#include "my_function.h"
#include "my_function.h"

int main()
{
	my_function();
	return 0;
}