#include <bits/stdc++.h>

using namespace std;

bool check666(string s) {
	return s.find("666") != string::npos ? true : false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int repeat = 0;
	int num = 666;
	while (repeat < n) {
		string numstr = to_string(num);
		if (check666(numstr)) {
			++repeat;
		}
		++num;
	}
	cout << num - 1;

	return 0;
}