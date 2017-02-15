/*
* ������ ���� � ������� ��.��.����, ��������� ������������ ����� � ���������� ��������� ����
*/

#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "Russian");

	int day, month, year;
	int marker_d = 0, marker_m = 0, marker_y = 0; // ������� ������������ ��������� ���
	int markerYearVis = 0;
	int sharedMarker = 0;
	
	day = month = year = 0;
	printf("������� ���� (� ������� ��.��.����): ");
	scanf("%2d.%2d.%4d", &day, &month, &year);

	markerYearVis = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ? 1 : 0);
	// ���� 1, �� ����������, � ���� 0, �� ���

	marker_y = (year >= 0 ? 1 : 0);

	marker_m = (month >= 1 && month <= 12 ? 1 : 0);
	// ���� 1, ����� ������ ���������, � ���� 0, �� ���

	marker_d = ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
		(day >= 1 && day <= 31) ? 1 :
		(month == 4 || month == 6 || month == 9 || month == 11) &&
		(day >= 1 && day <= 30) ? 1 :
		((month == 2) && (day >= 1 && day <= 28)) ||
		((month == 2 && markerYearVis == 1) && (day >= 1 && day <= 29)) ? 1 : 0);
	// ���� 1, �� ���� ������ ���������, � ���� 0, �� ���
	sharedMarker = (marker_d == 1 && marker_m == 1 && marker_y == 1) ? 1 : 0;
	// ��������� � ������������ �������� ������
	printf("���� ������� %s ���������!\n", (sharedMarker == 1 ?	"\b" : 
		sharedMarker == 0 ? "��\a": "\n������ ������� �����������!!!\n"));

	// ������ ��������� ����

	int yearNext = 0;
	int monthNext = 0;
	int dayNext = 0; 

	// ���������� ���������� ���
	dayNext = ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
		(day == 31) ? 1 :
		(month == 4 || month == 6 || month == 9 || month == 11) &&
		(day == 30) ? 1 :
		((month == 2) && (day == 28)) ||
		((month == 2 && markerYearVis == 1) && (day == 29)) ? 1 : day + 1);

	// ���������� ������ � ����������� �� �������� ���
	monthNext = (dayNext != 1 ? month :
		day == 1 && (month + 1) < 13 ? month + 1 : 1);
	/*monthNext = ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
		(day == 31) ? month + 1 :
		(month == 4 || month == 6 || month == 9 || month == 11) &&
		(day == 30) ? month + 1 :
		((month == 2) && (day == 28)) ||
		((month == 2 && marker_y == 1) && (day == 29)) ? month + 1 : month);*/
		// ���������� �������� ����
	yearNext = (monthNext >= month ? year : year + 1);
	
	// ����� ���� �� �����
	printf("��������� ���� ����� ��� %02d.%02d.%02d ����� %02d.%02d.%02d\n", day, month, year,
		dayNext, monthNext, yearNext);

	return 0;
}