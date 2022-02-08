#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	int n, k;
	cin >> n; cin >> k;
	deque<int> arr;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}
	cout << "<";
	while (!arr.empty())
	{
		if (arr.size() == 1)break;
		for (int i = 0; i < k - 1; i++)
		{
			arr.push_back(arr.front());
			arr.pop_front();
		}
		cout << arr.front() << ", ";
		arr.pop_front();
	}
	cout << arr.front() << ">" << endl;
	return 0;
}