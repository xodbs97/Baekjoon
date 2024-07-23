#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> stk;
	int k;
	cin >> k;
	while (k--)
	{
		int n;
		cin >> n;
		if (n)
		{
			stk.push(n);
		}
		else
		{
			stk.pop();
		}
	}

	int sum = 0;
	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}

	cout << sum;

	return 0;
}
