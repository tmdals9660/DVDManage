/*
	���    : �� ���� ���� �� ���� �Լ����� ����.
	�ۼ���  : SJY �븮
	�ۼ���  : 2019-03-11
	version : 1.0
*/
#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusinfo.h"


	//��� : cusInfo �Ҵ� �� ����
	//��ȯ : ���� �� ��ϵ� ������ ����, ���н� 0�� ��ȯ.
int AddCusInfo(char *ID, char *name, char *phoneNum);

	//��� : �ش� �� ID�� ������ ������ �ִ� �����͸� ��ȯ
	//��ȯ : ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
cusInfo *getCusPtrbyID(char *ID);


cusInfo *getIDbyNT(int aa);

	//��� : ���Ե� ID���� üũ
	//��ȯ : ���Ե� ID�̸� 1, �ƴϸ� 0�� ��ȯ.
int IsregistID(char *ID);

#endif // __CUSACCESS_H__

