#include "employee.h"


Employee::Employee(int id, string name, int depId) {
	this->m_id = id;
	this->m_name = name;
	this->m_depId = depId;
}
void Employee::showInfo() 
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t��λ:" << this->getDepName()
		<< "\tְ��: ��ɾ����������" << endl;
}
string Employee::getDepName() 
{
	return string("Ա��");
}