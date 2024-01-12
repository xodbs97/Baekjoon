#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	stack<int> s;

	int n = 1, sum = 0;
	bool  can_add = false;
	for (char c : str) {
		bool open = (c == '(' || c == '[') ? true : false;
		if (open) {
			int i = c == '(' ? 2 : 3;
			s.push(i);
			n *= i;
			can_add = true;
		}
		else {
			int i = c == ')' ? 2 : 3;
			if (s.empty() || s.top() != i) {
				cout << 0;
                
				return 0;
			}
			s.pop();
			if (can_add) sum += n;
			n /= i;
			can_add = false;
		}
	}
	if (s.size()) sum = 0;
	cout << sum;
    
	return 0;
}
