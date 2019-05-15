/*
	기능    : 고객 정보 저장 및 참조 함수들의 선언.
	작성자  : SJY 대리
	작성일  : 2019-03-11
	version : 1.0
*/
#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"


//기능 : dvdInfo 할당 및 저장
//반환 : 성공 시 등록된 정보의 개수, 실패시 0을 반환.
int AddDVDInfo(char *ISBN, char *title, int genre, int state);

//기능 : 해당 ISBN의 정보를 가지고 있는 변수의 포인터를 반환
//반환 : 등록 안된 ISBN의 경우 NULL 포인터 반환.
dvdInfo *getDVDPtrbyISBN(char *ISBN);

dvdInfo *getIDbyISBN(char *ISBN);

dvdInfo *getISBNbyID(char *date1, char *date2, char *NAME);

dvdInfo *getISBNbyNT(int aa);

dvdInfo *getISBNbyNT2(int aa);

dvdInfo *getISBNbyNT3(int aa);

//기능 : 존재하는 ISBN인지 체크
//반환 : 존재하는 ISBN이면 1, 아니면 0을 반환.
int IsregistISBN(char *ISBN);

void RentalDVD(void);

void RegistRentDVD(char *ISBN, char *NAME, char *date);


#endif // __DVDACCESS_H__

