#include <iostream>
#include <stack>
using namespace std;
int main()
{
	string str;
	int left = 0;
	int answer = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')' && str[i - 1] == '(') //레이저
		{
			left--;
			answer += left;
		}
		else if (str[i] == '(')
		{
			left++;  //막대개수
		}
		else if (str[i] == ')' && str[i - 1] != '(') //막대 끝
		{
			answer++; //막대 꽁다리
			left--;   //막대가 하나 빠짐
		}
	}
	cout << answer << endl;
	return 0;
}