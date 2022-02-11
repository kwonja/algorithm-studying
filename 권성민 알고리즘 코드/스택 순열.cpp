#include <iostream>
#include <string>
#include <stack>
#include<vector>
using namespace std;
int main()
{
	int n, input, cnt = 0;
	vector<char> arr;
	vector<int> p;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		p.push_back(input);
	}
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		arr.push_back('+');
		while (!v.empty() && v.back() == p[cnt])
		{
			v.pop_back();
			arr.push_back('-');
			cnt++;
		}
	}
	if (!v.empty())
	{
		cout << "NO" << endl;
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << '\n';
		}
	}
	return 0;
}