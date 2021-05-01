/*
Purpose: 製作出一個商場，
		 可以選擇並管理服飾店，
		 服飾店內可以新增衣服、
		 顯示所有衣服、
		 返回商場。
Author:
	Class: 資工二
	ID: 107590046
	Name:彭建豪
Homework number: HW8
Date:2019/11/12
*/
#include "MallUI.h"
#include "Mall.h"
using namespace std;

int main()
{
	Mall mall;
	MallUI UI;
	UI.start(mall);
	system("PAUSE");
	return 0;
}