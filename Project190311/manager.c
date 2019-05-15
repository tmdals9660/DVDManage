#include "common.h"
#include "cusinfo.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"


cusInfo S1;
dvdInfo D1;

void RegisterCustomer(void)
{
	int rt = 0;


	printf("+++++++++�ű� ����+++++++++\n");
	printf("ID    : ");
	scanf("%s", S1.ID);
	getchar();
	printf("Name  : ");
	scanf("%s", S1.name);
	getchar();
	printf("Phone : ");
	scanf("%s", S1.phoneNum);
	getchar();

	rt = AddCusInfo(S1.ID, S1.name, S1.phoneNum);

	if (rt == 0) {
		printf("����������������������������\n");
		printf("��       ��Ͻ���!!!      ��\n");
		printf("����������������������������\n");
		Sleep(1500);

	}
	else
	{
		Outcus();
		printf("����������������������������\n");
		printf("�� ����� �Ϸ�Ǿ����ϴ�. ��\n");
		printf("��   %d���� ȸ������ ���  ��\n", rt);
		printf("����������������������������\n");
		Sleep(2000);
	}


}

void SearchCusInfo(void)
{
	char *pds;
	char S2[ID_LEN];
	char ab2;

	system("cls");
	printf("+++++++++ȸ�� �˻�+++++++++\n");
	getIDbyNT(1);

	printf("ID : ");
	scanf("%s", S2);
	getchar();

	pds = getCusPtrbyID(S2);

	if (pds == 0)
	{
		printf("����������������������������\n");
		printf("����ϵ��� ���� ȸ���Դϴ٦�\n");
		printf("����������������������������\n");
		Sleep(2000);
	}
	else
	{
		ShowCustomerInfo(pds);
		printf("����ȭ�� >> �ƹ�Ű �Է�......   ");
		scanf("%c", &ab2);
		getchar();
	}

}

void RegistDVD(void)
{
	int rt2 = 0;


	printf("+++++++++DVD ���+++++++++\n");
	printf("ISBN    : ");
	scanf("%s", D1.ISBN);
	getchar();
	printf("title   : ");
	scanf("%s", D1.title);
	getchar();
	printf("����������������������������\n");
	printf("��1. ACTION    2. COMIC   ��\n");
	printf("��3. SF        4. ROMANTIC��\n");
	printf("����������������������������\n");
	printf("Genre   : ");
	scanf("%d", &D1.genre);
	getchar();

	if ((D1.genre > 4) || (D1.genre < 1)) rt2 == 0;
	else rt2 = AddDVDInfo(D1.ISBN, D1.title, D1.genre, 0);

	if (rt2 == 0) {
		printf("����������������������������\n");
		printf("��       ��Ͻ���!!!      ��\n");
		printf("����������������������������\n");
		Sleep(1500);

	}
	else
	{
		Outdvd();
		printf("����������������������������\n");
		printf("�� ����� �Ϸ�Ǿ����ϴ�. ��\n");
		printf("��      %d���� DVD ���    ��\n", rt2);
		printf("����������������������������\n");
		Sleep(2000);
	}


}

void SearchDVDInfo(void)
{
	char *pdd;
	char D2[ISBN_LEN];
	char ab;

	system("cls");
	printf("+++++++++DVD �˻�+++++++++\n");
	getISBNbyNT2(1);
	printf("ISBN : ");
	scanf("%s", D2);
	getchar();

	pdd = getDVDPtrbyISBN(D2);

	if (pdd == 0) {
		printf("����������������������������\n");
		printf("����ϵ��� ���� DVD�Դϴ� ��\n");
		printf("����������������������������\n");
		Sleep(2000);
	}
	else
	{
		ShowDVDInfo(pdd);

		printf("����ȭ�� >> �ƹ�Ű �Է�......   ");


		scanf("%c", &ab);
		getchar();
	}


}

