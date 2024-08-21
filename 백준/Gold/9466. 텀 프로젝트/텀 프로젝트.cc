#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int answer;
	int n;

	int tc;
	cin >> tc;
	while (tc--)
	{
		answer = 0;

		cin >> n;

		vector<char> team(n + 1, 0);
		vector<int> students(n + 1);
		students[0] = 0;

		for (int i = 1; i <= n; ++i)
		{
			cin >> students[i];
		}

		for (int i = 1; i <= n; ++i)
		{
			if (team[i])
			{
				continue;
			}

			vector<bool> temp(n + 1, false);
			queue<int> q;

			q.push(i);
			temp[i] = true;

			int cur = students[i];
			for (;;)
			{
				if (team[cur])
				{
					while (!q.empty())
					{
						team[q.front()] = 2;
						q.pop();
					}

					break;
				}

				if (temp[cur])
				{
					while (q.front() != cur)
					{
						team[q.front()] = 2;
						q.pop();
					}

					while (!q.empty())
					{
						team[q.front()] = 1;
						q.pop();
					}

					break;
				}

				q.push(cur);
				temp[cur] = true;
				cur = students[cur];
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			if (team[i] == 2)
			{
				++answer;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
