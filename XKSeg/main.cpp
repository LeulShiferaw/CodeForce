#include <iostream>
#include <algorithm>

using namespace std;

//Global variables
int freq=0;
long long k,x,v;
long long res=0;

//Number of elements in [ai,aj] divisible by x
long long num_div(const long long &ai, const long long &aj)
{
	return max(0ll,((long long)(aj/x)-(long long)((ai-1ll)/x)));//<=aj - <ai
}

void solve(long long A[], const int &s, const int &e)
{
	//Base case
	if(e==s+1)
	{
		return;
	}

	int m=(s+e)/2;
	if(num_div(v,A[m])==k)
	{
		res+=2-(A[m]!=v);
		if(m+1!=e)
			solve(A,m+1,e);
		if(m!=s)
			solve(A,s,m);
	}
	else if(num_div(v,A[m])<k)
	{
		if(m+1==e)
			return;
		solve(A,m+1,e);
	}
	else
	{
		if(m==s)
			return;
		solve(A,s,m);
	}
}

int main()
{
	int n;
	cin >> n >> x >> k;
	
	long long A[n+5];
	for(int i=0; i<n; ++i)
		cin >> A[i];
	sort(A,A+n);
	for(int i=0; i<n; ++i)
	{
		v=A[i];
		for(int j=i+1; j<n; ++j)
		{
			if(A[j]==A[i])
			{
				res+=(num_div(A[j],A[i])==k);
				++i;
			}
			else break;
		}
		solve(A,i,n);
	}
	cout << res << endl;
	return 0;
}
