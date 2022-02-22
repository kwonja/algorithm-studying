#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, temp;
	string str1[1001];
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i; j < str.length(); j++)
		{
			str1[i] += str[j];
		}
	}
	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str1[i] > str1[j])
			{
				temp = str1[j];
				str1[j] = str1[i];
				str1[i] = temp;
			}
		}
	}
	//알파벳의 사전은 크기순!!!!
	for (int i = 0; i < str.length(); i++)
	{
		cout << str1[i] << endl;
	}
}