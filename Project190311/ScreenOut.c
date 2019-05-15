#include "common.h"
#include "cusinfo.h"
#include "dvdInfo.h"

void ShowMenu(void)
{
	system("cls");
	printf("���������������������� ��  �� ����������������������\n");
	printf("��                                                ��\n");
	printf("��1. �ű԰���             2. ȸ����ȸ             ��\n");
	printf("��                                                ��\n");
	printf("��3. DVD ���             4. DVD ��ȸ             ��\n");
	printf("��                                                ��\n");
	printf("��5. DVD �뿩             6. DVD �ݳ�             ��\n");
	printf("��                                                ��\n");
	printf("��7. DVD �뿩 �̷� ��ȸ   8. ��ü DVD �뿩 ����   ��\n");
	printf("��                                                ��\n");
	printf("��                                        9. ���� ��\n");
	printf("����������������������������������������������������\n");
	printf(">> ���� : ");

}

void ShowCustomerInfo(cusInfo *pCus)
{
	printf("����������������������������\n");
	printf("  ID    �� %s               \n", pCus->ID);
	printf("  Name  �� %s               \n", pCus->name);
	printf("  Phone �� %s               \n", pCus->phoneNum);
	printf("����������������������������\n");
}

void ShowDVDInfo(dvdInfo *pDVD)
{
	printf("����������������������������\n");
	printf(" ISBN  �� %s                \n", pDVD->ISBN);
	printf(" title �� %s                \n", pDVD->title);
	printf(" Genre �� ");
	ShowGenre(pDVD->genre);
	printf(" Statu �� ");
	ShowState(pDVD->state);
	printf("����������������������������\n");
}

int ShowGenre(int gen)
{
	if (gen == 1) printf("ACTION\n");
	if (gen == 2) printf("COMIC\n");
	if (gen == 3) printf("SF\n");
	if (gen == 4) printf("ROMANTIC\n");

}

int ShowState(int stu)
{
	if (stu == 0) printf("�뿩 ����\n");
	if (stu == 1) printf("�뿩 �Ұ�\n");
	

}