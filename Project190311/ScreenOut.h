/*
	���    : �ݼ������ ���� �Լ����� ����.
	�ۼ���  : SJY �븮
	�ۼ���  : 2019-03-11
	version : 1.0
*/
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusinfo.h"
#include "dvdInfo.h"

	//��� : ���α׷��� ����ϱ� ���� �޴� ���
	//��ȯ : void
void ShowMenu(void);

	//��� : �� ������ ���
	//��ȯ : void
void ShowCustomerInfo(cusInfo *pCus);



void ShowDVDInfo(dvdInfo *pDVD);


int ShowGenre(int gen);

int ShowState(int stu);



#endif // !__SCREENOUT_H__

