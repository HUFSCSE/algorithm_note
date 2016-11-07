//오일러 피 함수
// 1부터 n까지 양의 정수중에 n과 서로소인 것의 갯수
//1, 2, 3, 4, 5, 6 중에, 6과 서로소인 수는 1, 5 두 개이다. 따라서, φ(6) = 2

#include<stdio.h>

long long euler_totient2(long long n, long long ps)
{
	for (long long i = ps; i * i <= n; i++) {
		if (n % i == 0) {
			long long p = 1;
			while (n % i == 0) {
				n /= i;
				p *= i;
			}
			return (p - p / i) * euler_totient2(n, i + 1);
		}
		if (i > 2) i++;
	}
	return n - 1;
}

long long euler_totient(long long n) {
	return euler_totient2(n, 2);
}

int main()
{
	printf("%lld", euler_totient(6));

	return 0;
}