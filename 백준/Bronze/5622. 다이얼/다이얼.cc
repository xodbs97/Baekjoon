#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int ans = 0;
	for (char c : str) {
		if (c <= 'C') ans += 3;
		else if (c <= 'F') ans += 4;
		else if (c <= 'I') ans += 5;
		else if (c <= 'L') ans += 6;
		else if (c <= 'O') ans += 7;
		else if (c <= 'S') ans += 8;
		else if (c <= 'V') ans += 9;
		else if (c <= 'Z') ans += 10;
	}
	cout << ans;
    
	return 0;
}