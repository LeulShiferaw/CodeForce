#include <iostream>

using namespace std;

int main()
{
	int n,d;
	cin >> n >> d;

	char A[n+5]; //Lilly or not binary code
	for(int i=0; i<n; ++i)
		cin >> A[i];

	int s=0;//Start index,current index
	int ans=0;
	while(true)
	{
		if(s==n-1)//Base case, end case
		{
			cout << ans << endl;
			return 0;
		}

		for(int i=min(n-1, s+d); i>s; --i)//Start from buffer end
		{
			if(A[i]=='1')//If lilly
			{
				s=i;//Go to lilly
				ans++;//Increment jump
				break;
			}
			else if(i==s+1)//Else if no jump possible
			{
				cout << -1 << endl;//End
				return 0;
			}
		}
	}
	return 0;
}
