#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
int cnt;
int n;
int colums[15];
bool check(int new_row) {
	int current_row = 0;
	bool c = false;
	while (current_row < new_row) {
		if (colums[new_row] == colums[current_row]
			|| abs(colums[new_row] - colums[current_row])
			== abs(new_row - current_row)) {
			c = true;
			break;
		}
		current_row += 1;
	}
	return c;
}
void find(int row) {
	if (check(row)) //°ãÄ¡¸é Á¾·á
		return;
	if (row == n - 1) 
		cnt += 1;
	else {
		for (int i = 0; i < n; i++) {
			colums[row + 1] = i;
			find(row + 1);
		}
	}
}
int main() {
	//N-Queen
	//https://www.acmicpc.net/problem/9663
	cin >> n;
	for (int i = 0; i < n; i++) {
		colums[0] = i;
		find(0);
	}
	cout << cnt << "\n";
	return 0;
}