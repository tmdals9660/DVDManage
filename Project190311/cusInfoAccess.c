#include "common.h"
#include "cusinfo.h"

int count = 0;
int size = 5;
cusInfo *ps;
//기능 : cusInfo 할당 및 저장
//반환 : 성공 시 등록된 정보의 개수, 실패시 0을 반환.

void Incus()
{
	char dID[30];
	char dNAME[30];
	char dPHONE[30];

	int res = 0;

	FILE *fp = fopen("cusdata.txt", "rt");

	if (fp == NULL)
	{
		printf("┌──────────────────┐\n");
		printf("│  기등록 된 회원데이터가 없습니다.  │\n");
		printf("└──────────────────┘\n");
		Sleep(1000);
	}
	else
	{
		printf("┌────────────────────┐\n");
		printf("│   기등록 된 회원데이터 불러오는중...   │\n");
		printf("└────────────────────┘\n");
		Sleep(1000);

		while (1)
		{
			res = fscanf(fp, "%s %s %s", dID, dNAME, dPHONE);
			if (res == EOF) break;
			AddCusInfo(dID, dNAME, dPHONE);
		
		}
		fclose(fp);
	}
}
void Outcus()
{
	if (ps != NULL) {
		FILE *fp = fopen("cusdata.txt", "wt");
		int i = 0;
		while (i < count)
		{
			fprintf(fp, "%s %s %s\n", (ps + i)->ID, (ps + i)->name, (ps + i)->phoneNum);
			i++;
		}
		fclose(fp);
	}
}

int AddCusInfo(char *ID, char *name, char *phoneNum)
{

	if (count == 0) ps = (cusInfo *)malloc(size * sizeof(cusInfo));

	if (IsregistID(ID) == 1) return 0;
	else
	{

	strcpy(ps[count].ID, ID);
	strcpy(ps[count].name, name);
	strcpy(ps[count].phoneNum, phoneNum);


	count += 1;
	if (count >= size)
	{
		size += 5;
		ps = (cusInfo *)realloc(ps, size * sizeof(cusInfo));
	}

	return count;
	}
	free(ps);
}

//기능 : 해당 고객 ID의 정보를 가지고 있는 포인터를 반환
//반환 : 등록 안된 ID의 경우 NULL 포인터 반환.
cusInfo *getCusPtrbyID(char *ID)
{
	int i = 0;
	if (IsregistID(ID) == 0) return 0;

	for (i = 0; i < size; i++) {

		if (strcmp(ID, (ps + i)->ID) == 0)
		{
			return &ps[i];
			
		}
	}
}
cusInfo *getIDbyNT(int aa)
{
	char *pscdall;

	int i = 0;
	printf("──────────────\n");
	for (i = 0; i < count; i++)
	{
		if (aa == 1) {
			pscdall = getCusPtrbyID((ps + i)->ID);
		
			printf("회원 ID   : %s\n", &ps[i].ID);
			
		}
	}
	printf("──────────────\n\n");
}

//기능 : 가입된 ID인지 체크
//반환 : 가입된 ID이면 1, 아니면 0을 반환.
int IsregistID(char *ID)
{	
	int i = 0;

	for (i = 0; i < size; i++) {

		if (strcmp(ID, (ps + i)->ID) == 0) return 1;
		
	}
	return 0;

}
