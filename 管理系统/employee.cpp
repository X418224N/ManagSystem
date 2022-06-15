#include"employee.h"
employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void employee::showInfo()
{
	cout << "职工编号:" << this->m_id << "职工姓名:" << this->m_name << "岗位:员工" << this->m_deptid << "职责:完成经理下发的任务" << endl;
 }
string employee::getDeptName()
{
	return string("员工");
}