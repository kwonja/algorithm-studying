#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')continue;
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 13;
			if (str[i] < 'A')
			{
				str[i] = str[i] + 26;
			}
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 13;
			if (str[i] < 'a')
			{
				str[i] = (str[i] + 26);
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')continue;
	}
	cout << str;
	return 0;
}