/*
	���    : �� ���� ���� �� ���� �Լ����� ����.
	�ۼ���  : SJY �븮
	�ۼ���  : 2019-03-11
	version : 1.0
*/
#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"


//��� : dvdInfo �Ҵ� �� ����
//��ȯ : ���� �� ��ϵ� ������ ����, ���н� 0�� ��ȯ.
int AddDVDInfo(char *ISBN, char *title, int genre, int state);

//��� : �ش� ISBN�� ������ ������ �ִ� ������ �����͸� ��ȯ
//��ȯ : ��� �ȵ� ISBN�� ��� NULL ������ ��ȯ.
dvdInfo *getDVDPtrbyISBN(char *ISBN);

dvdInfo *getIDbyISBN(char *ISBN);

dvdInfo *getISBNbyID(char *date1, char *date2, char *NAME);

dvdInfo *getISBNbyNT(int aa);

dvdInfo *getISBNbyNT2(int aa);

dvdInfo *getISBNbyNT3(int aa);

//��� : �����ϴ� ISBN���� üũ
//��ȯ : �����ϴ� ISBN�̸� 1, �ƴϸ� 0�� ��ȯ.
int IsregistISBN(char *ISBN);

void RentalDVD(void);

void RegistRentDVD(char *ISBN, char *NAME, char *date);


#endif // __DVDACCESS_H__

