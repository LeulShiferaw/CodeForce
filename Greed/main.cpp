#include <iostream>

using namespace std;

int main()
{
	long long tot_col=0;
	long long max1=0, max2=0;
	
	long long n,temp;
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		cin >> temp;
		tot_col+=temp;
	}
	//Get the greatest two cups in max1 and max2 where max1>=max2
	for(int i=0; i<n; ++i)
	{
		cin >> temp;
		if(temp > max1)
		{
			max2=max1;
			max1=temp;
		}
		else if(temp > max2)
			max2=temp;
	}

	if((max1+max2)>=tot_col)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
