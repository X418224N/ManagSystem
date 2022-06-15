#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class employee:public worker
{
public:
	employee(int id, string name, int did);
	virtual void showInfo();//显示个人信息
	virtual string getDeptName();// 显示职工岗位
};