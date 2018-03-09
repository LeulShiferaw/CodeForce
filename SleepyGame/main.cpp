#include <stack>
#include <vector>
#include <iostream>

using namespace std;

//Typedefs
typedef stack<int> si;
typedef vector<int> vi;
typedef vector< vector<int> > vii;

//Constants
#define WIN 0
#define LOSE 1
#define DRAW 2
#define VISITED 3
#define NVISITED 4
constexpr int max_dis=10e6;

//Return back the path to win in ref
//Return back if there is path
int dfs(const vii &edges, bool status[][2][5], int curr_node, int curr_dis, si &path)
{
	//Base case 1
	if(curr_dis>=max_dis)
		return DRAW;
	else if(status[curr_node][curr_node%2][LOSE])
		return LOSE;
	else if(status[curr_node][curr_node%2][VISITED])
		return DRAW;
	else if(status[curr_node][curr_node%2][DRAW])
		return DRAW;

	if(edges[curr_node].size()==0)
	{
		if(curr_dis%2==1)//If vasya's turn 
		{
			path.push(curr_node);
			return WIN;
		}
		else 
			return LOSE;	
	}

	bool can_draw=false;//If I can draw
	status[curr_node][curr_dis%2][VISITED]=true;//Started to visit node

	//Go through all the nodes
	for(int c : edges[curr_node])
	{
		int res=dfs(edges,status,c,curr_dis+1,path);
		if(res==WIN){
			path.push(curr_node);//I only need path if i can win
			return WIN;
		}else if(res==DRAW){
			can_draw=true;
		}
	}
	status[curr_node][curr_dis%2][VISITED]=false;//Started to visit node

	if(can_draw) 
	{
		status[curr_node][curr_node%2][DRAW]=true;//Visited and drawed
		return DRAW;
	}
	status[curr_node][curr_node%2][LOSE]=true;
	return LOSE;
}

int main()
{
	int s,n,m;
	cin >> n >> m;

	vii edges(n);//n vectors containing children nodes of all n nodes
	bool status[n][2][5];
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<2; ++j)//Not visited by either players
		{
			for(int k=0; k<5; ++k)
				status[i][j][k]=false;
			status[i][j][NVISITED]=true;
		}

		int ci,temp;
		cin >> ci;
		for(int j=0; j<ci; ++j)
		{
			cin >> temp;//One of the children of node i
			edges[i].push_back(temp-1);	
		}
	}
	cin >> s;//Starting vertex

	si path;
	int res=dfs(edges,status,s-1,0,path);
	if(res==WIN)
	{
		cout << "Win" << endl;
		//Display path
		while(!path.empty())
		{
			cout << path.top()+1 << " ";
			path.pop();
		}
		cout << endl;
	}
	else if(res==LOSE) cout << "Lose" << endl;
	else cout << "Draw" << endl;

	return 0;
}
