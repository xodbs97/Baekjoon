#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int k;
	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}

	vector<int> dot(100001, -1);
	vector<bool> checked(100001, false);

	queue<int> q;
	q.push(n);
	dot[n] = 0;

	bool repeat;
	int cur;
	while (!q.empty() && dot[k] == -1)
	{
		cur = q.front();
		q.pop();
		if (checked[cur])
		{
			continue;
		}
		checked[cur] = true;

		repeat = true;
		do
		{
			if (cur == 0 || 100000 < cur * 2 || checked[cur * 2])
			{
				repeat = false;
			}
			else if (dot[cur * 2] == -1 || dot[cur] < dot[cur * 2])
			{
				dot[cur * 2] = dot[cur];
				checked[cur * 2] = true;
			}

			if (cur && dot[cur - 1] == -1)
			{
				q.push(cur - 1);
				dot[cur - 1] = dot[cur] + 1;
			}

			if (cur < 100000 && dot[cur + 1] == -1)
			{
				q.push(cur + 1);
				dot[cur + 1] = dot[cur] + 1;
			}

			cur *= 2;
		} while (cur <= 100000 && repeat);
	}

	cout << dot[k];

	return 0;
}
