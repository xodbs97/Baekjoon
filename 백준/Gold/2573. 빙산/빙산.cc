#include <iostream>
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

	int row; // 행
	int col; // 열
	cin >> row >> col;

	int r;
	int c;
	int dir;
	vector<vector<int>> ocean(row, vector<int>(col));
	for (r = 0; r < row; ++r)
	{
		for (c = 0; c < col; ++c)
		{
			cin >> ocean[r][c];
		}
	}

	bool repeat = true;
	int year = 0;
	bool one;
	queue<Pos> q;
	Pos cur;
	Pos sub;
	while (repeat && year < 500)
	{
		++year;

		// 빼는 값 계산
		vector<vector<int>> melt(row, vector<int>(col, 0));
		for (r = 1; r < row - 1; ++r)
		{
			for (c = 1; c < col - 1; ++c)
			{
				if (ocean[r][c])
				{
					for (dir = 0; dir < 4; ++dir)
					{
						sub.first = r + R4[dir];
						sub.second = c + C4[dir];

						if (ocean[sub.first][sub.second])
						{
							continue;
						}

						++melt[r][c];
					}
				}
			}
		}

		// 적용
		for (r = 1; r < row - 1; ++r)
		{
			for (c = 1; c < col - 1; ++c)
			{
				ocean[r][c] = max(0, ocean[r][c] - melt[r][c]);
			}
		}

		// 확인
		one = false;
		vector<vector<bool>> visit(row, vector<bool>(col, false));
		for (r = 1; r < row - 1 && repeat; ++r)
		{
			for (c = 1; c < col - 1; ++c)
			{
				if (ocean[r][c] && !visit[r][c])
				{
					if (one)
					{
						repeat = false;
						break;
					}

					q.push({ r,c });
					visit[r][c] = true;

					while (!q.empty())
					{
						cur = q.front();
						q.pop();

						for (dir = 0; dir < 4; ++dir)
						{
							sub.first = cur.first + R4[dir];
							sub.second = cur.second + C4[dir];

							if (sub.first < 0 || row <= sub.first || sub.second < 0 || col <= sub.second || ocean[sub.first][sub.second] <= 0 || visit[sub.first][sub.second])
							{
								continue;
							}

							q.push(sub);
							visit[sub.first][sub.second] = true;
						}
					}

					one = true;
				}
			}
		}
	}

	if (repeat)
	{
		cout << 0;
	}
	else
	{
		cout << year;
	}

	return 0;
}
