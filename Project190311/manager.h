/*
	기능    : 업무 처리 함수들의 선언.
	작성자  : SJY 대리
	작성일  : 2019-03-11
	version : 1.0
*/
#ifndef __MGR_H__
#define __MGR_H__


//기능 : 신규 회원 가입
//반환 : void
void RegisterCustomer(void);

//기능 : ID를 통한 회원 검색
//반환 : void
void SearchCusInfo(void);

//기능 : 신규 DVD 등록
//반환 : void
void RegistDVD(void);

//기능 : DVD 검색
//반환 : void
void SearchDVDInfo(void);


void TurninDVD(void);

void InforDVD(void);

#endif // !__MANAGER_H__
