//유클리드 호제법으로 최대공약수,최소공배수 구하기
#include <stdio.h>
int func1(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	if (n > k)
	{
		printf("%d\n", func1(n, k));
		printf("%d\n", n*k / func1(n, k));

	}
	else
	{
		printf("%d\n", func1(k, n));
		printf("%d\n", n*k / func1(k, n));
	}
	return 0;
}