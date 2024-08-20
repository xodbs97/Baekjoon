#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

using Pos = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int R4[4] = { 0,0,1,-1 };
	const int C4[4] = { 1,-1,0,0 };

	int row;
	int col;
	cin >> row >> col;
	vector<string> map(row);
	for (int r = 0; r < row; ++r)
	{
		cin >> map[r];
	}

	vector <vector<pair<int, int>>> visit(row, vector<pair<int, int>>(col, { -1,-1 }));

	queue<pair<Pos, bool>> q;
	q.push({ { 0,0 }, false });
	visit[0][0].first = 1;

	bool repeat = true;
	bool breaked;
	Pos cur;
	Pos sub;
	while (!q.empty() && repeat)
	{
		cur = q.front().first;
		breaked = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			sub.first = cur.first + R4[i];
			sub.second = cur.second + C4[i];

			if (sub.first < 0 || row <= sub.first || sub.second < 0 || col <= sub.second)
			{
				continue;
			}

			if (breaked) // 사용
			{
				if (map[sub.first][sub.second] == '1' || 0 < visit[sub.first][sub.second].second)
				{
					continue;
				}

				q.push({ sub,true });
				visit[sub.first][sub.second].second = visit[cur.first][cur.second].second + 1;
			}
			else // 사용하지 않음
			{
				if (map[sub.first][sub.second] == '1') // 벽인 경우
				{
					if (0 < visit[sub.first][sub.second].second)
					{
						continue;
					}

					q.push({ sub,true });
					visit[sub.first][sub.second].second = visit[cur.first][cur.second].first + 1;
				}
				else // 벽이 아닌 경우
				{
					if (0 < visit[sub.first][sub.second].first)
					{
						continue;
					}

					q.push({ sub,false });
					visit[sub.first][sub.second].first = visit[cur.first][cur.second].first + 1;
				}
			}

			if (sub.first == row - 1 && sub.second == col - 1)
			{
				repeat = false;
				break;
			}
		}
	}

	cout << max(visit[row - 1][col - 1].first, visit[row - 1][col - 1].second);

	return 0;
}
