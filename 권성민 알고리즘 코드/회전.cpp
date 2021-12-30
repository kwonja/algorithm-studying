#include <cstring>
#include <deque>
#include <iostream>
#include<cmath>
using namespace std;

int main(void)
{
	deque<char> a;
	char arr[10];
	long long sum = 0;
	cin >> arr;

	for (int i = 0; i < strlen(arr); i++)
	{
		a.push_back(arr[i]);
	}
	for (int i = 0; i < a.size(); i++)
	{
		a.push_front(a.back());
		a.pop_back();
		for (int j = 0; j < a.size(); j++)
		{
			sum = sum + (((int)a[(a.size() - 1) - j] - 48) * pow(10, j));
		}
	}
	cout << sum << endl;
	return 0;
}