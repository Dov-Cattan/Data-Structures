#include <iostream>
#include <string>
#include "stack.h"
/********************************************************************Name: Dov Cattan Z#: 23532899 Course: Date Structures and Algorithm Analysis (COP3530) 
Professor: Dr. Lofton Bullard Due Date: 03/03/2021 Due Time: 11:59 PM 
Total Points: 25 Assignment Module 7: Stacks Description: Postfix to infix conversion with stacks*********************************************************************************************/
//STACK-DRIVER.CPP DRIVER FILE
using namespace std;

int main()

{

//Declare Variables
    stack s;
    string post;

  

        // User enter the postfix expression

        cout << "Enter The Postfix Expression: " << endl;
       getline(cin, post);

      //Allow the conversion to happen
       s.conversion(post);
     

    return 0;

}
		



	

	




