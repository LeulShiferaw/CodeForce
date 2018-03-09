#include <iostream>

using namespace std;

int min(const int &a, const int &b)
{
	if(a<b)return a;
	return b;
}
int max(const int &a, const  int &b)
{
	if(a>b)return a;
	return b;
}

int main()
{
	int n;
	cin >> n;

	int A[n+5];
	int alive=n;
	for(int i=0; i<n; ++i)
		cin >> A[i];
	int l=n-2;//Last alive element besides A[n-1]
	for(int i=n-1; i>0; --i)
	{
		l=min(l,i-1);//l < i
		alive-=max(0,l-max(0,i-A[i])+1);//max(0, size of [l,i-A[i]])
		l=max(-1,min(l,i-A[i]-1));//pos of l should be i-A[i]-1 if l > than it. -1 is the end
		if(l<=-1)break;//No more alive elements
	}
	cout << alive << endl;
	return 0;
}
