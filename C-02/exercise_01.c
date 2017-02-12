/*
 * ¬вести длину отрезка с указанием шкалы измерени€ (c Ц сантиметры, i Ц дюймы), напечатать результат в 
 * обеих шкалах: например,
 * при вводе Ђ2iї напечатать Ђ2Ф= 5.08 cmї
 * при вводе Ђ5.08cї напечатать Ђ5.08 cm = 2Фї
 */

//#include <stdio.h>
//#include <locale.h>
//
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//
//	int i = 0;
//	float cmIn = 2.54f;;
//	float fInput = 0.0f; // переменна€ дл€ ввода данных
//	float cutIn = 0.0f, cutCm = 0.0f; // переменные дл€ отрезка в разных единицах
//	char c;
//
//	start_input: // начало ввода данных
//	
//	printf("¬вести длину отрезка с указанием \nшкалы измерени€ (c Ц сантиметры, i Ц дюймы): ");
//	i = scanf("%f%c", &fInput, &c);
//	//fflush(stdout);
//
//	if ((c != 'c' || c != 'i') && i != 2)
//	{
//		printf("Ќеверно введены данные. ѕовторите ввод!\n");
//		goto start_input; // если данные введены неверно, идем в начало ввода
//	}
//	cutIn = (c == 'i' ? fInput : fInput / cmIn);
//	cutCm = (c == 'c' ? fInput : fInput * cmIn);
//
//	if(c == 'i') printf("%.2f\" = %.2f cm\n",cutIn, cutCm);
//	else printf("%.2f cm = %.2f\"\n", cutCm, cutIn);
//
//	return 0;
//}