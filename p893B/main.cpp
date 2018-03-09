#include <iostream>
#include <math.h>

using namespace std;

bool is_beautiful(int x)
{
	int k_2=2;//2^k
	int n=log2(x)+1;//max power
	for(int k=1; k<=n; ++k,k_2*=2)
		if(x==((k_2-1)*(k_2/2))) return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	for(int i=n; i>0; --i)
	{
		if(!(n%i) && is_beautiful(i)) {
			cout << i << endl;
		       	break;
		}
	}

	return 0;
}
