#include "Лаб. раб. 6.h"

list* sort(list *head, list **current)
{
	list *count1, *count2, *count3;
	int i = 0;
	for (count2 = *current; count2; count2 = count2->prev)
		for (count1 = head; count1->next; count1 = count1->next)
			if (count1->sheet.price > count1->next->sheet.price)
			{
				count3 = count1->next;
				if (!count1->prev)
					head = count1->next;
				count1->next = count1->next->next;
				if (count1->next)
					count1->next->prev = count1;
				else
				{
					*current = count1;
					count2 = *current;
				}
				count3->prev = count1->prev;
				count3->next = count1;
				if (count3->prev)
					count3->prev->next = count3;
				count1->prev = count3;
				count1 = count1->prev;
			}
	max_price(current, head);                                                //Функция для поиска игрушки с максимальной ценой и вывод результата
	return head;
}


void max_price(list **current, list *head)
{
	system("CLS");
	list *show = NULL, *showcur = nullptr, *showhead = NULL;
	
	showhead = listallocation(showhead);

	puts("Игрушка с максимальной ценой\n");
	do 
	{
		if ((*current)->sheet.price == head->sheet.price)
		{
			show = listallocation(show);
			show->sheet = head->sheet;
			show->next = nullptr;    // созданный узел указывает на следующий узел
			show->prev = nullptr;    // созданный узел указывает на предыдущий узел
			if (!showcur)
			{
				showcur = show;
				showhead = showcur;
			}
			else
			{
				show->prev = showcur;
				showcur->next = show;
				showcur = show;
			}
		}
		head = head->next;
	} while (head);
	listprint(showhead, &showcur);
}