#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	int p, pi = 0;
	vector<int> arr;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end()); //기본 오름차순 정렬
	for (int i = 0; i < n; i++)
	{
		pi = pi + arr[i];
		sum += pi;
	}
	cout << sum << endl;

	return 0;
}