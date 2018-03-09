#include <iostream>

using namespace std;

int main()
{
	bool cw=false;

	char spinner[4];
	spinner[0]='v';
	spinner[1]='<';
	spinner[2]='^';
	spinner[3]='>';
	
	char s,e;
	cin >> s >> e;

	int n;
	if(s=='v')n=0;
	else if(s=='<')n=1;
	else if(s=='^')n=2;
	else if(s=='>')n=3;
	
	int temp;
	cin >> temp;

	n+=temp%4;
	n%=4;

	if(spinner[n]==e)
	{
		cw=true;
	}

	spinner[0]='v';
	spinner[1]='>';
	spinner[2]='^';
	spinner[3]='<';
	
	if(s=='v')n=0;
	else if(s=='>')n=1;
	else if(s=='^')n=2;
	else if(s=='<')n=3;
	
	n+=temp%4;
	n%=4;

	if(spinner[n]==e)
	{
		if(cw) cout << "undefined" << endl;
		else cout << "ccw" << endl;
	}
	else cout << "cw" << endl;
	return 0;
}
