/*
 * ������ ����� ������� � ��������� ����� ��������� (c � ����������, i � �����), ���������� ��������� � 
 * ����� ������: ��������,
 * ��� ����� �2i� ���������� �2�= 5.08 cm�
 * ��� ����� �5.08c� ���������� �5.08 cm = 2��
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
//	float fInput = 0.0f; // ���������� ��� ����� ������
//	float cutIn = 0.0f, cutCm = 0.0f; // ���������� ��� ������� � ������ ��������
//	char c;
//
//	start_input: // ������ ����� ������
//	
//	printf("������ ����� ������� � ��������� \n����� ��������� (c � ����������, i � �����): ");
//	i = scanf("%f%c", &fInput, &c);
//	//fflush(stdout);
//
//	if ((c != 'c' || c != 'i') && i != 2)
//	{
//		printf("������� ������� ������. ��������� ����!\n");
//		goto start_input; // ���� ������ ������� �������, ���� � ������ �����
//	}
//	cutIn = (c == 'i' ? fInput : fInput / cmIn);
//	cutCm = (c == 'c' ? fInput : fInput * cmIn);
//
//	if(c == 'i') printf("%.2f\" = %.2f cm\n",cutIn, cutCm);
//	else printf("%.2f cm = %.2f\"\n", cutCm, cutIn);
//
//	return 0;
//}