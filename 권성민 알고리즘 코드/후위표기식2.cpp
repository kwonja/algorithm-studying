#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	double a, b;
	int input;
	vector<double> arr;
	string str;
	int k = 0;
	stack<double> temp;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			temp.push(arr[int(str[i] - 'A')]);
		}
		else
		{
			a = temp.top();
			temp.pop();
			b = temp.top();
			temp.pop();
			switch (str[i])
			{
			case '+':
				temp.push(a + b);
				break;
			case '-':
				temp.push(b - a);
				break;
			case '*':
				temp.push(a * b);
				break;
			case '/':
				temp.push(b / a);
				break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << temp.top();
	return 0;
}