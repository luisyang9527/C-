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
		cout << "�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		int sex;
		cout << "�������Ա�" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "��������������" << endl;
		}

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;
		
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ�޼�¼" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "����:" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�:" << (abs->personArray[i].m_sex == 1? "��" : "Ů") << "\t";
			cout << "����:" << abs->personArray[i].m_age << "\t";
			cout << "�绰:" << abs->personArray[i].m_phone << "\t";
			cout << "סַ:" << abs->personArray[i].m_addr << endl;
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
	cout << "������Ҫɾ������" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBooks* abs)
{
	cout << "������Ҫ���ҵ���" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "����:" << abs->personArray[ret].m_name << "\t";
		cout << "�Ա�:" << (abs->personArray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "����:" << abs->personArray[ret].m_age << "\t";
		cout << "�绰:" << abs->personArray[ret].m_phone << "\t";
		cout << "סַ:" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBooks* abs)
{
	cout << "������Ҫ���ҵ���" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		int sex;
		cout << "�������Ա�" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "��������������" << endl;
		}

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		cout << "��ӳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	
	system("pause");
	system("cls");
}

void cleanPerson(AddressBooks* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "*****1. add��ϵ��*****" << endl;
	cout << "*****2. show��ϵ��*****" << endl;
	cout << "*****3. delete��ϵ��*****" << endl;
	cout << "*****4. find��ϵ��*****" << endl;
	cout << "*****5. change��ϵ��*****" << endl;
	cout << "*****6. clear��ϵ��*****" << endl;
	cout << "*****0. �˳�*****" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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