#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	virtual void showInfo() = 0;//������Ϣ
	virtual string getDeptName() = 0;//��λ����
	int m_id;//ְ�����
	string m_name;//ְ������
	int m_deptid;//���ű��
};
