//gcd

#include<stdio.h>

//시간복잡도 : O(log2(min(a, b)))
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
	//a,b중 작은수 b

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