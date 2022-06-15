#include"Manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Manager::showInfo() 
{
	cout << "职工编号:" << this->m_id << " 职工姓名:" << this->m_name << " 岗位:经理" << this->m_deptid<< " 职责:分发任务完成boss分发的任务并下发到员工" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}