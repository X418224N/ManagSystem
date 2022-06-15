#include"workerManager.h"
workermanager::workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
	int num = this->get_Empnum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new worker * [this->m_EmpNum];//���ٿռ�
	this->init_Emp();//���ļ������ݴ浽������
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << this->m_EmpArray[i]->m_id << endl;
	//	cout << this->m_EmpArray[i]->m_name << endl;
	//	cout << this->m_EmpArray[i]->m_deptid<< endl;
	//}
}
void workermanager::Show_Menu()
{
	cout << "0.�˳�����" << endl;
	cout << "1.����Ա����Ϣ" << endl;
	cout << "2.��ʾԱ����Ϣ" << endl;
	cout << "3.ɾ����ְԱ��" << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << "5.����ְ����Ϣ" << endl;
	cout << "6.�������" << endl;
	cout << "7.����ĵ�" << endl;
}
void workermanager::Exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workermanager::Add_Emp()//���ְ��
{
	cout << "���������ְ������" << endl;
	int addnum = 0;
	cin >> addnum;//�����û���������
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;//�¿ռ�����=ԭ����¼����+��������
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
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
				while (true)
				{
					cin >> id;
					int ret = IsExist(id);
					if (ret != -1)
					{
						cout << "����ظ�" << endl;
					}
					else
					{
						break;
					}
			}
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ��ְ����λ" << endl;
			cout << "1,��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		delete[] this->m_EmpArray;//�ͷ�ԭ�пռ�
		this->m_EmpArray = newSpace;//�����¿ռ�ָ��
		this->m_EmpNum = newSize;//����ְ������
		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << addnum << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}
void workermanager::save()//�����ļ�
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
void workermanager::Show_Emp()//չʾ
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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

void workermanager::Del_Emp()//ɾ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);//��������ڷ���-1
		if (index != -1)//˵��ְ�����ڣ�����ɾ��indexλ���ϵ�ְ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
			if (this->m_EmpNum == 0)
			{
				cout << "ϵͳ����ְ��" << endl;
			}
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void workermanager::Mod_Emp()//�޸�
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int dselect = 0;
			cout << "�鵽" << id << "��ְ������������ְ����:" << endl;
			cin >> newid;
			cout << "������������" << endl;
			cin >> newname;
			cout << "�������¸�λ" << endl;
			cout << "1,��ְͨ��" << endl;
			cout << "2,����" << endl;
			cout << "3,�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "���޴���" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
void workermanager::find_Emp()//Ѱ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1,���ձ�Ų���" << endl;
		cout << "2,�������ֲ���" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵı��" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�,��Ϣ����" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
			if (select == 2)
			{
				string name;
				cout << "��������Ҫ���ҵ�����" << endl;
				cin >> name;
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_name == name)
					{
						this->m_EmpArray[i]->showInfo();
					}
					else
			{
				cout << "���޴���" << endl;
			}
				}
			}
			
		}
	system("pause");
	system("cls");
}
void workermanager::sort_Emp()//����
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ���" << endl;
		cout << "1.��ְ���Ž�������" << endl;
		cout << "2.��ְ���Ž��н���" << endl;
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
		cout << "����ɹ������Ϊ" << endl;
		this->save();
		this->Show_Emp();
	}
}
void workermanager::Clean_file()
{
	cout << "ȷ�����?" << endl;
	cout << "1,ȷ��" << endl;
	cout << "2,����" << endl;
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
		cout << "��ճɹ�" << endl;
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