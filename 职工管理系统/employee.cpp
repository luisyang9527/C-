#include "employee.h"


Employee::Employee(int id, string name, int depId) {
	this->m_id = id;
	this->m_name = name;
	this->m_depId = depId;
}
void Employee::showInfo() 
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDepName()
		<< "\t职责: 完成经理给的任务" << endl;
}
string Employee::getDepName() 
{
	return string("员工");
}