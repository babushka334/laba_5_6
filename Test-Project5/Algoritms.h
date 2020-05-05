#pragma once
#include "IteratorOut.h"

template<class T>
class Algoritm
{
	
	iter<T>* it;
public:
	typedef bool (__cdecl *Comp)(T, T);
	Algoritm()
	{
		it = NULL;
	}
	Algoritm(stack<T>*);
	//void poisk(T& obj);
	void poisk(iter<T>* it, T& obj);
	void quick_sort(stack<T>* p, iter<T>* it_left, iter<T>* it_right, Comp compare);
	~Algoritm();
};




template<class T>
Algoritm<T>::Algoritm(stack<T>* p)
{
	it = new iter<T>(p);
	it->begin();
}

template <class T>
Algoritm<T>::~Algoritm()
{
	if (!it)
		delete it;
}

template <class T>
//void Algoritm<T>::poisk(T& obj)
void Algoritm<T>::poisk(iter<T>* it, T& obj)
{
	it->begin();
	int k = 1;
	do
	{
		//if(*(*it) == obj)
		if (*it == obj)
		{
			cout << obj << endl;
			k = 0;
		}
	} while (((*it)++) == true);
	if (k)
		cout << "not find" << endl;
}

template <class T>
void Algoritm<T>::quick_sort(stack<T>* p, iter<T>* it_left, iter<T>* it_right, Comp compare)
{
	T obj;
	iter<T>* its = new iter<T>(p);
	int size = 0;
	its->begin();
	size = its->Size(size, it_left, it_right);
	int indx_of_pivot = size / 2;
	for (int i = 0; i < indx_of_pivot; i++)
	{
		it++;
	}

	iter<T>* it_pivot = its;
	iter<T>* i = it_left;
	iter<T>* j = it_right;

	while (*i <= j)
	{
		//while (arr[i] < pivot)
		while (compare(**i, **it_pivot))
			i++;
		//while (arr[j] > pivot)
		while (compare(**it_pivot, **j))
			j--;
		if (i <= j) 
		{
			swap(**i, **j);
			i++;
			j--;
		}
	}

	//if (left < j)
	if(compare(**j, **it_left))
		quick_sort(p, it_left, j, obj.cmpB_fio);
	//if (i < right)
	if (compare(**it_right, **i));
		quick_sort(p, i, it_right, obj.cmpB_fio);
}