#include <bits/stdc++.h>
using namespace std;

int arr[1000001], tmp[1000001];

void merge(int st, int en) {
	int mid = (st + en) / 2;
	int li = st, ri = mid;
	for (int i = st; i < en; i++) {
		if (li == mid) tmp[i] = arr[ri++];
		else if (ri == en) tmp[i] = arr[li++];
		else if (arr[li] < arr[ri]) tmp[i] = arr[li++];
		else  tmp[i] = arr[ri++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}