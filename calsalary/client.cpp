#include"calsal.h"
#include"salesperson.h"
#include"manager.h"

class printsalary
{
public:
	void displaysal(employee *e)
	{
		e->calsal();
		e->display();
		if (typeid(*e) == typeid(manager))
		{
			manager *mg = dynamic_cast<manager*>(e);
			mg->forreal();
		}
	}
};

class acceptance
{
public:
	void accept1(employee *e)
	{
		e->accept();
	}
};


void main()
{
	employee **ptr = NULL;
	int num,i;
	cout << "enter total num\n";
	cin >> num;
	ptr = new employee*[num];
	for (i = 0; i < num; i++)
	{
		cout << "enter choice";
		cout << "1.sales person\n";
		cout << "2.employee\n";
		cout << "3.manager\n";
		int ch;
		cin >> ch;
		acceptance ac;
		switch(ch)
		{
		case 1:
			ptr[i] = new salesperson[1];
			ac.accept1(ptr[i]);
			break;
		case 3:
			ptr[i] = new manager[1];
			ac.accept1(ptr[i]);
			break;
        }
    }

	for (i = 0; i < num; i++)
	{
		printsalary ex;
		ex.displaysal(ptr[i]);
	}
	_getch();
}