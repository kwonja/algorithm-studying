#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector <long long> arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(i);
	}
	int n;
	cin >> n;
	if (n > 1022)
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < (arr[i] % 10); j++)
		{
			arr.push_back(arr[i] * 10 + j);
		}
	}
	cout << arr[n];
	return 0;
}