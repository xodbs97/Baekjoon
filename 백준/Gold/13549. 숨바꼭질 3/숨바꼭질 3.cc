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
	int sub;
	while (!q.empty() && dot[k] == -1)
	{
		cur = q.front();
		q.pop();
		if (checked[cur])
		{
			continue;
		}
		checked[cur] = true;

		sub = cur;
		repeat = true;
		do
		{
			if (100000 < sub * 2 || checked[sub * 2])
			{
				repeat = false;
			}
			else if (dot[sub * 2] == -1 || dot[sub] < dot[sub * 2])
			{
				dot[sub * 2] = dot[sub];
				checked[sub * 2] = true;
			}

			if (sub && !checked[sub - 1] && dot[sub - 1] == -1)
			{
				q.push(sub - 1);
				dot[sub - 1] = dot[sub] + 1;
			}

			if (sub < 100000 && !checked[sub + 1] && dot[sub + 1] == -1)
			{
				q.push(sub + 1);
				dot[sub + 1] = dot[sub] + 1;
			}

			sub *= 2;
		} while (sub <= 100000 && repeat);
	}

	cout << dot[k];

	return 0;
}
