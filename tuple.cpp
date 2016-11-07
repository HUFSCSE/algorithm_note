#include<iostream>
#include<tuple>
using namespace std;
int main() {
	tuple<int, int, int> x;
	x = make_tuple(1, 2, 3);
	tuple<int, int, int, int>y(1, 2, 3, 4);
	cout << get<0>(x) << get<1>(x) << get<2>(x) << endl;
	//for (int i = 0; i < 3; ++i)cout << get<i>(x); ---º¯¼ö ¸ø¾¸
	cout << get<0>(y) << get<1>(y) << get<2>(y) <<get<3>(y)<< endl;

	return 0;
}