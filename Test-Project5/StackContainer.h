#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>

template <class T>
struct node
{
	T data;
	node<T>* next;
	node<T>* prev;
};


template<class T>
class stack
{
	node<T>* head;
	template<class T>
	friend class iter;
	template<class T>
	friend class Algoritm;
public:
	stack();
	stack(const T& ob);
	~stack();
	void add(T);
	void del();
	void show();
	bool empty();
};








using namespace std;

template<class T>
stack<T>::stack()
{
	head = NULL;
}
template< class T>
stack<T>::stack(const T& ob)
{
	head = new node<T>;
	head->data = ob.data;
	head->next = NULL;
	head->prev = NULL;
}
template<class T>
void stack<T>::add(T dataPar)
{
	if (!head)
	{
		head = new node<T>;
		head->data = dataPar;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		node<T>* ptr = new node<T>;
		ptr->data = dataPar;
		ptr->next = head;
		ptr->prev = NULL;
		head->prev = ptr;
		head = ptr;
	}
}
template<class T>
void stack<T>::show()
{
	if (head == NULL)
	{
		cout << "Stack empty" << endl;
	}
	else
	{
		node<T>* ptr = head;
		while (ptr->next != NULL)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
		cout << ptr->data << endl;
	}
}
template<class T>
void stack<T>::del()
{
	if (head)
	{
		node<T>* ptr = head;
		head = head->next;
		delete ptr;
	}
	else
		cout << "Stak empty" << endl;
}
template<class T>
stack<T>::~stack()
{
	if (head)
	{
		while (head != NULL)
		{
			node<T>* ptr = head;
			head = head->next;
			delete ptr;
		}
	}
}
template<class T>
bool stack<T>::empty()
{
	if (head == NULL)
		return 1;
	else
		return 0;
}