#include "common.h"
#include "dvdInfo.h"
#include "cusinfo.h"
#include "dvdInfoAccess.h"


int count2 = 0;
int size2 = 5;

int count3 = 0;
int size3 = 5;


dvdInfo *pd;
dvdRentInfo *pdvd;
dvdRentInfo R1;
dvdRentInfo T1;

void Indvd()
{
	char dISBN[30];
	char dTITLE[30];
	int dgenre = 0;
	int dstate = 0;
	int res;

	FILE *fp = fopen("dvddata.txt", "rt");



	if (fp == NULL)
	{
		printf("┌──────────────────┐\n");
		printf("│   기등록 된 DVD데이터가 없습니다.  │\n");
		printf("└──────────────────┘\n");
		Sleep(1000);
	}
	else
	{
		printf("┌────────────────────┐\n");
		printf("│   기등록 된 DVD 데이터 불러오는중...   │\n");
		printf("└────────────────────┘\n");
		Sleep(1000);

		
		while (1)
		{
			res = fscanf(fp, "%s %s %d %d", dISBN, dTITLE, &dgenre, &dstate);
			if (res == EOF) break;
			AddDVDInfo(dISBN, dTITLE, dgenre, dstate);
			
		}
		fclose(fp);
	}
}

void Outdvd()
{
	if (pd != NULL)
	{
		FILE *fp = fopen("dvddata.txt", "wt");
		int i = 0;

		while (i<count2)
		{
			fprintf(fp, "%s %s %d %d\n", (pd + i)->ISBN, (pd + i)->title, (pd + i)->genre, (pd + i)->state);
			i++;
		}
		fclose(fp);
	}
}
void Inpdvd()
{
	char dISBN[30];
	char dNAME[30];
	char dDATE[30];

	int res = 0;

	FILE *fp = fopen("dvdinfodata.txt", "rt");



	if (fp == NULL)
	{
		printf("┌──────────────────┐\n");
		printf("│기등록 된 DVD이력 데이터가 없습니다.│\n");
		printf("└──────────────────┘\n");
		Sleep(1000);
	}
	else
	{
		printf("┌────────────────────┐\n");
		printf("│ 기등록 된 DVD이력 데이터 불러오는중... │\n");
		printf("└────────────────────┘\n");
		Sleep(1000);

		while (1)
		{
			res = fscanf(fp, "%s %s %s", dISBN, dNAME, dDATE);
			if (res == EOF) break;
			RegistRentDVD(dISBN, dNAME, dDATE);
			
		}
		fclose(fp);
	
	}
}
void Outpdvd()
{
	if (pdvd != NULL) {
		FILE *fp = fopen("dvdinfodata.txt", "wt");
		int i = 0;

		while (i < count3)
		{
			fprintf(fp, "%s %s %s\n", (pdvd + i)->ISBN, (pdvd + i)->NAME, (pdvd + i)->date);
			i++;
		}
		fclose(fp);
	}

}


//기능 : cusInfo 할당 및 저장
//반환 : 성공 시 등록된 정보의 개수, 실패시 0을 반환.
int AddDVDInfo(char *ISBN, char *title, int genre, int state)
{

	if (count2 == 0) pd = (dvdInfo *)malloc(size2 * sizeof(dvdInfo));

	if (IsregistISBN(ISBN) == 1) return 0;
	else
	{

		strcpy(pd[count2].ISBN, ISBN);
		strcpy(pd[count2].title, title);
		pd[count2].genre =  genre;
		pd[count2].state = state;

		count2 += 1;
		if (count2 >= size2)
		{
			size2 += 5;
			pd = (dvdInfo *)realloc(pd, size2 * sizeof(dvdInfo));
		}

		return count2;
	}
	free(pd);
}

//기능 : 해당 고객 ID의 정보를 가지고 있는 포인터를 반환
//반환 : 등록 안된 ID의 경우 NULL 포인터 반환.
dvdInfo *getDVDPtrbyISBN(char *ISBN)
{
	int i = 0;
	if (IsregistISBN(ISBN) == 0) return 0;
	

	for (i = 0; i < size2; i++) {

		if (strcmp(ISBN, (pd + i)->ISBN) == 0)
		{
			return &pd[i];			
		}
			
	}
	
}
dvdInfo *getIDbyISBN(char *ISBN)
{
	char *pdic;

	int i = 0;
	if (IsregistISBN(ISBN) == 0) return 0;

	for (i = 0; i < size3; i++) {

		if (strcmp(ISBN, (pdvd + i)->ISBN) == 0)
		{
			pdic = getCusPtrbyID((pdvd+i)->NAME);
			ShowCustomerInfo(pdic);
			printf("대여 날짜 : %s\n", &pdvd[i].date);
			printf("──────────────\n\n");
		}
	}
}



dvdInfo *getISBNbyID(char *date1, char *date2, char *NAME)
{
	int i = 0;
	
	for (i = 0; i < size3; i++) {
		if ((strcmp((pdvd + i)->date, date1) == 1 || strcmp((pdvd + i)->date, date1) == 0)
			&& (strcmp((pdvd + i)->date, date2) == -1 || strcmp((pdvd + i)->date, date2) == 0))
		{
		if (strcmp(NAME, (pdvd + i)->NAME) == 0)
		{
			printf("──────────────\n");
			printf("DVD ISBN  : %s\n", &pdvd[i].ISBN);
			printf("대여 날짜 : %s\n", &pdvd[i].date);
			printf("──────────────\n\n");
		}
	}
	}
}

dvdInfo *getISBNbyNT(int aa)
{
	char *pdvdall;

	int i = 0;
	
	for (i = 0; i < count2; i++) 
	{
		if (aa == 1) {
			pdvdall = getDVDPtrbyISBN((pd + i)->ISBN);
			ShowDVDInfo(pdvdall);
		}
	}
}
dvdInfo *getISBNbyNT2(int aa)
{
	int i = 0;
	printf("──────────────\n");
	for (i = 0; i < count2; i++)
	{
		if (aa == 1) {

			printf("DVD ISBN  : %s\n", &pd[i].ISBN);

		}
	}
	printf("──────────────\n\n");
}
dvdInfo *getISBNbyNT3(int aa)
{
	char *pdvd1;

	int i = 0;
	int j = 0;
    int k = 0;

	for (i = 0; i < count2; i++)
	{
		if (aa == 1) {

			if (pd[i].state == 0)
			{
			printf("──────────────\n");
			printf(" ISBN  ∥ %s                \n", &pd[i].ISBN);
			printf(" title ∥ %s                \n", &pd[i].title);
			printf(" Genre ∥ ");
			ShowGenre(pd[i].genre);
			printf(" Statu ∥ ");
			ShowState(pd[i].state);
			printf("──────────────\n");
			}
			if (pd[i].state == 1) 
			{
				printf("──────────────\n");
				printf(" ISBN  ∥ %s                \n", &pd[i].ISBN);
				printf(" title ∥ %s                \n", &pd[i].title);
				printf(" Genre ∥ ");
				ShowGenre(pd[i].genre);
				printf(" Statu ∥ ");
				ShowState(pd[i].state);

				for (j = 0; j <= count3; j++)
				{
					if (strcmp(pd[i].ISBN , pdvd[j].ISBN) == 0) 
					{
						k = j;						
					}
				}
				printf(" ID    ∥ %s\n", &pdvd[k].NAME);
				printf(" Date  ∥ %s\n", &pdvd[k].date);
				printf("──────────────\n");
			}

		}
	}
}


//기능 : 가입된 ID인지 체크
//반환 : 가입된 ID이면 1, 아니면 0을 반환.
int IsregistISBN(char *ISBN)
{
	int i = 0;

	for (i = 0; i < size2; i++) {

		if (strcmp(ISBN, (pd + i)->ISBN) == 0) return 1;

	}
	return 0;

}


void RentalDVD(void)
{
	char *pdr;
	char *pdrs;

	system("cls");
	printf("+++++++++DVD 대여+++++++++\n");
	getISBNbyNT(1);
	printf("대여할 DVD의 ISBN을 입력하세요 : ");
	scanf("%s", R1.ISBN);

	pdr = getDVDPtrbyISBN(R1.ISBN);
	int num = 0;
	int i = 0;

	for (i = 0; i < size2; i++) {

		if (strcmp(R1.ISBN, (pd + i)->ISBN) == 0) num = i;

	}

	
	
	if (pdr == 0) 
	{
		printf("┌────────────┐\n");
		printf("│등록되지 않은 DVD입니다 │\n");
		printf("│  DVD대여를 종료합니다  │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}
	else if (pd[num].state == 1)
	{
		printf("┌────────────┐\n");
		printf("│   대여중인 DVD입니다   │\n");
		printf("│  DVD대여를 종료합니다  │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}
	
	if (!(pdr == 0) && (pd[num].state == 0))
	{
		printf("┌────────────┐\n");
		printf("│ 대여 가능한 DVD입니다  │\n");
		printf("└────────────┘\n");

		printf("대여자 ID를 입력해 주세요 : ");
		scanf("%s", R1.NAME);

		pdrs = getCusPtrbyID(R1.NAME);

		if (pdrs == 0)
		{
			printf("┌────────────┐\n");
			printf("│등록되지 않은 회원입니다│\n");
			printf("│  DVD대여를 종료합니다  │\n");
			printf("└────────────┘\n");
			Sleep(2000);
		}
		else
		{
			printf("┌────────────┐\n");
			printf("│ 대여 가능한 회원입니다 │\n");
			printf("└────────────┘\n");
			printf("대여 날짜를 입력해 주세요 : ");
			scanf("%s", R1.date);

			RegistRentDVD(R1.ISBN, R1.NAME, R1.date);
			pd[num].state = 1;
			Outpdvd();
			printf("┌────────────┐\n");
			printf("│ 대여가 완료되었습니다. │\n");
			printf("└────────────┘\n");
			Sleep(2000);
		}

	}

}

void RegistRentDVD(char *ISBN, char *NAME, char *date)
{
	if (count3 == 0) pdvd = (dvdRentInfo *)malloc(size3 * sizeof(dvdRentInfo));

		strcpy(pdvd[count3].ISBN, ISBN);
		strcpy(pdvd[count3].NAME, NAME);
		strcpy(pdvd[count3].date, date);

		count3 += 1;
		if (count3 >= size3)
		{
			size3 += 5;
			pdvd = (dvdRentInfo *)realloc(pdvd, size3 * sizeof(dvdRentInfo));
		}
		return count3;
		
	free(pdvd);
}
void TurninDVD(void)
{

	char *pdt;

	printf("+++++++++DVD 반납+++++++++\n");
	printf("반납할 DVD의 ISBN을 입력하세요 : ");
	scanf("%s", T1.ISBN);

	pdt = getDVDPtrbyISBN(T1.ISBN);

	int num = 0;
	int i = 0;

	for (i = 0; i < size2; i++) {

		if (strcmp(T1.ISBN, (pd + i)->ISBN) == 0) num = i;

	}

	
	if (pdt == 0)
	{
		printf("┌────────────┐\n");
		printf("│등록되지 않은 DVD입니다 │\n");
		printf("│  DVD반납을 종료합니다  │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}
	else if (pd[num].state == 0)
	{
		printf("┌────────────┐\n");
		printf("│대여중인 DVD가 아닙니다 │\n");
		printf("│  DVD반납을 종료합니다  │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}

	if ((pd[num].state == 1) && !(pdt == 0))
	{
		pd[num].state = 0;
		printf("┌────────────┐\n");
		printf("│ 반납이 완료되었습니다. │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}
}

