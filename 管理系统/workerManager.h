#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"Manager.h"
#include<fstream>
#define FILENAME "empFile.txt"
class workermanager
{
public:
	workermanager();
	void Show_Menu();
	void Exitsystem();
	~workermanager();
	int m_EmpNum;//��¼ְ������
	worker** m_EmpArray;//ְ������ָ��
	void Add_Emp();//���ְ��
	void save();//�����ļ�
	bool m_FileIsEmpty;
	int get_Empnum();//ͳ���ļ�������
	void init_Emp();
	void Show_Emp();//��ʾְ��
	void Del_Emp();//ɾ��ְ��
	int IsExist(int id);//�ж�ְ������Ƿ����
	void Mod_Emp();//�޸�ְ��
	void find_Emp();
	void sort_Emp();
	void Clean_file();
}; 