#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showInfo()
{
	cout << "ְ�����:" << this->m_id <<"ְ������:" << this->m_name << "��λ:�ϰ�" << this->m_deptid << "ְ��:�ַ�����" << endl;
}
string boss::getDeptName()
{
	return string("�ϰ�");
}