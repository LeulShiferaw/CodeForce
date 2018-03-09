#include <string>
#include <iostream>

using namespace std;

bool find_str(const string &x, const string &y, string &z)
{
	z="";
	for(unsigned int i=0; i<x.size(); ++i)
	{
		if(x[i]<y[i]) return false;
		z+=y[i];
	}
	return true;
}

int main()
{
	string x,y,z;
	cin >> x >> y;
	if(find_str(x,y,z))
		cout << z << endl;
	else cout << -1 << endl;
	return 0;
}
