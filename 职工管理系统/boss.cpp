#include "boss.h"

Boss::Boss(int id, string name, int depId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_depId = depId;
}
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t��λ:" << this->getDepName()
		<< "\tְ��: ����˾��������" << endl;
}
string Boss::getDepName()
{
	return string("�ܲ�");
}