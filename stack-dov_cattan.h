#include <iostream>
#include <string>
/********************************************************************Name: Dov Cattan Z#: 23532899 Course: Date Structures and Algorithm Analysis (COP3530) 
Professor: Dr. Lofton Bullard Due Date: 03/03/2021 Due Time: 11:59 PM 
Total Points: 25 Assignment Module 7: Stacks Description: Postfix to infix conversion with stacks*********************************************************************************************/
//STACK.H HEADER FILE

using namespace std;

typedef string stack_element;

class stack_node
{
public:
	stack_element data;
	stack_node* next;
};

class stack
{
public:
	stack() {count=0; s_top = 0; }
	~stack();
	stack_element top();
	void pop();
	void push(const stack_element&);
	void print();
	void conversion(const string&);

private:

	stack_node* s_top;
  int count;
};

