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
	vector<ll> arr;
	ll n, k, input;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input - k > 0)
			arr.push_back(input - k);
		else
			arr.push_back(k - input);
	}
	ll ans = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (ans > arr[i])
			ans = func(ans, arr[i]);
		else
			ans = func(arr[i], ans);
	}
	cout << ans;
	return 0;
}
