#include"employee.h"
employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void employee::showInfo()
{
	cout << "ְ�����:" << this->m_id << "ְ������:" << this->m_name << "��λ:Ա��" << this->m_deptid << "ְ��:��ɾ����·�������" << endl;
 }
string employee::getDeptName()
{
	return string("Ա��");
}