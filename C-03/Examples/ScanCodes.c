//���������� ASCII � Scan-����� � ����������

//#include<stdio.h>
//#include<locale.h>
//#include<conio.h>	/*������ � �������� */
//
//#define ESC 0x1B
//
//int main()
//{
//	int code;
//	setlocale(LC_CTYPE, "");
//	printf("��������� �������, �������� ����.\n"
//		"0X00ZZ - ASCII-��� (������� �������)\n"
//		"0XZZ00 - Scan-��� (����������� �������\n"
//		"Esc-�����\n");
//
//	do
//	{
//		code = _getch(); //���� ������� � �������
//		if (code == 0 || code == 0xE0) //����������� �������
//			code = _getch() << 8;
//		printf("%#06x\n", code);
//	}
//	while (code != ESC);
//
//	return 0;
//}
