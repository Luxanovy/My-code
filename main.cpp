#include "���. ���. 6.h"

int main()
{
	SetConsoleCP(1251);                          //���������� ������
	SetConsoleOutputCP(1251);
	struct toys* toy = NULL;
	struct list *head = NULL, *current = NULL;
	toy = toysallocation(toy);
	head = listallocation(head);
	current = listallocation(current);
	FILE *flist = NULL;
	puts("������ � �������:");
	menu(toy, head, flist);          //������� ��� ������ � ���� ���������
	return 0;
}