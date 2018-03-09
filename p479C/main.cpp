#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int temp,temp1;
	vector<pair<int,int> > exam_dates;
	for(int i=0; i<n; ++i)
	{
		cin >> temp >> temp1;
		exam_dates.push_back(pair<int,int>(temp,temp1));
	}
	sort(exam_dates.begin(),exam_dates.end());

	int latest=0;
	for(unsigned int i=0; i<exam_dates.size(); ++i)
	{
		if(min(exam_dates[i].first,exam_dates[i].second)>=latest)
			latest=min(exam_dates[i].first,exam_dates[i].second);
		else latest=max(exam_dates[i].first,exam_dates[i].second);
	}
	cout << latest << endl;			
	return 0;
}
