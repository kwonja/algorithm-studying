#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> arr;
	int n, k;
	int count = 0;
	cin >> n >> k;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		count += (k / arr[i]);
		k = k % arr[i];
		if (k == 0)break;
	}
	cout << count;
	return 0;
}