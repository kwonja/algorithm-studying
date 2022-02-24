#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void)
{
	ll count[2] = { 0, };
	ll n, m;
	cin >> n >> m;
	//2의 배수
	for (ll i = 2; i <= n; i = i * 2)
	{
		count[0] += (n / i);
	}
	for (ll i = 2; i <= (n - m); i = i * 2)
	{
		count[0] -= ((n-m) / i);
	}
	for (ll i = 2; i <= m; i = i * 2)
	{
		count[0] -= (m / i);
	}
	//5의 배수
	for (ll i = 5; i <= n; i = i * 5)
	{
			count[1] += (n / i);
	}
	for (ll i = 5; i <= m; i = i * 5)
	{
			count[1] -= (m / i);
	}
	for (ll i = 5; i <= (n-m); i = i * 5)
	{
			count[1] -= ((n-m) / i);
	}
	cout << min(count[0], count[1]);
	return 0;
}
