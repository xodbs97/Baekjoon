#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 사전 준비
	map<string, int> mp;

	int n, m;
	cin >> n >> m;

	// 입력 및 수정부
	while (n--) {
		string s;
		cin >> s;
		// 기준치 이하의 단어는 저장하지 않음
		if (s.size() < m) continue;
		// 처음 나오는 단어라면 map에 삽입함
		if (mp.find(s) == mp.end()) mp.insert({ s,1 });
		// 내부에 단어가 이미 존재한다면 출현 횟수를 1 증가시킴
		else ++mp[s];
	}

	// 정렬부
	// 정렬을 위해 pair 형태의 map의 데이터를 vector<pair<string, int>> 형태의 벡터에 옮김
	vector<pair<string, int>> v;
	for (const auto& p : mp) v.push_back(p);
	// 비교 함수를 사용하여 정렬함
	sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
		// 최우선으로 빈도수로 정렬함
		if (a.second != b.second) return a.second > b.second;
		// 차선으로 문자열의 길이가 긴 순서대로 정렬함
		if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
		// 마지막으로 사전순으로 정렬함
		return a.first < b.first;
		});

	// 출력부
	for (const auto& p : v) cout << p.first << "\n";

	return 0;
}