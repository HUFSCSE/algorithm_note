//n^k mod m을 구한다.

#include<stdio.h>
#define LLONG_MAX 1000000000

//시간복잡도 : O(log2(k))
long long power(long long n, long long k, long long m = LLONG_MAX)
{
	long long ret = 1;

	while (k)
	{
		long long a = k & 1;
		if (a) ret = (ret*n) % m;
		n = (n*n) % m;
		k >>= 1;
	}

	return ret;
}

int main()
{

	return 0;
}