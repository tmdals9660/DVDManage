/*
	기능    : 콜솔출력을 위한 함수들의 선언.
	작성자  : SJY 대리
	작성일  : 2019-03-11
	version : 1.0
*/
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusinfo.h"
#include "dvdInfo.h"

	//기능 : 프로그램을 사용하기 위한 메뉴 출력
	//반환 : void
void ShowMenu(void);

	//기능 : 고객 정보를 출력
	//반환 : void
void ShowCustomerInfo(cusInfo *pCus);



void ShowDVDInfo(dvdInfo *pDVD);


int ShowGenre(int gen);

int ShowState(int stu);



#endif // !__SCREENOUT_H__

