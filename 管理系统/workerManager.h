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
	int m_EmpNum;//记录职工人数
	worker** m_EmpArray;//职工数组指针
	void Add_Emp();//添加职工
	void save();//保存文件
	bool m_FileIsEmpty;
	int get_Empnum();//统计文件中人数
	void init_Emp();
	void Show_Emp();//显示职工
	void Del_Emp();//删除职工
	int IsExist(int id);//判断职工编号是否存在
	void Mod_Emp();//修改职工
	void find_Emp();
	void sort_Emp();
	void Clean_file();
}; 