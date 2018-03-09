#include <string>
#include <iostream>

using namespace std;

int num_vk(const string &str)
{
	int res=0;
	for(unsigned int i=0; i<str.size()-1; ++i)
		if(str[i]=='V' && str[i+1]=='K')
			++res;
	return res;
}

int main()
{
	string str;
	cin >> str;

	int temp;
	char temp_ch;
	int largest=num_vk(str);
	for(unsigned int i=0; i<str.size(); ++i)
	{
		temp_ch=str[i];

		if(str[i]=='V')
			str[i]='K';
		else str[i]='V';
		temp=num_vk(str);
		if(temp>largest)
			largest=temp;

		str[i]=temp_ch;
	}
	cout << largest << endl;
	return 0;
}
