/*
	���    : �� ���� ����ü
	�ۼ���  : SJY �븮
	�ۼ���  : 2019-03-11
	version : 1.0
*/

#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN 10
#define NAME_LEN 30
#define PHONE_LEN 30



typedef struct __cusInfo
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
}cusInfo;

#endif // !__CUSINFO_H__