#include "workManage.h"

WorkManage::WorkManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	int num = this->get_empNum();
	cout << "职工人数为：" << endl;
	this->m_empNum = num;

	this->m_empArray = new Worker * [this->m_empNum];
	this->init_emp();
	for (int i = 0; i < this->m_empNum; i++)
	{
		cout << "职工编号：" << this->m_empArray[i]->m_id
			<< "姓名：" << this->m_empArray[i]->m_name
			<< "部门：" << this->m_empArray[i]->m_depId << endl;
	}

	this->m_empNum = 0;
	this->m_empArray = NULL;
}

void WorkManage::showMenu()
{
	cout << "********欢迎使用职工系统********" << endl;
	cout << "********0. 退出管理程序********" << endl;
	cout << "********1. 添加职工信息********" << endl;
	cout << "********2. 显示职工信息********" << endl;
	cout << "********3. 删除离职职工********" << endl;
	cout << "********4. 修改职工信息********" << endl;
	cout << "********5. 查找职工信息********" << endl;
	cout << "********6. 按照编号排序********" << endl;
	cout << "********7. 清空所有文档********" << endl;
}

void WorkManage::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkManage::addEmp() 
{
	cout << "请输入添加职工的数量" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_empNum + addNum;
		Worker** newSpace = new Worker* [newSize];
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				newSpace[i] = this->m_empArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int depSelect;
			cout << "请输入第" <<i+1<<"个新职工编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请输入该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> depSelect;

			Worker* worker = NULL;
			switch (depSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_empNum + i] = worker;
		}
		delete[] this->m_empArray;
		this->m_empArray = newSpace;
		this->m_empNum = newSize;
		cout << "成功添加" << addNum << "名员工" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManage::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empNum; i++)
	{
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_depId << endl;
	}
	ofs.close();
}

int WorkManage::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		num++;
	}
	return num;
}

void WorkManage::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		Worker* worker = NULL;
		if (depId == 1)
			worker = new Employee(id, name, depId);
		else if(depId == 2)
			worker = new Manager(id, name, depId);
		else
			worker = new Boss(id, name, depId);
		this->m_empArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkManage::show_emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_empNum; i++)
			this->m_empArray[i]->showInfo();
		system("pause");
		system("cls");
	}
}

void WorkManage::del_emp()
{
	if (this->m_fileIsEmpty)
		cout << "文件不存在或者记录为空" << endl;
	else
	{
		cout << "请输入要删除的员工号" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if(index != -1)
		{
			for (int i = 0; i < m_empNum; i++)
				this->m_empArray[i] = this->m_empArray[i + 1];
			this->m_empNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
			cout << "删除失败，未找到该员工" << endl;
	}
	system("pause");
	system("cls");
}

int WorkManage::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->m_empArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkManage::mod_emp()
{
	if (this->m_fileIsEmpty)
		cout << "文件不存在或者记录为空" << endl;
	else
	{
		cout << "请输入要修改的员工号" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			delete this->m_empArray[index];
			int newId = 0;
			string newName = "";
			int depSelect = 0;
			cout << "查到"<<id<<"号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名" << endl;
			cin >> newName;

			cout << "请输入新岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> depSelect;

			Worker* worker = NULL;
			switch (depSelect)
			{
			case 1:
				worker = new Employee(newId, newName, depSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, depSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, depSelect);
				break;
			default:
				break;
			}
			this->m_empArray[index] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else
			cout << "修改失败，查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManage::find_emp()
{
	if(this->m_fileIsEmpty)
		cout << "文件不存在或输入为空" << endl;
	else
	{
		cout << "输入查找方式" << endl;
		cout << "按照职工编号查找" << endl;
		cout << "按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找编号" << endl;
			cin >> id;
			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "查找成功，职工信息如下：" << endl;
				this->m_empArray[ret]->showInfo();
			}
			else
				cout << "查无此人" << endl;
		}
		else if (select == 2)
		{
			bool flag = false;
			string name;
			cout << "请输入查找姓名" << endl;
			cin >> name;
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArray[i]->m_name == name)
				{
					cout << "查找成功，编号为："
						<< this->m_empArray[i]->m_id
						<< "号职工信息如下：" << endl;
					flag = true;
					this->m_empArray[i]->showInfo();
				}		
			}
			if(flag == false)
				cout << "查无此人" << endl;
		}
		else
			cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManage::sort_emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在" << endl;
		system("pause");
		system("cls");
	}	
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.职工号升序" << endl;
		cout << "2.职工号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_empNum; i++)
		{
			int min_max = i;
			for (int j = i + 1; j < this->m_empNum; j++)
			{
				if (select == 1)
				{
					if (this->m_empArray[min_max]->m_id > this->m_empArray[j]->m_id)
						min_max = j;
				}
				else
				{
					if (this->m_empArray[min_max]->m_id < this->m_empArray[j]->m_id)
						min_max = j;
				}
			}
			if (i != min_max)
			{
				Worker* temp = this->m_empArray[i];
				this->m_empArray[i] = this->m_empArray[min_max];
				this->m_empArray[min_max] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->save();
		this->show_emp();
	}
}

void WorkManage::clean_file()
{
	cout << "确定清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_empArray != NULL)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				delete this->m_empArray[i];
				this->m_empArray[i] = NULL;
			}
			delete[] this->m_empArray;
			this->m_empNum = 0;
			this->m_fileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkManage::~WorkManage()
{
	if (this->m_empArray != NULL)
	{
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
}