//catalan number
//1 - 2- 5 - 14 - 42 - 132 - 429
//°ø½Ä : (2n)! / n!(n+1)!

#include<stdio.h>

long long binomial(int n, int m)
{
	if (n < m || n < 0) return 0;
	long long ans = 1, ans2 = 1;

	for (int i = 0; i < m; i++)
	{
		ans *= n - i;
		ans2 *= i + 1;
	}
	return ans / ans2;
}

long long catalan_number(int n)
{
	return binomial(2 * n, n) / (n + 1);
}

int main()
{
	printf("%lld", catalan_number(7));

	return 0;
}