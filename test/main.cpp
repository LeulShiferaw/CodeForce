#include <iostream>

using namespace std;

bool find(int v, int arr[])
{
	for(int i=0; i<6; ++i)
		if(arr[i]==v)
			return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	int dice[n][6];

	for(int i=0; i<n; ++i)
		for(int j=0; j<6; ++j)
			cin >> dice[i][j];

	int max=0;

	if(n==1)
	{
		//One digit
		for(int i=1; i<10; ++i)
		{
			if(find(i,dice[0]))
			{
				max=i;
			}
			else
			{
				cout << max << endl;
				return 0;
			}
		}
	}

	if(n==2)
	{
		//One digit
		for(int i=1; i<10; ++i)
		{
			if(find(i,dice[0])||find(i,dice[1]))
			{
				max=i;
			}
			else
			{
				cout << max << endl;
				return 0;
			}
		}
		//Two digit
		for(int i=1; i<10; ++i)
		{
			for(int j=0; j<10; ++j)
			{
				if((find(i,dice[0])&&find(j,dice[1]))||(find(i,dice[1])&&find(j,dice[0])))
				{
					max=i*10+j;
				}
				else
				{
					cout << max << endl;
					return 0;
				}
			}
		}
	}

	if(n==3)
	{
		//One digit
		for(int i=1; i<10; ++i)
		{
			if(find(i,dice[0])||find(i,dice[1])||find(i,dice[2]))
			{
				max=i;
			}
			else
			{
				cout << max << endl;
				return 0;
			}
		}
		//Two digit
		for(int i=1; i<10; ++i)
		{
			for(int j=0; j<10; ++j)
			{
				if((find(i,dice[0])&&find(j,dice[1]))||(find(i,dice[0])&&find(j,dice[2]))||(find(i,dice[1])&&find(j,dice[0]))||(find(i,dice[1])&&find(j,dice[2]))||(find(i,dice[2])&&find(j,dice[0]))||(find(i,dice[2])&&find(j,dice[1])))
				{
					max=i*10+j;
				}
				else
				{
					cout << max << endl;
					return 0;
				}
			}
		}
		//Three digit
		for(int i=1; i<10; ++i)
		{
			for(int j=0; j<10; ++j)
			{
				for(int k=0; k<10; ++k)
				{
					if((find(i,dice[0])&&find(j,dice[1])&&find(k,dice[2]))||(find(i,dice[0])&&find(j,dice[2])&&find(k,dice[1]))||(find(i,dice[1])&&find(j,dice[0])&&find(k,dice[2]))||(find(i,dice[1])&&find(j,dice[2])&&find(k,dice[0]))||(find(i,dice[2])&&find(j,dice[0])&&find(k,dice[1]))||(find(i,dice[2])&&find(j,dice[1])&&find(k,dice[0])))
					{
						max=i*100+j*10+k;
					}
					else
					{
						cout << max << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}
