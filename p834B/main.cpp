#include <string>
#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	
	string str;
	cin >> str;	

	int number_guest[26];
	bool has_guard[26];

	for(int i=0; i<26; ++i)
	{
		number_guest[i]=0;
		has_guard[i]=false;
	}

	for(unsigned int i=0; i<str.size(); ++i)
	{
		++number_guest[str[i]-'A'];
	}

	int n_guards=0;
	for(unsigned int i=0; i<str.size(); ++i)
	{
		--number_guest[str[i]-'A'];
		if(!has_guard[str[i]-'A'] && n_guards==k)
		{
			cout << "YES" << endl;
			return 0;
		}	
		else if(!has_guard[str[i]-'A'])
		{
			++n_guards;
			has_guard[str[i]-'A']=true;
		}

		if(has_guard[str[i]-'A']&&number_guest[str[i]-'A']<=0)
		{
			has_guard[str[i]-'A']=false;
			--n_guards;
		}
	}

	cout << "NO" << endl;
	return 0;
}
