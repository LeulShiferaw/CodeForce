#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int res=0;
	int numq=0;
	vector<int> numq_a;//Number of q before A
	for(unsigned int i=0; i<s.size(); ++i)
	{
		if(s[i]=='Q')
		{
			for(unsigned int j=0; j<numq_a.size(); ++j)
			{
				res+=numq_a[j];
			}
			++numq;
		}
		else if(s[i]=='A')
		{
			numq_a.push_back(numq);
		}
	}	
	cout << res << endl;
	return 0;
}
