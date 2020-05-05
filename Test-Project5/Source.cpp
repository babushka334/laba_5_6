#include "Player.h"
#include <windows.h>




int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stack<Player>* q = new stack<Player>;
	iter<Player> it(q);
	iter<Player> its(q);
	Player obj;
	Player* ob;
	Algoritm<Player> alg(q);
	int vibor;
	char c = 'n';
	do
	{
		cout << "1 - add: 2 - del: 3 - show: 4 - iter++:" << endl;
		cout << "5 - iter --: 6 - iter begin: 7 - iter *: 8 iter - end" << endl;
		cin >> vibor;
		switch (vibor)
		{
		case 1:
		{
			cout << " Vvod Player " << endl;
			cin >> obj;
			q->add(obj);
			it.begin();
			break;
		}
		case 2:
		{
			q->del();
			break;
		}
		case 3:
		{
			do
			{
				cout << *it << endl;
			} while ((it++) == true);
			//q->show();
			//break;

			//q->show();
			break;
		}
		case 4:
		{
			if ((it++) == false)
				cout << "error" << endl;
			break;
		}
		case 5:
		{
			if ((it--) == false)
				cout << "error" << endl;
			break;
		}
		case 6:
		{
			if (it.begin() == false)
				cout << "error" << endl;
			break;
		}
		case 7:
		{
			//do
			//{
			cout << *it << endl;
			//}while((it++)== true);
			break;
		}
		case 8:
			if (it.end() == false)
				cout << "error" << endl;
			break;

		case 9:
		{
			it.begin();
			its.end();
			alg.quick_sort(q, &it, &its, obj.cmpB_fio);
			break;
		}
		}
		cout << "Continue y/n" << endl;
		cin >> c;
	} while (c == 'y');
	return 0;
}
