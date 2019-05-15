#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoSearch.h"

dvdRentInfo I1;
dvdRentInfo I2;


void InforDVD(void)
{
	int sel = 1;

	printf("+++++++++DVD �뿩 �̷� ��ȸ+++++++++\n");
	printf("����������������������������������������������������\n");
	printf("����ȸ�� ����� ������ �ּ���.                    ��\n");
	printf("��                                                ��\n");
	printf("��1. ISBN ������ȸ     2. ��¥/ID�� ���� �󼼰˻� ��\n");
	printf("����������������������������������������������������\n");
	printf(">> ���� : ");
	scanf("%d", &sel);


	if (sel == 1) InforDVDBASIC();
	if (sel == 2) InforDVDDETAIL();
	if (!((sel == 1) || (sel == 2)))
	{
		printf("�߸��� �����Դϴ�. �������� ���ư��ϴ�.");
		Sleep(1500);
	}
}
void InforDVDBASIC(void)
{
	char *pdid;
	char abc;

	printf("��ȸ�� DVD�� ISBN�� �Է��ϼ��� : ");
	scanf("%s", I1.ISBN);
	getchar();

	pdid = getDVDPtrbyISBN(I1.ISBN);


	int i = 0;

	if (pdid == 0)
	{
		printf("����������������������������\n");
		printf("����ϵ��� ���� DVD�Դϴ� ��\n");
		printf("��  DVD��ȸ�� �����մϴ�  ��\n");
		printf("����������������������������\n");
		Sleep(2000);
	}
	else {
		system("cls");
		printf("����������������������������\n");
		printf("��     �뿩 �̷� ��ȸ     ��\n");
		printf("����������������������������\n\n");
		getIDbyISBN(I1.ISBN);
		printf("����ȭ�� >> �ƹ�Ű �Է�......   ");


		scanf("%c", &abc);
		getchar();
	}

}

void InforDVDDETAIL(void)
{
	char *pdetid;
	char abcd;
	char StartDate[DATE_LEN];
	char EndDate[DATE_LEN];

	printf("����������������������������������������\n");
	printf("��ȸ���� ��¥�� �Է��ϼ��� : ");
	scanf("%s", StartDate);
	getchar();

	printf("��ȸ���� ��¥�� �Է��ϼ��� : ");
	scanf("%s", EndDate);
	getchar();

	printf("����������������������������������������\n");

	printf("�� ID�� �Է��� �ּ��� : ");
	scanf("%s", I2.NAME);
	getchar();

	pdetid = getCusPtrbyID(I2.NAME);

	if (pdetid == 0)
	{
		printf("����������������������������\n");
		printf("����ϵ��� ���� ȸ���Դϴ٦�\n");
		printf("��  DVD�뿩�� �����մϴ�  ��\n");
		printf("����������������������������\n");
		Sleep(2000);
	}
	else
	{
		system("cls");
		printf("����������������������������\n");
		printf("��     �뿩 �̷� ��ȸ     ��\n");
		printf("����������������������������\n\n");

		printf("%s�Ϻ��� %s�ϱ���, ID : %s�� ��ȸ���\n", StartDate, EndDate, I2.NAME);
		printf("������������������������������������������\n");


		getISBNbyID(StartDate, EndDate, I2.NAME);


		printf("����ȭ�� >> �ƹ�Ű �Է�......   ");


		scanf("%c", &abcd);
		getchar();
	}
}

void inforDVDTOTAL(void)
{
	char abcde;

	system("cls");

	printf("+++++++++DVD ��ü �뿩 ����+++++++++\n");

	getISBNbyNT3(1);

	printf("����ȭ�� >> �ƹ�Ű �Է�......   ");


	scanf("%c", &abcde);
	getchar();

}