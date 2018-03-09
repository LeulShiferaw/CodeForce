#include <string>
#include <iostream>

using namespace std;

bool poss_palindrome(const string &str)
{
	int n_chan=0;
	unsigned int size=str.size()/2;
	for(unsigned int i=0; i<size; ++i)
	{
		if(str[i]!=str[str.size()-1-i])
		{
			if(n_chan>0)
				return false;
			++n_chan;
		}	
	}
	if(n_chan==1) return true;
	return false;
}

int main()
{
	string str;
	cin >> str;

	if(poss_palindrome(str))
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
