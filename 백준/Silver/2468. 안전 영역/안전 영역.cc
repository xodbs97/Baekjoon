#include <iostream>

#include <vector>
#include <queue>

using namespace std;

using pos = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int R4[4] = { 0,0,1,-1 };
	const int C4[4] = { 1,-1,0,0 };

	int n; // 길이
	cin >> n;

	int lowest = 101;
	int highest = 0;
	vector<vector<int>> map(n, vector<int>(n));
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			cin >> map[r][c];
			lowest = min(lowest, map[r][c]);
			highest = max(highest, map[r][c]);
		}
	}

	int answer = 1;
	pos cur;
	int sr;
	int sc;
	for (int rain = lowest; rain < highest; ++rain)
	{
		int area = 0;
		vector<vector<bool>> visit(n, vector<bool>(n, false));
		queue<pos> q;

		for (int r = 0; r < n; ++r)
		{
			for (int c = 0; c < n; ++c)
			{
				if (rain < map[r][c] && !visit[r][c])
				{
					++area;

					q.push({ r,c });
					visit[r][c] = true;

					while (!q.empty())
					{
						cur = q.front();
						q.pop();

						for (int i = 0; i < 4; ++i)
						{
							sr = cur.first + R4[i];
							sc = cur.second + C4[i];

							if (sr < 0 || n <= sr || sc < 0 || n <= sc || map[sr][sc] <= rain || visit[sr][sc])
							{
								continue;
							}

							q.push({ sr,sc });
							visit[sr][sc] = true;
						}
					}
				}
			}
		}

		answer = max(answer, area);
	}

	cout << answer;

	return 0;
}
