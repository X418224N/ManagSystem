#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showInfo()
{
	cout << "职工编号:" << this->m_id <<"职工姓名:" << this->m_name << "岗位:老板" << this->m_deptid << "职责:分发任务" << endl;
}
string boss::getDeptName()
{
	return string("老板");
}