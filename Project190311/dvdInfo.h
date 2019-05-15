/*
	기능    : DVD 관리 구조체
	작성자  : SJY 대리
	작성일  : 2019-03-11
	version : 1.0
*/

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN 30
#define TITLE_LEN 30
#define DATE_LEN 30

//도서 장르 정보
enum {ACTION = 1, COMIC, SF, ROMANTIC};

typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre; // 도서장르 멤버변수
	int state;

}dvdInfo;

typedef struct __dvdRentInfo
{
	char ISBN[ISBN_LEN];
	char NAME[TITLE_LEN];
	char date[DATE_LEN];

}dvdRentInfo;

#endif // !__DVDINFO_H__