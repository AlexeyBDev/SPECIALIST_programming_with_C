#include "stud.h"
#include <locale.h>

int letter(student *p, int n)
{
	system("notepad.exe letter.txt");
	return n;
}

main()
{
	const menu_item pos[]=
	{
		{L"���� � ����������", input},
		{L"����� �� �����", output},
		{L"���������� �� ��������", sortname},
		{L"���������� �� ������", sortyear},
		{L"���������� �� ������������", sortmark},
		{L"������ � �������", letter},
		{L"�������� �� �����", load},
		{L"���������� � �����", save}
	};
 
	setlocale(LC_CTYPE,".866");
	menu(pos, sizeof pos / sizeof *pos);
}