#include<iostream>
#include"workerManager.h"
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"Manager.h"
int main()
{	
	worker* worker = NULL;
	workermanager wm;
	int choice = 0;
	while (true)
	{

		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�����
			wm.Exitsystem();
			break;
		case 1://����Ա����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾԱ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ����ְԱ��
		/*{
			int ret = wm.IsExist(1);
			if (ret != -1)
			{
				cout << "ְ������" << endl;
			}
			else
			{
				cout << "ְ��������" << endl;
			}
			break;
		}*/
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.find_Emp();
				break;
		case 6://�������
			wm.sort_Emp();
			break;
		case 7://����ĵ�
			wm.Clean_file();
				break;
		default:
			system("cls");
		}
	}
	system("pause");
	return 0;
}