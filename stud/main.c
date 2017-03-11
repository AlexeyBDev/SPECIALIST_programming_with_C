#include <locale.h>
#include <stdlib.h>
#include "data.h"
#include "iface.h"

int main()
{
	setlocale(LC_CTYPE, "rus");

	menu();

	return 0;
}