#pragma once
#include "StackContainer.h"

template<class T>
class iter
{
	stack<T>* q;
	node<T>* current;
public:
	iter();
	iter(stack<T>*);
	~iter();
	bool begin();
	bool end();
	bool end(int& count);
	int Size(int count, iter<T>* left, iter<T>* right);
	bool operator ++(int kostil);
	bool operator --(int kostil);
	bool operator == (T data);
	bool operator <= (iter<T>* right);
	bool operator != (T data);
	T& operator *();
};





template<class T>
iter<T>::iter()
{
	q = new stack<T>;
	current = NULL;
}
template<class T>
iter<T>::iter(stack<T>* stack)
{
	q = stack;
	current = q->head;
}
template<class T>
bool iter<T>::begin()
{
	if (q->head)
	{
		current = q->head;
		return true;
	}
	else
		return false;
}
template<class T>
bool iter<T>::end()
{
	if (q->head)
	{
		node<T>* ptr;
		ptr = q->head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		current = ptr;
		return true;
	}
	else
		return false;
}
template<class T>
bool iter<T>::end(int& count)
{
	count = 0;
	if (q->head)
	{
		node<T>* ptr;
		ptr = q->head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			count++;
		}
		current = ptr;
	}
	else
		return false;
}
template<class T>
int iter<T>::Size(int count, iter<T>* left, iter<T>* right)
{
	count = 0;
	if (q->head)
	{
		node<T>* ptr;
		ptr = left->current;
		while (ptr->next != right->current->next)
		{
			ptr = ptr->next;
			count++;
		}
		return count;

	}
	else
		return 0;
}
template<class T>
bool iter<T>::operator++(int kostil)
{
	if (current->next)
	{
		current = current->next;
		return true;
	}
	return false;
}
template<class T>
bool iter<T>::operator--(int kostil)
{
	if (current->prev)
	{
		current = current->prev;
		return true;
	}
	return false;
}

template<class T>
T& iter<T>::operator*()
{
	if (current)
		return current->data;
	//else return current; //сделать бы тут исключение...
}

template<class T>
bool iter<T>::operator==(T data)
{
	if (current->data == data)
		return 1;
	return 0;
}
template<class T>
bool iter<T>::operator<=(iter<T>* right)
{
	int count = 0;
	bool flag = false;
	if (q->head)
	{
		node<T>* ptr;
		ptr = this->current;
		while (ptr->next != NULL)
		{
			if (ptr == *right->current)
			{
				flag = true;
				break;
			}
			count++;
			ptr = ptr->next;
		}
		return count;

	}
	else
		return 0;
}
template<class T>
bool iter<T>::operator!=(T data)
{
	if (current->data != data)
		return 1;
	return 0;
}
template<class T>
iter<T>::~iter()
{
	delete q;
	///delete current;
}