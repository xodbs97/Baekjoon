#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int i;
	int a;
	stack<int> left;
	for (i = 1; i < n; ++i)
	{
		cin >> a;
		left.push(a);
	}

	stack<int> right;
	cin >> a;
	right.push(a);

	vector<int> nge(n);
	nge[n - 1] = -1;

	for (i = n - 2; 0 <= i; --i)
	{
		int cur = left.top();
		left.pop();

		while (!right.empty() && right.top() <= cur)
		{
			right.pop();
		}

		if (right.empty())
		{
			nge[i] = -1;
		}
		else
		{
			nge[i] = right.top();
		}
		right.push(cur);
	}

	for (auto& num : nge)
	{
		cout << num << ' ';
	}

	return 0;
}