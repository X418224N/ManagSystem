#include"workerManager.h"
workermanager::workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
	int num = this->get_Empnum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new worker * [this->m_EmpNum];//开辟空间
	this->init_Emp();//将文件中数据存到数组中
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << this->m_EmpArray[i]->m_id << endl;
	//	cout << this->m_EmpArray[i]->m_name << endl;
	//	cout << this->m_EmpArray[i]->m_deptid<< endl;
	//}
}
void workermanager::Show_Menu()
{
	cout << "0.退出程序" << endl;
	cout << "1.增加员工信息" << endl;
	cout << "2.显示员工信息" << endl;
	cout << "3.删除离职员工" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.查找职工信息" << endl;
	cout << "6.编号排序" << endl;
	cout << "7.清空文档" << endl;
}
void workermanager::Exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workermanager::Add_Emp()//添加职工
{
	cout << "请输入添加职工数量" << endl;
	int addnum = 0;
	cin >> addnum;//保存用户输入数量
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;//新空间人数=原来记录人数+新增人数
		worker ** newSpace =new worker* [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
				while (true)
				{
					cin >> id;
					int ret = IsExist(id);
					if (ret != -1)
					{
						cout << "编号重复" << endl;
					}
					else
					{
						break;
					}
			}
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择职工岗位" << endl;
			cout << "1,普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;//释放原有空间
		this->m_EmpArray = newSpace;//更新新空间指向
		this->m_EmpNum = newSize;//更新职工人数
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addnum << "名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
void workermanager::save()//保存文件
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << endl;
		ofs << this->m_EmpArray[i]->m_name << endl;
		ofs << this->m_EmpArray[i]->m_deptid << endl;
	}
	ofs.close();
}
int workermanager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	return num;
}
void workermanager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker = NULL;
		if (did == 1)
		{
			worker = new employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void workermanager::Show_Emp()//展示
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int workermanager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workermanager::Del_Emp()//删除
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);//如果不存在返回-1
		if (index != -1)//说明职工存在，并且删掉index位置上的职工
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
			if (this->m_EmpNum == 0)
			{
				cout << "系统中无职工" << endl;
			}
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void workermanager::Mod_Emp()//修改
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改的职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int dselect = 0;
			cout << "查到" << id << "号职工，请输入新职工号:" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入新岗位" << endl;
			cout << "1,普通职工" << endl;
			cout << "2,经理" << endl;
			cout << "3,老板" << endl;
			cin >> dselect;
			worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new employee(newid, newname, dselect);
				break;
			case 2:
				worker = new Manager(newid, newname, dselect);
				break;
			case 3:
				worker = new boss(newid, newname, dselect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void workermanager::find_Emp()//寻找
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1,按照编号查找" << endl;
		cout << "2,按照名字查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的编号" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功,信息如下" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
			if (select == 2)
			{
				string name;
				cout << "请输入想要查找的名字" << endl;
				cin >> name;
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_name == name)
					{
						this->m_EmpArray[i]->showInfo();
					}
					else
			{
				cout << "查无此人" << endl;
			}
				}
			}
			
		}
	system("pause");
	system("cls");
}
void workermanager::sort_Emp()//排序
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方法" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minormax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minormax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		cout << "排序成功，结果为" << endl;
		this->save();
		this->Show_Emp();
	}
}
void workermanager::Clean_file()
{
	cout << "确定情况?" << endl;
	cout << "1,确定" << endl;
	cout << "2,返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");

}
workermanager::~workermanager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete[] this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}