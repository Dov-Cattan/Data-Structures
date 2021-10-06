/*
This is a simple program to give the student experience writing code
for binary trees.  This is a CLASS implementation of the BST ADT.
The student should study, comment, correct errors, compile,
implement/un-implemented/undeveloped functions, and modify code to make
it more efficient when ever necessary. The student should be able to
discuss the advantages and disadvantages of using such an
implementation.
*/


#include <iostream>
#include <string>
#include "dovcattan_bst.h"
using namespace std;


bool bst::empty()
{
	return (root == 0);
}

void bst::insert(const string& item,const double &population)
{

	insert_info(root,item,population);
}



void bst::insert_info(treenode*& loc_ptr, const string& item, const double& population)
{

  if (loc_ptr == 0)
  {

    loc_ptr = new treenode;
    loc_ptr->lchild = loc_ptr->rchild = 0;
    loc_ptr->county_name = item;
    loc_ptr->population_size = population;
  }
  else if (loc_ptr->county_name > item)
  {
    insert_info(loc_ptr->lchild, item, population);
  }
  else if (loc_ptr->county_name < item)
  {
    insert_info(loc_ptr->rchild, item, population);
  }
  else
  {
    cout << "the item is already in the tree\n";
  }
}



treenode * bst::search_tree(string item)
{
	return search_tree(root, item);
}

treenode * bst::search_tree(treenode * loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
			return loc_ptr;
		else if (loc_ptr->county_name>item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}



void bst::del_name(string item)
{
	del_name(root, item);
}

void bst::del_name(treenode * & loc_ptr, string item)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->county_name < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode * ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}

}

treenode * bst::inorder_succ(treenode * loc_ptr)
{

	treenode *ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

void bst::print_tree()
{
	print_tree(root);
}

void bst::print_tree(treenode * &loc_ptr)
{
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->county_name << endl;
		print_tree(loc_ptr->rchild);
	}
}


bst::~bst()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}



