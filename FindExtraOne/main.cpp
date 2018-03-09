#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int x,y;
	int l=0,r=0;
	for(int i=0; i<n; ++i)
	{
		cin >> x >> y;
		if(x==0)++l,++r;
		else if(x>0)++r;
		else if(x<0)++l;	
	}
	int res=l-r;
	if(res<0)res=-res;
	if(res==0||res==1)
		cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
}
