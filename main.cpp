#include "Лаб. раб. 6.h"

int main()
{
	SetConsoleCP(1251);                          //Объявление данных
	SetConsoleOutputCP(1251);
	struct toys* toy = NULL;
	struct list *head = NULL, *current = NULL;
	toy = toysallocation(toy);
	head = listallocation(head);
	current = listallocation(current);
	FILE *flist = NULL;
	puts("Данные о игрушке:");
	menu(toy, head, flist);          //Функция для работы с меню программы
	return 0;
}