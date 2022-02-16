#include <iostream>
#include "workManage.h"
using namespace std;

//#include "worker.h"
//#include "employee.h"
//#include "manager.h"
//#include "boss.h"

int main()
{
	/*Worker* worker;
	worker = new Employee(1, "yang", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "zhang", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "wang", 3);
	worker->showInfo();
	delete worker;*/

	WorkManage wm;
	int chioce;
	while (true)
	{
		wm.showMenu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ:" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();
			break;
		case 2:
			wm.show_emp();
			break;
		case 3:
			wm.del_emp();
			break;
		case 4:
			wm.mod_emp();
			break;
		case 5:
			wm.find_emp();
			break;
		case 6:
			wm.sort_emp();
			break;
		case 7:
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}