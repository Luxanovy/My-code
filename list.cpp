#include "Лаб. раб. 6.h"

void inputDATA(list* temp, toys* t)                //Функция для записи массива структур в бинарный файл
{
	printf("\nName toys: ");                            //Ввод данных в поля структуры
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
	inputDATA(temp, t);     // сохранение поля данных добавляемого узла
	temp->next = nullptr;    // созданный узел указывает на следующий узел
	temp->prev = nullptr;    // созданный узел указывает на предыдущий узел
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
	if (!(*current)) printf("Ошибка, повторите ввод\n");
	else
	{
		struct list *prev, *next;
		prev = (*current)->prev; // узел, предшествующий current
		next = (*current)->next; // узел, следующий за current
		if (prev != NULL)
			prev->next = (*current)->next; // переставляем указатель
		if (next != NULL)
			next->prev = (*current)->prev; // переставляем указатель
		free(*current); // освобождаем память удаляемого элемента
		*current = prev;
		return(head);
	}
}

void listprint(list *lst, list **current)
{
	system("CLS");
	struct list *p;
	p = lst;
	if (!(*current)) printf("Ошибка, повторите ввод\n");
	else
	{
		printf("Name \t Price \t\t Year\n");
		do
		{
			printf("%s \t %f \t %d-%d\n", p->sheet.name, p->sheet.price, p->sheet.otgoda, p->sheet.dogoda); // вывод значения элемента p
			p = p->next;     // переход к следующему узлу
		} while (p != NULL); // условие окончания обхода
	}
}