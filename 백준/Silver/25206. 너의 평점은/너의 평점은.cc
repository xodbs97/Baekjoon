#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a = 0, b = 0;
	for (int i = 0; i < 20; ++i) {
		string t, r;
		double g;
		// 과목명, 학점, 등급
		cin >> t >> g >> r;
		if (r == "P") continue;
		b += g;
		if (r == "A+") a += g * 4.5;
		else if (r == "A0") a += g * 4.0;
		else if (r == "B+") a += g * 3.5;
		else if (r == "B0") a += g * 3.0;
		else if (r == "C+") a += g * 2.5;
		else if (r == "C0") a += g * 2.0;
		else if (r == "D+") a += g * 1.5;
		else if (r == "D0") a += g * 1.0;
	}
	cout << a / b;

	return 0;
}