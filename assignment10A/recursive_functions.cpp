#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string& s);
string  printReversel(const string& s){return s;};
string printIterReverse(const string& s){return s;};



bool palindrome(const string& s) 
{
	int first =0;
  int last = s.length() - 1;
	if (s.length() <= 1)
	{
		return true;
	}
	else
	{
	
			if (s[first] != s[last])
			{
				return false;
			}
		else
			{
				return palindrome(s.substr(++first,--last));
			}

		}
    
	}


int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
