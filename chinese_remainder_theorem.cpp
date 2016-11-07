//#include<stdio.h>
//#include<iostream>
//using namespace std;
//
//long long gcd(long long a, long long b)
//{
//	if (!b) return a;
//	return gcd(b, a%b);
//}
//
//pair<long long, long long> extended_gcd(long long a, long long b)
//{
//	if (!b) return make_pair(1, 0);
//	pair<long long, long long> t = extended_gcd(b, a %b);
//	return make_pair(t.second, t.first - t.second *(a / b));
//}
//
//long long modInverse(long long a, long long m)
//{
//	return (extended_gcd(a, m).first %m + m) % m;
//}
//
//long long chinese_remainder(long long *a, long long *n, int size)
//{
//	if (size == 1) return *a;
//	long long temp = modInverse(n[0], n[1]);
//	long long temp2 = (temp * (a[1] - a[0]) % n[1] + n[1]) % n[1];
//	long long ora = a[1];
//	long long tgcd = gcd(n[0], n[1]);
//
//	a[1] = a[0] + n[0] / tgcd * temp2;
//	n[1] *= n[0] / tgcd;
//	long long ret = chinese_remainder(a + 1, n - 1, size - 1);
//	n[1] /= n[0] / tgcd;
//	a[1] = ora;
//	return ret;
//}
//
//int main()
//{
//
//	return 0;
//}