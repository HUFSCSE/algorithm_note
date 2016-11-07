//gcd

#include<stdio.h>

//�ð����⵵ : O(log2(min(a, b)))
long long gcd(long long a, long long b)
{
	if (!b) return a;
	return gcd(b, a%b);
}

//gcd(a,b) = gcd(a, b-a)

int main()
{
	printf("%lld", gcd(2, 1024));
	
	return 0;
}


int gcd(int a, int b)
{
	//a,b�� ������ b

	//while(a*b)
	while (a && b)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}

	return a + b;
}