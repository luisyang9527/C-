#include "manager.h"

Manager::Manager(int id, string name, int depId) 
{
	this->m_id = id;
	this->m_name = name;
	this->m_depId = depId;
}
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDepName()
		<< "\t职责: 完成老板给的任务，并下发任务给员工" << endl;
}
string Manager::getDepName()
{
	return string("经理");
}