#include<iostream>
#include<vector>

using namespace std;
int main()
{
	vector <int> dict(256,-1);
	int i;
	cout << dict.size() << endl;
	for(i = 0;i != dict.size();i++)
	cout << dict[i] << ',';
	
	
	return 0;
}
