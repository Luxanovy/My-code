#include "Лаб. раб. 6.h"

void InFILE(FILE *&flist, list *head)
{
	system("CLS");
	fopen_s(&flist, "1", "wb+");
	while (head)
	{
		fwrite(&(head->sheet), 1, sizeof(toys), flist);
		head = head->next;
	}
	fclose(flist);
	puts("Запись произведена успешно");
}

void outFILE(FILE *flist)                     //Функция для чтения данных из файла
{
	system("СLS");
	list* fl = nullptr, *flcur = nullptr, *head = NULL;
	head = listallocation(head);
	fopen_s(&flist, "1", "rb+");
	rewind(flist);
	while (!feof(flist))
	{
		fl = listallocation(fl);
		fread(&(fl->sheet), sizeof(toys), 1, flist);
		if (feof(flist)) break;
		fl->next = nullptr;    // созданный узел указывает на следующий узел
		fl->prev = nullptr;    // созданный узел указывает на предыдущий узел
		if (!flcur)
		{
			flcur = fl;
			head = flcur;
		}
		else
		{
			fl->prev = flcur;
			flcur->next = fl;
			flcur = fl;
		}
	}
	listprint(head, &flcur);
	fclose(flist);
}