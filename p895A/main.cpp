#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int tot_sum=0;
	int A[n+5];
	for(int i=0; i<n; ++i)
	{
		cin >> A[i];
		tot_sum+=A[i];
	}

	int sum1=0;
	int min_diff=tot_sum;
	for(int i=0; i<n-1; ++i)
	{
		sum1=A[i];
		for(int j=i+1; j<n; ++j)
		{
			if(abs(tot_sum-2*sum1)<min_diff)//sum-sum1 gives one half sum1 gives the other
				min_diff=abs(tot_sum-2*sum1);
			sum1+=A[j];
		}
	}
	cout << min_diff << endl;
	return 0;
}
