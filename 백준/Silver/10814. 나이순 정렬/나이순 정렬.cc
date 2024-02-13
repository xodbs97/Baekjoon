#include <bits/stdc++.h>

using namespace std;

// member[나이]에는 이름들이 입력된 순서대로 push_back 된다.
vector<vector<string>> member(201, vector<string>());

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int j;
		string s;
		cin >> j >> s;
		member[j].push_back(s);
	}

	for (int age = 1; age <= 200; ++age) {
        // 가장 어린 나이부터 출력
		if (member[age].size()) {
            // 같은 나이라면 입력된 순서대로 출력
			for (string name : member[age]) cout << age << " " << name << "\n";
		}
	}

	return 0;
}