#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	stack<int> arr;
	int n, input;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> input;
			arr.push(input);
			continue;
		}
		if (str == "pop")
		{
			if (arr.size() == 0)
			{
				cout << -1 << endl;
				continue;
			}
			cout << arr.top() << endl;
			arr.pop();
			continue;
		}
		if (str == "size")
		{
			cout << arr.size() << endl;
			continue;
		}
		if (str == "empty")
		{
			cout << arr.empty() << endl;
			continue;
		}
		if (str == "top")
		{
			if (arr.size() == 0)
			{
				cout << -1 << endl;
				continue;
			}
			cout << arr.top() << endl;
			continue;
		}
	}
	return 0;
}