//ac + bd = gcd(a, b)가 되는(c, d)를 찾는다.


#include<stdio.h>
#include<iostream>
using namespace std;

//시간복잡도 : O(log2(b))
pair<long long, long long> extended_gcd(long long a, long long b)
{
	if (!b) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a %b);
	return make_pair(t.second, t.first - t.second *(a / b));
}

int main()
{	

	return 0;
}