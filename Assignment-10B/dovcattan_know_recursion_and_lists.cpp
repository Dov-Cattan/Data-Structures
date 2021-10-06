#include<iostream>
#include <string>
#include<iomanip>
using namespace std;
class node
{
  public:
 int data;
 node * next;
};
void add_back(node * & front,node * &back,int i)
{
if(front == NULL && back == NULL)
{
front = back = new node;
front->data = i;
}
else
{
back->next = new node;
back = back->next;
back->data =i;
}

}
void fun(class node* start)
{
 if(start == NULL)
return;
 cout<<start->data;
 if(start->next != NULL )
fun(start->next->next);
 cout<<start->data;
}
int main()
{
 
node* front = 0;
node* back = 0;
for (int i = 1; i <= 6; i++)
{
add_back(front, back, i);
}
fun(front);

return 0;
}