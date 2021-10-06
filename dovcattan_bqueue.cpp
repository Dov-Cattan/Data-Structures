#include<iostream>
#include "dovcattan_bqueue.h"
/********************************************************************
Name: Dov Cattan Z#: 23532899
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard Due Date: 03/10/2021
Due Time: 11:59 PM Total Points: 25
Assignment Module 8: Queues
Description: Circular Queues with doubly linked list implementation
*********************************************************************************************/
//BQUEUE IMPLEMENTATION FILE
using namespace std;

//Default Constructor
bqueue::bqueue()
{
	
	front = 0;
}
//Destructor
bqueue::~bqueue()
{
	
	while (front != 0)
	{
		dequeue();
	}
}
//Copy Constructor
bqueue::bqueue(const bqueue& obj)
{
	
	bqnode* p = obj.front;

	if (p == 0)
	{
		cout << "Cannot print Queue because queue is empty\n" << endl;
	}

	else
	{
		do
		{
			enqueue(p->priority);
			p = p->next;
		} while (p != obj.front);

	}
}
//Explicit-Value Constructor/ adding the element to the circular queue
void bqueue::enqueue(int priority)
{
	
	if (front == 0)
	{
		front = new bqnode;
		front->priority = priority;
		front->next = front;
		front->prev = front;
	}
	else
	{
		front->prev->next= new bqnode;
		front->prev->next->prev = front->prev;
		front->prev = front->prev->next;
		front->prev->next = front;
		front->prev->priority = priority;
	}
}
// Decreasing the elements in the circular queue
void bqueue::dequeue( )
{
	if (front != 0)
	{
		bqnode *p = front;
		front = front->next;
		if (p != front)
		{
			front->prev = p->prev;
			p->prev->next = front;
		}
		else
		{
			front = 0;
		}
		delete p;
	}
	else
	{
		cout<<"Cannot deQueue because queue is empty\n";
	}

}
//Print out the queues
void bqueue::print()
{

	bqnode *p = front;
	if(p == 0)
	{
		cout << "Cannot print Queue because queue is empty\n" << endl;
	}

	else
	{
		do
		{
			cout << p->priority << endl;
			p = p->next;
		} while (p != front);
	  
	}
}