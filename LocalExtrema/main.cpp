#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int A[n];
	for(int i=0; i<n; ++i)
		cin >> A[i];

	int res=0;
	for(int i=1; i<n-1; ++i)
	{
		if((A[i]>A[i-1] && A[i]>A[i+1])||(A[i]<A[i-1]&&A[i]<A[i+1]))
			++res;
	}	
	cout << res << endl;
	return 0;
}
