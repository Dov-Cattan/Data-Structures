#include <iostream>
#include <vector>
#include <string>
#include "dovcattan_vlist.h" 
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist()
{
	count =0;
  vectorsize =9;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & Org)
{
  DB =Org.DB;
count = Org.count;
print();


}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 
vlist::~vlist()
{
 count = 0; 
 DB.empty();
}

//more skeletons -- implement

bool vlist::isEmpty() {
   if(count ==0)
   {
    return true;
   }
else
 {
    return false;
 } 
 }

vector<string>::iterator vlist::search(const string& key)
{
  
  for(vector<string>::iterator i = DB.begin(); i != DB.end();i++)
 {

  if (key==*i)
  {
     return i;
  }
 }

   return DB.end();
    
}

void vlist::insert(const string & key)
{
   
     
      for (vector<string>::iterator i = DB.begin(); i !=DB.end(); i++) 
       {

       if(*i >=key)
       {
            DB.insert(i,key);
            count++;
            return;

             
       }
    
       }
      DB.insert(DB.end(),key);
            count++;
       

}

void vlist::remove(const string& key) 
{
  vector<string>::iterator position=search(key);
  if(position!=DB.end()) 
  {
    DB.erase(position);
    count--;
  }
  else 
  {
    cout<<"The item is not in the list\n";
  }
  
  
}
void vlist::print()
 {
   for (vector<string>::iterator i = DB.begin(); i !=DB.end(); i++) 
   {
           cout<< *i<<" ";
    }
    cout<<endl;
 }

