#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,d;
	cin >> n >> d;
	
	int A[n+5];
	for(int i=0; i<n; ++i)
		cin >> A[i];
	sort(A,A+n);

	if(n==1)
	{
		cout << 0 << endl;
		return 0;
	}

	int l=0,r=1;
	int max_size=1;
	while(1)
	{
		if(A[r]-A[l]>d) ++l;
		else if(r<n-1)max_size=max(max_size,r-l+1),++r;
		else break;
	}
	max_size=max(max_size,r-l+1);
	cout << n-max_size << endl;
	return 0;

}
