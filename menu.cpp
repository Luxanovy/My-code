#include "���. ���. 6.h"

void poisk(toys* t, list* lst)       //������� ��� ������ � ������ �������� �������, ������� �������� �� ���� ���������������
{
	int pi = 0, age = 0, k = 0, j = 0;                        //���������� ������
	float sum = 0;
	printf("\n");
	printf("money: ");
	sum = vvod(sum);                                          //���� ����� �����
	printf("The book is suitable for children with age: ");
	age = vod(age);                                           //����� ������� ��� ����� � �������� �����, 	
															  //����������� ������� ����� ��� ������� ������������� �������                    
	list *p = lst, *show = NULL, *current, *head = NULL;
	show = listallocation(show);
	head = listallocation(head);
	current = nullptr;

	printf("Suitable toys: ");
	do
	{
		if (p->sheet.price <= sum)
		{
			if (p->sheet.otgoda <= age && p->sheet.dogoda >= age)
			{
				head = push1(p, &current, head);
			}
			p = p->next;
		}
		else p = p->next;
	} while (p);

	listprint(head, &current);
}

list* push1(list *h, list **current, list *head)
{
	system("CLS");
	struct list *temp = NULL;
	temp = listallocation(temp);
	temp->sheet = h->sheet;   // ���������� ���� ������ ������������ ����
	temp->next = nullptr;     // ��������� ���� ��������� �� ��������� ����
	temp->prev = nullptr;     // ��������� ���� ��������� �� ���������� ����
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

void menu(toys* toy, list* head, FILE *flist)                                 //������� ��� ������ � ���� ���������
{
	list *current = nullptr;
	char choice;
	while (1)
	{
		puts("\n��� ��������");
		puts("1-�������� �������(����)");
		puts("2-������� �������(����)");
		puts("3-����������� ������ �������(����)");
		puts("4-��������� ������");
		puts("5-����� ���� ��������");
		puts("6-�������� � ����");
		puts("7-������� � ����� � ����");
		puts("0-��������");
		choice = getchar();
		rewind(stdin);
		switch (choice)
		{
		case'1': head = push(toy, &current, head); break;
		case'2': head = pop(&current, head); break;
		case'3': listprint(head, &current); break;
		case'4': poisk(toy, head); break;
		case'5': head = sort(head, &current); break;
		case'6': InFILE(flist, head); break;
		case'7': outFILE(flist); break;
		case'0': return;
		default: system("CLS");  printf("������, ��������� ����\n");
		}
	}
}