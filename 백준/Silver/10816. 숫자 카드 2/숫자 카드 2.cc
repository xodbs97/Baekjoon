#include <bits/stdc++.h>
using namespace std;

// card[0] = -10 000 000, card[10 000 000] = 0, card[20 000 000] = 10 000 000
int card[20000005]; 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	stringstream ss;
	ss.str(s);
	while (ss >> n) ++card[n + 10000000];
	ss.clear();

	cin >> n;
	getline(cin, s);
	getline(cin, s);
	ss.str(s);
	while (ss >> n) cout << card[n + 10000000] << " ";

	return 0;
}