#include <iostream>
#include <string>
#include "stack.h"
/********************************************************************Name: Dov Cattan Z#: 23532899 Course: Date Structures and Algorithm Analysis (COP3530) 
Professor: Dr. Lofton Bullard Due Date: 03/03/2021 Due Time: 11:59 PM 
Total Points: 25 Assignment Module 7: Stacks Description: Postfix to infix conversion with stacks*********************************************************************************************/
//STACK.CPP IMPLENTATION FILE
//Destructor
stack::~stack()
{

	while(s_top!=0)
	{
		pop();
	}
}
//Pop off the stack
void stack::pop()
{

	stack_node *p;
	
	if (s_top != 0)
	{
		p = s_top;
		s_top = s_top->next;
		delete p;
    count--;
	}
	
}
//Push into the stack
void stack::push(const stack_element & item)
{
	
	stack_node *p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
  count++;
}
//Print out the stack
void stack::print()
{
	

	for(stack_node *p = s_top; p!=0; p=p->next)
	{
		cout<<p->data<<endl;
	}
}
//Detect the top of the stack and end it there
stack_element stack::top()
{
	

	if (s_top == 0)
	{
		exit(1);
	}
	else
	{
		return s_top->data;
	}
}


//Conversion function 
void stack::conversion(const string &infix)
{
	int error = 0;

  string postfix;
	string expr,operand1,operand2;
  string operpush;
  string op;
  //detect empty space
  if(infix.length() == 0)
  {
    push("Empty");
  }
  //detect single operand
  else if(infix.length()==1)
  {
    push("("+infix+")");
  }
  else{
  // start of infix to postfix conversion 
	for (int i = 0; i < infix.length(); i++)
	{
     operpush = infix[i];
		if(infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/')
    {
            push(operpush);
    }
   else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
	{
     //check if there's too many operators and not enough operands
			if(count <2)
{
    	cout << "Too many operators and not enough operands" << endl;
      return;
}	
//execute infix to postifix conversion
	 else 
   {
   if(infix[i] == '+' )
      {
         op = "+";
      }
     else if(infix[i] == '-' )
      {
         op = "-";
      }
       else if(infix[i] == '*' )
      {
         op = "*";
      }
       else if(infix[i] == '/' )
      {
         op = "/";
      }
      operand2 = top();
      pop();
      operand1 = top();
      pop();
      expr = "(" + operand1 + op + operand2 + ")";
			push(expr);
   }
			
	}
  }
  //check if there's too many operands and not enough operators
  if(count!=1)
  {
    	cout << "Too many operands and not enough operators" << endl;
      return;
  }
  }
  //Print out to the main
	print();
	


}
