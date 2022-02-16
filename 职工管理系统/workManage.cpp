#include "workManage.h"

WorkManage::WorkManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
		cout << "�ļ�Ϊ��" << endl;
		this->m_empNum = 0;
		this->m_empArray = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	int num = this->get_empNum();
	cout << "ְ������Ϊ��" << endl;
	this->m_empNum = num;

	this->m_empArray = new Worker * [this->m_empNum];
	this->init_emp();
	for (int i = 0; i < this->m_empNum; i++)
	{
		cout << "ְ����ţ�" << this->m_empArray[i]->m_id
			<< "������" << this->m_empArray[i]->m_name
			<< "���ţ�" << this->m_empArray[i]->m_depId << endl;
	}

	this->m_empNum = 0;
	this->m_empArray = NULL;
}

void WorkManage::showMenu()
{
	cout << "********��ӭʹ��ְ��ϵͳ********" << endl;
	cout << "********0. �˳��������********" << endl;
	cout << "********1. ���ְ����Ϣ********" << endl;
	cout << "********2. ��ʾְ����Ϣ********" << endl;
	cout << "********3. ɾ����ְְ��********" << endl;
	cout << "********4. �޸�ְ����Ϣ********" << endl;
	cout << "********5. ����ְ����Ϣ********" << endl;
	cout << "********6. ���ձ������********" << endl;
	cout << "********7. ��������ĵ�********" << endl;
}

void WorkManage::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkManage::addEmp() 
{
	cout << "���������ְ��������" << endl;
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
			cout << "�������" <<i+1<<"����ְ�����" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "�������ְ����λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		cout << "�ɹ����" << addNum << "��Ա��" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	else
	{
		cout << "������Ҫɾ����Ա����" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if(index != -1)
		{
			for (int i = 0; i < m_empNum; i++)
				this->m_empArray[i] = this->m_empArray[i + 1];
			this->m_empNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	else
	{
		cout << "������Ҫ�޸ĵ�Ա����" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			delete this->m_empArray[index];
			int newId = 0;
			string newName = "";
			int depSelect = 0;
			cout << "�鵽"<<id<<"��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "������������" << endl;
			cin >> newName;

			cout << "�������¸�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
			cout << "�޸�ʧ�ܣ����޴���" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManage::find_emp()
{
	if(this->m_fileIsEmpty)
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	else
	{
		cout << "������ҷ�ʽ" << endl;
		cout << "����ְ����Ų���" << endl;
		cout << "����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ұ��" << endl;
			cin >> id;
			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
				this->m_empArray[ret]->showInfo();
			}
			else
				cout << "���޴���" << endl;
		}
		else if (select == 2)
		{
			bool flag = false;
			string name;
			cout << "�������������" << endl;
			cin >> name;
			for (int i = 0; i < this->m_empNum; i++)
			{
				if (this->m_empArray[i]->m_name == name)
				{
					cout << "���ҳɹ������Ϊ��"
						<< this->m_empArray[i]->m_id
						<< "��ְ����Ϣ���£�" << endl;
					flag = true;
					this->m_empArray[i]->showInfo();
				}		
			}
			if(flag == false)
				cout << "���޴���" << endl;
		}
		else
			cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManage::sort_emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ�������" << endl;
		system("pause");
		system("cls");
	}	
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.ְ��������" << endl;
		cout << "2.ְ���Ž���" << endl;
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
		cout << "����ɹ�" << endl;
		this->save();
		this->show_emp();
	}
}

void WorkManage::clean_file()
{
	cout << "ȷ�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
		cout << "��ճɹ�" << endl;
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