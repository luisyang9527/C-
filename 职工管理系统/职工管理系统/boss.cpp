#include "boss.h"

Boss::Boss(int id, string name, int depId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_depId = depId;
}
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDepName()
		<< "\t职责: 管理公司所有事务" << endl;
}
string Boss::getDepName()
{
	return string("总裁");
}