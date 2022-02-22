#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b, c, d, e, f;
	cin >> a >> b >> c >> d;
	e = a + b;
	f = c + d;
	long long result = stoll(e) + stoll(f);
	cout << result;
	return 0;
	//이어붙이고 나면 그 수가 엄청 커진다
}