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
		{L"Ввод с клавиатуры", input},
		{L"Вывод на экран", output},
		{L"Сортировка по алфавиту", sortname},
		{L"Сортировка по курсам", sortyear},
		{L"Сортировка по успеваемости", sortmark},
		{L"Письмо в деревню", letter},
		{L"Загрузка из файла", load},
		{L"Сохранение в файле", save}
	};
 
	setlocale(LC_CTYPE,".866");
	menu(pos, sizeof pos / sizeof *pos);
}