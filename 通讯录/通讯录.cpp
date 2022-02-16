#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

struct AddressBooks
{
	struct Person personArray[MAX];
	int m_size;
};

void addPerson(AddressBooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		int sex;
		cout << "请输入性别" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重输" << endl;
		}

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;
		
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前无记录" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名:" << abs->personArray[i].m_name << "\t";
			cout << "性别:" << (abs->personArray[i].m_sex == 1? "男" : "女") << "\t";
			cout << "年龄:" << abs->personArray[i].m_age << "\t";
			cout << "电话:" << abs->personArray[i].m_phone << "\t";
			cout << "住址:" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
			return i;
	}
	return -1;
}

void deletePerson(AddressBooks* abs)
{
	cout << "请输入要删除的人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBooks* abs)
{
	cout << "请输入要查找的人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << abs->personArray[ret].m_name << "\t";
		cout << "性别:" << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs->personArray[ret].m_age << "\t";
		cout << "电话:" << abs->personArray[ret].m_phone << "\t";
		cout << "住址:" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBooks* abs)
{
	cout << "请输入要查找的人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		int sex;
		cout << "请输入性别" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重输" << endl;
		}

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		cout << "添加成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}

void cleanPerson(AddressBooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "*****1. add联系人*****" << endl;
	cout << "*****2. show联系人*****" << endl;
	cout << "*****3. delete联系人*****" << endl;
	cout << "*****4. find联系人*****" << endl;
	cout << "*****5. change联系人*****" << endl;
	cout << "*****6. clear联系人*****" << endl;
	cout << "*****0. 退出*****" << endl;
}

int main()
{
	AddressBooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}