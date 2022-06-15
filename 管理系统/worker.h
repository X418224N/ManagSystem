#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	virtual void showInfo() = 0;//个人信息
	virtual string getDeptName() = 0;//岗位名称
	int m_id;//职工编号
	string m_name;//职工姓名
	int m_deptid;//部门编号
};
