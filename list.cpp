#include "���. ���. 6.h"

void inputDATA(list* temp, toys* t)                //������� ��� ������ ������� �������� � �������� ����
{
	printf("\nName toys: ");                            //���� ������ � ���� ���������
	rewind(stdin);
	gets_s(t->name);
	printf("How much is a toy: ");
	t->price = vvod(t->price);
	printf("Children age from: ");
	t->otgoda = vod(t->otgoda);
	printf("Children age before: ");
	t->dogoda = vod(t->dogoda);
	temp->sheet = *t;
}

list* push(toys* t, list **current, list *head)
{
	system("CLS");
	struct list *temp = NULL;
	temp = listallocation(temp);
	inputDATA(temp, t);     // ���������� ���� ������ ������������ ����
	temp->next = nullptr;    // ��������� ���� ��������� �� ��������� ����
	temp->prev = nullptr;    // ��������� ���� ��������� �� ���������� ����
	if (!(*current))
	{
		*current = temp;
		head = *current;
	}
	else
	{
		temp->prev = *current;
		(*current)->next = temp;
		*current = temp;
	}
	return head;
}

list* pop(list **current, list* head)
{
	system("CLS");
	if (!(*current)) printf("������, ��������� ����\n");
	else
	{
		struct list *prev, *next;
		prev = (*current)->prev; // ����, �������������� current
		next = (*current)->next; // ����, ��������� �� current
		if (prev != NULL)
			prev->next = (*current)->next; // ������������ ���������
		if (next != NULL)
			next->prev = (*current)->prev; // ������������ ���������
		free(*current); // ����������� ������ ���������� ��������
		*current = prev;
		return(head);
	}
}

void listprint(list *lst, list **current)
{
	system("CLS");
	struct list *p;
	p = lst;
	if (!(*current)) printf("������, ��������� ����\n");
	else
	{
		printf("Name \t Price \t\t Year\n");
		do
		{
			printf("%s \t %f \t %d-%d\n", p->sheet.name, p->sheet.price, p->sheet.otgoda, p->sheet.dogoda); // ����� �������� �������� p
			p = p->next;     // ������� � ���������� ����
		} while (p != NULL); // ������� ��������� ������
	}
}