#include<vector>
#include <stack>
using namespace std;
int main()
{
	int n, input;
	vector<int> arr;
	vector<int> s;
	stack<int> answer;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	for (int i = n - 1; i > -1; i--)
	{
		while (!s.empty() && s.back() <= arr[i])s.pop_back();
		if (s.empty())answer.push(-1);
		else answer.push(s.back());
		s.push_back(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << answer.top() << " ";
		answer.pop();
	}
	return 0;
}