#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	vector<int> arr;
	vector<pair<int, int>> f;

	vector<pair<int, int>> s;
	vector<int> ans;
	int count[1000001] = { 0, };
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		count[input]++;
		arr.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		f.push_back(make_pair(arr[i], count[arr[i]]));
	}
	for (int i = n - 1; i > -1; i--)
	{
		while (!s.empty() && f[i].second >= s.back().second)
		{
			s.pop_back();
		}
		if (s.empty()) ans.push_back(-1);
		else
			ans.push_back(s.back().first);

		s.push_back(make_pair(f[i].first, f[i].second));
	}
	for (int i = n - 1; i > -1; i--)
	{
		cout << ans[i] << " ";
	}
	return 0;
}