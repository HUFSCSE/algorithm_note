//nCm % p 를 구한다
//n,m은 문자열로 주어지는 정수, p는소수
//http://bowbowbow.tistory.com/2

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

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

int lucas_theorem(const char *n, const char *m, int p)
{
	vector<int> np, mp;
	int i;
	for (i = 0; n[i]; i++)
	{
		if (n[i] == '0' && np.empty()) 
			continue;
		np.push_back(n[i] - '0');
	}

	for (i = 0; m[i]; i++)
	{
		if (m[i] == '0' && mp.empty())
			continue;
		mp.push_back(m[i] - '0');
	}

	int ret = 1;
	int ni = 0, mi = 0;
	while (ni < np.size() || mi < mp.size())
	{
		int nmod = 0, mmod = 0;
		for (i = ni; i < np.size(); i++)
		{
			if (i + 1 < np.size())
				np[i + 1] += (np[i] % p) * 10;
			else
				nmod = np[i] % p;
			np[i] /= p;
		}

		for (i = mi; i < mp.size(); i++)
		{
			if (i + 1 < mp.size())
				mp[i + 1] += (mp[i] % p) * 10;
			else
				mmod = mp[i] % p;
			mp[i] /= p;
		}
		while (ni < np.size() && np[ni] == 0) 
			ni++;
		while (mi < mp.size() && mp[mi] == 0) 
			mi++;

		ret = (ret*binomial(nmod, mmod)) % p;
	}
	return ret;
}

int main()
{
	char a[20], b[20];
	strcpy(a, "30");
	strcpy(b, "3");

	lucas_theorem(a, b, 3);

	return 0;
}



