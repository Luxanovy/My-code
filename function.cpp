#include "Лаб. раб. 6.h"

float vvod(float i)
{
	int result;                                             //Вызов функции для ввода и проверки числа, 
	do                                                      //Означающего возраст детей для которых предназначена игрушка
	{
		result = scanf_s("%f", &i);
		rewind(stdin);
	} while (result != 1);
	return i;
}

int vod(int i)
{
	int result;
	do
	{
		result = scanf_s("%d", &i);
		rewind(stdin);
	} while (result != 1);
	return i;
}

toys* toysallocation(toys *temp)
{
	temp = (struct toys*)malloc(sizeof(struct toys));
	return temp;
}

list* listallocation(list *temp)
{
	temp = (struct list*)malloc(sizeof(struct list));
	return temp;
}