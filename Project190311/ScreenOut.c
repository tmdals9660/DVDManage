#include "common.h"
#include "cusinfo.h"
#include "dvdInfo.h"

void ShowMenu(void)
{
	system("cls");
	printf("┌────────── 메  뉴 ──────────┐\n");
	printf("│                                                │\n");
	printf("│1. 신규가입             2. 회원조회             │\n");
	printf("│                                                │\n");
	printf("│3. DVD 등록             4. DVD 조회             │\n");
	printf("│                                                │\n");
	printf("│5. DVD 대여             6. DVD 반납             │\n");
	printf("│                                                │\n");
	printf("│7. DVD 대여 이력 조회   8. 전체 DVD 대여 상태   │\n");
	printf("│                                                │\n");
	printf("│                                        9. 종료 │\n");
	printf("└────────────────────────┘\n");
	printf(">> 선택 : ");

}

void ShowCustomerInfo(cusInfo *pCus)
{
	printf("──────────────\n");
	printf("  ID    ∥ %s               \n", pCus->ID);
	printf("  Name  ∥ %s               \n", pCus->name);
	printf("  Phone ∥ %s               \n", pCus->phoneNum);
	printf("──────────────\n");
}

void ShowDVDInfo(dvdInfo *pDVD)
{
	printf("──────────────\n");
	printf(" ISBN  ∥ %s                \n", pDVD->ISBN);
	printf(" title ∥ %s                \n", pDVD->title);
	printf(" Genre ∥ ");
	ShowGenre(pDVD->genre);
	printf(" Statu ∥ ");
	ShowState(pDVD->state);
	printf("──────────────\n");
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
	if (stu == 0) printf("대여 가능\n");
	if (stu == 1) printf("대여 불가\n");
	

}