//считывание ASCII и Scan-кодов с клавиатуры

//#include<stdio.h>
//#include<locale.h>
//#include<conio.h>	/*работа с консолью */
//
//#define ESC 0x1B
//
//int main()
//{
//	int code;
//	setlocale(LC_CTYPE, "");
//	printf("Нажимайте клавиши, смотрите коды.\n"
//		"0X00ZZ - ASCII-код (обычная клавиша)\n"
//		"0XZZ00 - Scan-код (управляющая клавиша\n"
//		"Esc-конец\n");
//
//	do
//	{
//		code = _getch(); //ввод символа с консоли
//		if (code == 0 || code == 0xE0) //управляющая клавиша
//			code = _getch() << 8;
//		printf("%#06x\n", code);
//	}
//	while (code != ESC);
//
//	return 0;
//}
