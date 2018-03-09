#include <iostream>

using namespace std;

int main()
{
	int n, temp;
	cin >> n;

	int p1=1, p2=2, sp=3;
	while(n--)
	{
		cin >> temp;
		if(temp==p1)
			swap(p2,sp);
		else if(temp==p2)
			swap(p1,sp);
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}	
	cout << "YES" << endl;
	return 0;
}
