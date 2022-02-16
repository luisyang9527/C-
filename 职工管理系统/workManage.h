#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkManage
{
public:
	WorkManage();

	void showMenu();
	void exitSystem();
	int m_empNum;
	Worker** m_empArray;
	void addEmp();
	void save();
	bool m_fileIsEmpty;
	int get_empNum();
	void init_emp();
	void show_emp();
	void del_emp();
	int isExist(int id);
	void mod_emp();
	void find_emp();
	void sort_emp();
	void clean_file();

	~WorkManage();
};