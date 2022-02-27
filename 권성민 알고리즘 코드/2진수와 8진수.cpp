// 8->2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	string str;
	string ans;
	long long a;
	char temp;
	cin >> str;
	if (str == "0")
	{
		cout << str;
		return 0;
	}
	for (int i = 0; i < str.length(); i++)
	{
		a = (int)(str[i]) - 48;
		ans += to_string(a / 4);
		ans += to_string(a % 4 / 2);
		ans += to_string(a % 4 % 2);
	}
	bool flag = false;
	for (int i = 0; i < ans.length(); i++)
	{
		if (!flag)
		{
			if (ans[i] == '1')
			{
				flag = true;
				cout << ans[i];
			}
		}
		else
		{
			cout << ans[i];
		}
	}
	return 0;
}

//  2->8
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	string str;
	string answer;
	long long k = 1;
	int count = 0;
	long long ans = 0;
	cin >> str;
	for (int i = str.length() - 1; i > -1; i--)
	{
		count++;
		if (str[i] == '1')
		{
			ans += k;
		}
		k = k * 2;
		if (count % 3 == 0)
		{
			answer += to_string(ans);
			ans = 0;
			k = 1;
		}
	}
	if (count % 3 != 0)answer += to_string(ans);
	for (int i = answer.length() - 1; i > -1; i--)
	{
		cout << answer[i];
	}
	return 0;
}