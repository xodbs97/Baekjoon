#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Map = vector<vector<int>>;
using Pos = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int R4[4] = { 0,0,1,-1 };
	const int C4[4] = { 1,-1,0,0 };

	int answer = 200;

	int n; // 지도의 크기
	cin >> n;
	Map map(n, vector<int>(n)); // 원본 지도
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			cin >> map[r][c]; // 0은 바다, 1은 육지
		}
	}
	Map tempMap(map);

	queue<Pos> q;
	Pos cur;
	Pos sub;
	bool repeat;
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			if (tempMap[r][c] == 1) // 확인되지 않은 섬
			{
				Map island(n, vector<int>(n, -1));
				queue<Pos> coastline;

				q.push({ r,c });
				tempMap[r][c] = 0; // 해당 섬의 확인된 영토 표시
				island[r][c] = 0;

				while (!q.empty())
				{
					cur = q.front();
					q.pop();
					coastline.push(cur);

					for (int dir = 0; dir < 4; ++dir)
					{
						sub.first = cur.first + R4[dir];
						sub.second = cur.second + C4[dir];

						if (sub.first < 0 || n <= sub.first || sub.second < 0 || n <= sub.second || tempMap[sub.first][sub.second] == 0)
						{
							continue;
						}

						q.push(sub);
						tempMap[sub.first][sub.second] = 0;
						island[sub.first][sub.second] = 0;
					}
				}

				repeat = true;
				while (!coastline.empty() && repeat)
				{
					cur = coastline.front();
					coastline.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						sub.first = cur.first + R4[dir];
						sub.second = cur.second + C4[dir];

						if (sub.first < 0 || n <= sub.first || sub.second < 0 || n <= sub.second || island[sub.first][sub.second] != -1)
						{
							continue;
						}
						if (map[sub.first][sub.second] == 1)
						{
							repeat = false;
							break;
						}

						coastline.push(sub);
						island[sub.first][sub.second] = island[cur.first][cur.second] + 1;
					}
				}

				answer = min(answer, island[cur.first][cur.second]);
			}
		}
	}

	cout << answer;

	return 0;
}
