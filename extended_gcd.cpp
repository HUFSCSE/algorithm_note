//ac + bd = gcd(a, b)�� �Ǵ�(c, d)�� ã�´�.


#include<stdio.h>
#include<iostream>
using namespace std;

//�ð����⵵ : O(log2(b))
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