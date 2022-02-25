#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll func(ll a, ll b)
{
	long long temp;
	temp = 1;
	while (temp)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main(void)
{
	int n, input;
	long long num, sum;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		vector<long long> arr;
		for (int j = 0; j < input; j++)
		{
			cin >> num;
			arr.push_back(num);
		}
		sum = 0;
		for (int j = 0; j < input; j++)
		{
			for (int k = j + 1; k < input; k++)
			{
				if (arr[j] > arr[k])
					sum += func(arr[j], arr[k]);
				else
					sum += func(arr[k], arr[j]);
			}
		}
		cout << sum << endl;
	}


	return 0;
}
