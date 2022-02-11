#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	int n, count;
	string str;
	queue<char> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			arr.push(str[i]);
		}
		while (!arr.empty())
		{
			if (arr.front() == '(')
			{
				count++;
				arr.pop();
			}
			else if (arr.front() == ')')
			{
				count--;
				arr.pop();
				if (count < 0) //count가 음수면 ')' 개수가 더 많다는 의미
					break;
			}
		}
		while (!arr.empty())
		{
			arr.pop();
		}
		if (count == 0)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}