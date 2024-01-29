#include <bits/stdc++.h>
using namespace std;

int bs(const vector<int>& v, int num) {
	int le = 0, ri = (int)v.size();
	while (le <= ri) {
		int mid = (le + ri) / 2;
		if (v[mid] > num) ri = mid - 1;
		else if (v[mid] < num)le = mid + 1;
		else return mid;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> original(n);
	for (int i = 0; i < n; i++) cin >> original[i];
    
	vector<int> sorted = original;
	sort(sorted.begin(), sorted.end());
    
	vector<int> unique;
	unique.push_back(sorted[0]);
	for (int i = 1; i < n; i++) {
		if (sorted[i] == unique[unique.size() - 1]) continue;
		else unique.push_back(sorted[i]);
	}
	for (int i : original) cout << bs(unique, i) << " ";
    
	return 0;
}