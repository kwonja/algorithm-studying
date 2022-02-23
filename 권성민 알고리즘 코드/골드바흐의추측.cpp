#include <iostream>
#include <cmath>
using namespace std;
int arr[1000001] = { 1,1, };
void func1()
{
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		for (int j = i + i; j <= 1000000; j = j + i)
		{
			arr[j] = 1; //배수
		}
	}
}
int main()
{
	func1();
	bool check = 0;
	int input;
	//cin 입력에 시간을 줄여준다.
	while (1)
	{
		check = 0;
		scanf("%d", &input);
		if (input == 0)break;
		for (int i = 3; i <= (input) / 2; i = i + 2)
		{
			if ((arr[i] == 0) && (arr[input - i] == 0))
			{
				check = 1;
				printf("%d = %d + %d\n", input, i, input - i);
				break;
			}
		}
		if (check == 0)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
	}
	return 0;
}