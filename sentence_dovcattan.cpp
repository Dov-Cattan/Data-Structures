#include <iostream>
#include <string>
#include "sentence.h"
/********************************************************************************************
Name: Dov Cattan Z#: 23532899
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 02/22/2021 Due Time: 11:59 PM
Total Points: 25 Assignment 4: Linked Lists
Description: Linked Lists With Sentence Nodes
*********************************************************************************************/



using namespace std;
sentence::sentence()
{
	front = NULL;
	back = NULL;
	count = NULL;
}
sentence::sentence(const string& s)
{
	front = 0;
	back = 0;

	string temp;

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
		}

		else if (s[i] == ' ')
		{
			add_back(temp);
			temp = " ";
			add_back(temp);
			temp = "";
		}


	}
	add_back(temp);
}

word* sentence::Search(const string& subject)
{
	word* p = front;

	while (p != 0)
	{
		if (p->term == subject)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}
sentence::sentence(const sentence& org)
{
	
	
	word* sample = org.front;
	while (sample != 0)
	{
		add_back(sample->term);
		sample = sample->next;
	}
}

sentence:: ~sentence()
{
	cout << "Destructor has been called\n";
	while (front != 0)
	{
		word* p = front;
		front = front->next;
		delete p;
	}
}
bool isEmpty(int front)

{
	return front == 0;
}

int sentence::length()
{
	word* n = this->front;
	int len = 0;
	if (n == 0) //front has nothing just return the length
	{

		return len;
	}
	else	
	{
		while (n != 0) //while the front isn't null incerment the length and move on to the next node everytime
		{

			len += n->term.length();

			n = n->next;
		}
		return len; // return the length
	}
	

		
	
}
void sentence::add_back(string& s)
{
	if (s.length() != 0)
	{
		// declare that the term is the string and that next is nothing
		word* n = new word;
		n->term = s;
		n->next = 0;
		if (front == 0)
		{
			front = back = n;
		}
		else
		{
			back->next = n;
			back = n;
		}
	}

}
ostream& operator<<(ostream& out, const sentence& obj)
{
	/* word* n = new word;
	 n = obj.front;*/
	word* n = obj.front;
	while (n != 0)
	{
		out << n->term; //output the nodes and strings and spaces
		n = n->next;

	}
	return out;
}
void sentence::operator=(const string& s)
{
	front = back = 0;

	string str = s;

	if (str.length() == 0)
	{
		return;// no results
	}
	string _ = "";
	if (s.length() != 0) //if the string has a length
	{
		for (unsigned int i = 0; i < str.length(); i++)
		{
			if (s[i] != ' ')
			{
				_ += s[i]; //add a node without a space
			}

			else if (s[i] == ' ')
			{
				
				add_back(_); //add a space back
				_ = " ";
				add_back(_); // end the space
				_ = "";
			}
		
		}
		add_back(_);
	}
}
sentence& sentence::operator=(const sentence& w)
{
	front = back = 0;
	word* n = w.front;
	if(this != &w)
	{
	  while(front !=0)
	  {
		 n = front;
		 front = front ->next;
		 delete n;
	  }
	   back = front;
	   n = w.front;
	}

	while (n !=0)
	{
	  add_back(n->term);
	  n = n->next;
	}
	return *this;
}
void sentence::operator+(sentence& B)
{
	word* senfront = B.front;
	// if front of sentence B isnt zero do the following, otherwise return nothing
	if (senfront != 0)
	{
		while (senfront != 0)
		{
			//adds back to the term to allow the next node to appear
			add_back(senfront->term);
			senfront = senfront->next;
		}

	}
	else
	{
		return;//return nothing
	}
}
bool sentence::isEqual(sentence& B)
{
	//declaring the original front and front of sentence B
	word* pd = this->front;
	word* pt = B.front;
	// if the front are both zero than its correct
	if (pt == 0 && pd == 0)
	{
		return true;
	}
	// if the fronts are different in any shape or form than it is for sure false
	else if ((pt != 0 && pd == 0) || (pt == 0 && pd != 0))
	{
		return false;
	}
	// if the lengths are not the same for both B and and the original lengths than its false
	else if (B.length() != length()) {
	
		return false;
	
	}
	// while the original front isn't zero, if the terms of the sentence B and original fronts aren't the same,
	// then its false. Otherwise, declare the next nodes for both of the terms
	while (pd != 0) {
		if (pd->term != pt->term) {
			return false;
		
		}
		pd = pd->next;
		pt = pt->next;
	
	}
	// this implies that it is true considering all the if statements are passed
	return true;
	



	
}

void sentence::remove(const string& s)
{
	
	
	//if length is nothing then it is empty
       if (this->length() == 0)
	{
		cout<< "empty list\n";
	
	}
	   // if front of the term is the string then c is declared as front and the next front is called then c gets deleted
	else if (this->front->term ==s)
		{
		   word* c = front;
		   this->front = this->front->next;
		   delete c;
		
		}
	   // if not the following will take place
		else
		{
			word* p = front;
			word* c2 = front->next;
			// after p and c2 are declared a loop implying c2 not 0 is declared
			while (c2 != 0)
			{
				// if c2 of term is s break
				if (c2->term == s) {
					break;
				}
				//otherwise p is the same as c2 and c2 keeps on going
				else
				{
					p = c2;
					c2 = c2->next;
				}
			}
			// if c2 is null, than remove doesn't work
			if (c2 == 0)
			{
				cout << "remove doesn't work, no match found" << endl;
			}
			//otherwise p of next is the same as c2 of next and c2 gets deleted
			else
			{
				p->next = c2->next;
				delete c2;

			}
	   }
	}
	
	
	
	


