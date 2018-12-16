//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// stack.h
//
#pragma once
#include <iostream>

template <typename T> 
class l_stack 
{	
	
    // Узел списка
    struct node 
    {
        T data;
        node * next;
    };

    // Начало списка
    node *begin;
	
	friend void coppy(node *is, node *&to)
	{
		
			if (is == nullptr)
			{
				to = nullptr;
				return;
			}
			l_stack<T>::node *p = new l_stack<T>::node;
			p->data = is->data;
			p->next = nullptr;
			to = p;
			coppy(is->next, to->next);
		

	}
	friend void delete_list(node *&is)
	{
		l_stack::node *tmp;
		while (is != nullptr)
		{
			tmp = is->next;
			delete is;
			is = tmp;
		}

	}
	friend void edd_list(node *&is, const T & x)
	{
		if (is == nullptr)
		{
			l_stack::node *p = new l_stack::node;
			p->data = x;
			p->next = nullptr;
			is = p;
			return;
		}
		l_stack::node *p = new l_stack::node;
		p->data = x;
		p->next = is;
		is = p;

	}

public:
	l_stack() :begin(nullptr) {};

	l_stack(const l_stack<T> &s)
	{
		coppy(s.begin, this->begin);
	}
    l_stack &operator=(const l_stack<T> &s)
	{
		coppy(s.begin, this->begin);
		return *this;
	}

    ~l_stack()
	{
		delete_list(this->begin);
	}

    bool is_empty()
	{
		return this->begin == nullptr;
	}
    void push(const T &x)
	{
		edd_list(begin, x);
	}
    void pop()
	{

		node *tmp = begin->next;

		delete begin;
		begin = nullptr;
		begin = tmp;

	}
    T & top()
	{
		
		
		
		return  begin->data;
	}
	
	friend std::ostream &operator<<(std::ostream &os, const l_stack<T> &s)
	{
		l_stack::node *tmp = s.begin;
		while (tmp)
		{
			os << tmp->data << " ";
			tmp = tmp->next;
		}
		return os;
	}
};
