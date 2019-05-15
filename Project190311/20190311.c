#include "common.h"
#include "manager.h"
#include "ScreenOut.h"
#include "dvdInfoAccess.h"

#define TIME_SLIP 30
void print_EXIT(void);

enum {CUS_REGIST = 1,CUS_SEARCH,DVD_REGIST,DVD_SEARCH, RENTAL, TURNIN, INFOM, TOTALS, QUIT};

int main(void)
{
	int inputMenu = 0;
	
	Incus();
	Indvd();
	Inpdvd();

	while (1)
	{
		ShowMenu();
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu)
		{
		case CUS_REGIST:
			RegisterCustomer();
			break;

		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;

		case RENTAL:
			RentalDVD();
			break;

		case TURNIN:
			TurninDVD();
			break;

		case INFOM:
			InforDVD();
			break;

		case TOTALS:
			inforDVDTOTAL();
			break;

		}
		if (inputMenu == QUIT)
		{
			print_EXIT();
			Outcus();
			Outdvd();
			Outpdvd();
			break;
		}
	}

	return 0;
}
void print_EXIT(void) {
	
	system("cls");
	printf("　　　　　　　　　　　　──　　　　　　　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　　　　　　　────　　　　　　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　　　　　　──────　　　　　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　　　　　────────　　　　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　　　　──────────　　　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　　　────────────　　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　  ──────────────　　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　　────────────────　　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　　──────────────────　　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　　────────────────────　　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　　──────────────────────　　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("　────────────────────────　\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	Sleep(TIME_SLIP);
	printf("│                                                │\n");
	Sleep(TIME_SLIP);
	printf("│                                                │\n");
	Sleep(TIME_SLIP);
	printf("│                                                │\n");
	Sleep(TIME_SLIP);
	printf("└　　　　　　　　　　　　　　　　　　　　　　　　┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└─                                            ─┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└──　　　　　　　　　　　　　　　　　　　　──┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└───　　　　　　　　　　　　　　　　　　───┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└────　　　　　　　　　　　　　　　　────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└─────　　　　　　　　　　　　　　─────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└──────　　　　　　　　　　　　──────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└───────　　　　　　　　　　───────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└────────　　　　　　　　────────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└─────────　　　　　　─────────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└──────────　　　　──────────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("│                                                │\n");
	printf("└───────────　　───────────┘\n");
	Sleep(TIME_SLIP);
	system("cls");
	printf("┌────────────────────────┐\n");
	printf("│                                                │\n");
	printf("│            이용해주셔서 감사합니다             │\n");
	printf("│                                                │\n");
	printf("└────────────────────────┘\n");

	
}