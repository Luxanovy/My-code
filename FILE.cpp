#include "���. ���. 6.h"

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
	puts("������ ����������� �������");
}

void outFILE(FILE *flist)                     //������� ��� ������ ������ �� �����
{
	system("�LS");
	list* fl = nullptr, *flcur = nullptr, *head = NULL;
	head = listallocation(head);
	fopen_s(&flist, "1", "rb+");
	rewind(flist);
	while (!feof(flist))
	{
		fl = listallocation(fl);
		fread(&(fl->sheet), sizeof(toys), 1, flist);
		if (feof(flist)) break;
		fl->next = nullptr;    // ��������� ���� ��������� �� ��������� ����
		fl->prev = nullptr;    // ��������� ���� ��������� �� ���������� ����
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