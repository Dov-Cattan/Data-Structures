#include <iostream>
/********************************************************************
Name: Dov Cattan Z#: 23532899 
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard Due Date: 03/10/2021 
Due Time: 11:59 PM Total Points: 25 
Assignment Module 8: Queues
Description: Circular Queues with doubly linked list implementation
*********************************************************************************************/
//BQUEUE HEADER
using namespace std;

#ifndef BQUEUE_H
#define BQUEUE_H

class bqnode
{ public:
int priority;
 bqnode* prev,* next;
}; 
class bqueue
{
public:
bqueue();
~bqueue();
bqueue(const bqueue& obj); 
void enqueue(int);
void dequeue();
void print();
private:
bqnode* front;
//Only one pointer is used here
};

#endif

