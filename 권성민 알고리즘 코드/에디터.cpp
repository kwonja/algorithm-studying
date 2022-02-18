#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	stack<char> l;
	stack<char> r;
	char amend;
	cin >> str;
	int n;
	for (int i = 0; i < str.length(); i++)  //처음 입력되면 커서는 맨끝에 있다.
	{
		l.push(str[i]);
	}
	//수정시작
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> amend;
		switch (amend)
		{
		case 'P':
			cin >> amend;
			l.push(amend);
			break;
		case'L':
			if (!l.empty())
			{
				r.push(l.top());
				l.pop();
			}
			break;
		case'D':
			if (!r.empty())
			{
				l.push(r.top());
				r.pop();
			}
			break;
		case'B':
			if (!l.empty())
			{
				l.pop();
			}
			break;
		}
	}
	while (!l.empty())
	{
		r.push(l.top());
		l.pop();
	}
	while (!r.empty())
	{
		cout << r.top();
		r.pop();
	}
	return 0;
}