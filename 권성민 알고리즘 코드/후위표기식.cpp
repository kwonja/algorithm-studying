#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	string str;
	cin >> str;
	vector<char> op;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cout << str[i];
		}
		else
		{
			if (str[i] == '+' || str[i] == '-')
			{
				while (!op.empty() && op.back() != '(')
				{
					cout << op.back();
					op.pop_back();
				}
				op.push_back(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				while (!op.empty() && (op.back() == '*' || op.back() == '/'))
				{
					cout << op.back();
					op.pop_back();
				}
				op.push_back(str[i]);
			}
			else if (str[i] == '(')
			{
				op.push_back(str[i]);
			}
			else if (str[i] == ')')
			{
				while (!op.empty() && op.back() != '(')
				{
					cout << op.back();
					op.pop_back();
				}
				op.pop_back();                  //'(' 기호 빼기
			}
		}

	}
	while (!op.empty())
	{
		cout << op.back();
		op.pop_back();
	}
	return 0;
}