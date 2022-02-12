#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	stack<char> arr;
	int cnt = 0;
	string str;
	getline(cin, str);
	for (int i = 0; i <= str.length(); i++)
	{
		if (cnt == 0)
		{
			if (str[i] == '<')
			{
				while (1)
				{
					cout << str[i];
					if (str[i] == '>')
					{
						i++;
						break;
					}
					i++;
				}
			}
		}
		if (str[i] == ' ' || str[i] == NULL || str[i] == '<')
		{
			while (!arr.empty())
			{
				cout << arr.top();
				arr.pop();
			}
			if (str[i] == ' ')cout << " ";
			if (str[i] == '<')i--;
			cnt = 0;
			continue;
		}
		arr.push(str[i]);
		cnt = 1;
	}
	return 0;
}