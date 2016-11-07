//ax = gcd(a, m) (mod m)가 되는 x를 찾는다.

#include<stdio.h>
#include<iostream>
using namespace std;

pair<long long, long long> extended_gcd(long long a, long long b)
{
	if (!b) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a %b);
	return make_pair(t.second, t.first - t.second *(a / b));
}

long long modInverse(long long a, long long m)
{
	return (extended_gcd(a, m).first %m + m) % m;
}

int main()
{

	printf("%lld", modInverse(3, 7));

	return 0;
}