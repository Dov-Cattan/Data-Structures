#include <iostream>
#include "dovcattan_bqueue.h"
/********************************************************************
Name: Dov Cattan Z#: 23532899
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard Due Date: 03/10/2021
Due Time: 11:59 PM Total Points: 25
Assignment Module 8: Queues
Description: Circular Queues with doubly linked list implementation
*********************************************************************************************/
//BQUEUE DRIVER
using namespace std;
int main()
{
	bqueue k;
	k.print();
	k.enqueue(60);
	k.enqueue(20);
	k.enqueue(30);
	k.print();
	k.enqueue(10);
	k.print();
	k.enqueue(50);
	k.enqueue(40);
	k.print();
	bqueue j = k;
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	return 0;
}