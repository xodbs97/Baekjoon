#include <bits/stdc++.h>

using namespace std;

vector<int> arr, copyOrder;

void mergeFunc(int p, int q, int r) {
	vector<int> tmp;

	int le = p, ri = q + 1;
	while (true) {
		if (le > q && ri > r) break;

		if (le > q) tmp.push_back(arr[ri++]);
		else if (ri > r) tmp.push_back(arr[le++]);
		else if (arr[le] > arr[ri]) tmp.push_back(arr[ri++]);
		else tmp.push_back(arr[le++]);
	}

	int idx = p;
	for (int num : tmp) {
		copyOrder.push_back(num);
		arr[p++] = num;
	}
}

void mergeSort(int p, int r) {
	if (p == r) return;

	int q = (p + r) / 2;
	mergeSort(p, q);
	mergeSort(q + 1, r);

	mergeFunc(p, q, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	arr.reserve(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	mergeSort(0, n - 1);

	cout << ((int)copyOrder.size() < k ? -1 : copyOrder[k - 1]);

	return 0;
}