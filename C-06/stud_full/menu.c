#include "stud.h"
int getlimint(const wchar_t *tips, int min, int max);

void menu(const menu_item *p, int n)
{
	int i, r;

	extern student *astud;
	extern int nstud;
	init();

	while(1)
	{
		system("cls");
		for(i=0; i<n; ++i)
			wprintf(L"%2d. %s\n", i+1, p[i].txt);
		wprintf(L"%2d. %s\n\n", 0, L"Выход");
		r=getlimint(L"Введите номер", 0, i);
		system("cls");
		if(--r<0) break;
		nstud=p[r].cmd(astud,nstud);
		wprintf(L"\nНажмите любую клавишу ... ");
		getch();
	}
}