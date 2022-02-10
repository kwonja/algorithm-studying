#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	stack<char> arr;
	int n;
	cin >> n;
	cin.ignore();
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		for (int i = 0; i <= str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == NULL)
			{
				while (!arr.empty())
				{
					cout << arr.top();
					arr.pop();
				}
				if (str[i] != NULL)cout << " ";
				continue;
			}
			arr.push(str[i]);
		}
		cout << endl;
	}
	return 0;
	//cin.ignore();는 버퍼 전체를 비우는것이 아니라 맨 앞의 문자하나를 지운다.
}