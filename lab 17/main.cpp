//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// main.cpp
//
#include "stack.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include  <string>
#include  <sstream>

using namespace std;

int main()
{
	l_stack<char> left, right;
	char a='_';
	ifstream file("text.txt");
	while (!file.eof())
	{
		file >> a;
		if (a == '{' || a == '[' || a == '(') left.push(a);
		else
		if (a == '}' || a == ']' || a == ')') right.push(a);
		a = '!';
	}
	while (!left.is_empty() && !right.is_empty() && (left.top()==right.top() ))
	{
		left.pop();
		right.pop();
	}
	//cout << left.is_empty() && right.is_empty();

	string c=" ((1+2)*(3-4))/5";
	string out1 = "";
	l_stack< char> tmp;
	l_stack<char> out;
	stringstream k;
	k << c;
	bool FLAG_Prev = 0;
	while ( !k.eof())
	{
		a = '_';
		k >> a;
		if (a >= '0'&& a <= '9')
			if (FLAG_Prev)
				out1[out1.size()] = a;
			else
			{
				out1= out1 + a +" " ;
				FLAG_Prev = true;
			}
		else {
			if (a == '(' || a == ')')
				if (a == ')')
				{
					while (tmp.top() != '(')
					{
						out1 = out1+ tmp.top()+ " " ;
						tmp.pop();
					}
					
					tmp.pop();
				}
				else
				{
					
					tmp.push(a);
				}
			if (a == '*' || a == '/')
				if (tmp.is_empty()|| tmp.top() == '+' || tmp.top() == '-' || tmp.top() == '('  )
				{
					
					tmp.push(a);
				}
				else
				{
					out1 = out1+ tmp.top()+ " " ;
					tmp.pop();
					tmp.push(a);
				}
			if (a=='+'|| a=='-')
				if (tmp.is_empty() || tmp.top() == '(')
					tmp.push(a);
				else
				 if (tmp.top() == '*' || tmp.top() == '/' )
				{
					 out1 = out1 + tmp.top() + " ";
					 tmp.pop();
					 tmp.push(a);
				}
				 else
					 {
					 out1 = out1 + tmp.top() + " ";
						 tmp.pop();
						 tmp.push(a);
					 }

			FLAG_Prev = false;
			
		}
		
	}
	while (!tmp.is_empty())
		{
			out1 = out1 + tmp.top() + " ";
			tmp.pop();
		}
	cout << out1;
    system("pause");
    return 0;
}