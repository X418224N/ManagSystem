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
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出程序
			wm.Exitsystem();
			break;
		case 1://增加员工信息
			wm.Add_Emp();
			break;
		case 2://显示员工信息
			wm.Show_Emp();
			break;
		case 3://删除离职员工
		/*{
			int ret = wm.IsExist(1);
			if (ret != -1)
			{
				cout << "职工存在" << endl;
			}
			else
			{
				cout << "职工不存在" << endl;
			}
			break;
		}*/
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.find_Emp();
				break;
		case 6://编号排序
			wm.sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_file();
				break;
		default:
			system("cls");
		}
	}
	system("pause");
	return 0;
}