#include <bits/stdc++.h>

using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx >= 2) {
		int par = idx / 2;
		if (heap[par] <= heap[idx]) break;
		swap(heap[idx], heap[par]);
		idx = par;
	}
}

int top() { // 힙에서 가장 작은 값은 heap[1]에서 가지고 있다.
	return heap[1];
}

void pop() {
	heap[1] = heap[sz--];
	int idx = 1;
	while (idx * 2 <= sz) { // 부모에게 비교할 자식이 있을 때
		int le = idx * 2;
		int ri = idx * 2 + 1;
		int mn = le;
		if (ri <= sz && heap[ri] < heap[le]) mn = ri;
		if (heap[idx] <= heap[mn]) break;
		swap(heap[idx], heap[mn]);
		idx = mn;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		if (i) push(i);
		else {
			if (sz) {
				cout << top() << "\n";
				pop();
			}
			else cout << "0\n";
		}
	}

	return 0;
}