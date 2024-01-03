#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[26];
	fill(a, a + 26, 0);
	string s;
	cin >> s;
	for (auto c : s) {
		a[(int)(c - 'a')]++;
	}
	for (auto i : a) {
		cout << i << ' ';
	}


	return 0;
}