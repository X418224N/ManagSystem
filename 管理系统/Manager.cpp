#include"Manager.h"
Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void Manager::showInfo() 
{
	cout << "ְ�����:" << this->m_id << " ְ������:" << this->m_name << " ��λ:����" << this->m_deptid<< " ְ��:�ַ��������boss�ַ��������·���Ա��" << endl;
}
string Manager::getDeptName()
{
	return string("����");
}