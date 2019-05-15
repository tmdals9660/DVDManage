#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoSearch.h"

dvdRentInfo I1;
dvdRentInfo I2;


void InforDVD(void)
{
	int sel = 1;

	printf("+++++++++DVD 대여 이력 조회+++++++++\n");
	printf("┌────────────────────────┐\n");
	printf("│조회할 방식을 선택해 주세요.                    │\n");
	printf("│                                                │\n");
	printf("│1. ISBN 간편조회     2. 날짜/ID를 통한 상세검색 │\n");
	printf("└────────────────────────┘\n");
	printf(">> 선택 : ");
	scanf("%d", &sel);


	if (sel == 1) InforDVDBASIC();
	if (sel == 2) InforDVDDETAIL();
	if (!((sel == 1) || (sel == 2)))
	{
		printf("잘못된 선택입니다. 메인으로 돌아갑니다.");
		Sleep(1500);
	}
}
void InforDVDBASIC(void)
{
	char *pdid;
	char abc;

	printf("조회할 DVD의 ISBN을 입력하세요 : ");
	scanf("%s", I1.ISBN);
	getchar();

	pdid = getDVDPtrbyISBN(I1.ISBN);


	int i = 0;

	if (pdid == 0)
	{
		printf("┌────────────┐\n");
		printf("│등록되지 않은 DVD입니다 │\n");
		printf("│  DVD조회를 종료합니다  │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}
	else {
		system("cls");
		printf("┌────────────┐\n");
		printf("│     대여 이력 조회     │\n");
		printf("└────────────┘\n\n");
		getIDbyISBN(I1.ISBN);
		printf("메인화면 >> 아무키 입력......   ");


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

	printf("────────────────────\n");
	printf("조회시작 날짜를 입력하세요 : ");
	scanf("%s", StartDate);
	getchar();

	printf("조회종료 날짜를 입력하세요 : ");
	scanf("%s", EndDate);
	getchar();

	printf("────────────────────\n");

	printf("고객 ID를 입력해 주세요 : ");
	scanf("%s", I2.NAME);
	getchar();

	pdetid = getCusPtrbyID(I2.NAME);

	if (pdetid == 0)
	{
		printf("┌────────────┐\n");
		printf("│등록되지 않은 회원입니다│\n");
		printf("│  DVD대여를 종료합니다  │\n");
		printf("└────────────┘\n");
		Sleep(2000);
	}
	else
	{
		system("cls");
		printf("┌────────────┐\n");
		printf("│     대여 이력 조회     │\n");
		printf("└────────────┘\n\n");

		printf("%s일부터 %s일까지, ID : %s의 조회결과\n", StartDate, EndDate, I2.NAME);
		printf("─────────────────────\n");


		getISBNbyID(StartDate, EndDate, I2.NAME);


		printf("메인화면 >> 아무키 입력......   ");


		scanf("%c", &abcd);
		getchar();
	}
}

void inforDVDTOTAL(void)
{
	char abcde;

	system("cls");

	printf("+++++++++DVD 전체 대여 상태+++++++++\n");

	getISBNbyNT3(1);

	printf("메인화면 >> 아무키 입력......   ");


	scanf("%c", &abcde);
	getchar();

}