//Book Reading
#include <queue>
#include <iostream>

using namespace std;

const int time_day=86400;

int main()
{
	int n,t,temp;
	cin >> n >> t;

	int curr=0;
	for(int i=0; i<n; ++i)
	{
		cin >> temp;
		curr+=time_day-temp;
		if(curr>=t)
		{
			cout << i+1 << endl;
			return 0;	
		}
	}

	return 0;
}
