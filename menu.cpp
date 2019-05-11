#include "Лаб. раб. 6.h"

void poisk(toys* t, list* lst)       //Функция для поиска и вывода названия игрушек, которые подходят по всем характеристикам
{
	int pi = 0, age = 0, k = 0, j = 0;                        //Объявление данных
	float sum = 0;
	printf("\n");
	printf("money: ");
	sum = vvod(sum);                                          //Ввод суммы денег
	printf("The book is suitable for children with age: ");
	age = vod(age);                                           //Вызов функции для ввода и проверки числа, 	
															  //означающего возраст детей для которых предназначена игрушка                    
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
	temp->sheet = h->sheet;   // сохранение поля данных добавляемого узла
	temp->next = nullptr;     // созданный узел указывает на следующий узел
	temp->prev = nullptr;     // созданный узел указывает на предыдущий узел
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

void menu(toys* toy, list* head, FILE *flist)                                 //Функция для работы с меню программы
{
	list *current = nullptr;
	char choice;
	while (1)
	{
		puts("\nВид операции");
		puts("1-добавить игрушку(узел)");
		puts("2-удалить игрушку(узел)");
		puts("3-просмотреть список игрушек(лист)");
		puts("4-выполнить задачу");
		puts("5-найти макс значение");
		puts("6-Записать в файл");
		puts("7-считать с файла в лист");
		puts("0-окончить");
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
		default: system("CLS");  printf("Ошибка, повторите ввод\n");
		}
	}
}