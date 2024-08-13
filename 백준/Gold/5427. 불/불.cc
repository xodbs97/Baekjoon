#include <iostream>

#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	const int R4[4] = { 0,0,1,-1 };
	const int C4[4] = { 1,-1,0,0 };

	int tc;
	cin >> tc;
	while (tc--)
	{
		int col;
		int row;
		cin >> col >> row;

		vector<vector<char>> building(row, vector<char>(col)); // 빌딩
		queue<pair<pair<int, int>, int>> fullTime; // 상근
		queue<pair<pair<int, int>, int>> fire; // 불

		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				cin >> building[r][c];
				if (building[r][c] == '@')
				{
					fullTime.push({ { r,c }, 0 });
				}
				else if (building[r][c] == '*')
				{
					fire.push({ {r,c},0 });
				}
			}
		}

		int initR = fullTime.front().first.first;
		int initC = fullTime.front().first.second;
		if (initR == 0 || initR == row - 1 || initC == 0 || initC == col - 1)
		{
			cout << 1 << '\n';
			continue;
		}

		bool start = false;
		int time = 0;
		pair<int, int> cur;
		pair<int, int> sub;
		queue<pair<int, int>> edge;
		for (;;)
		{
			while (edge.size())
			{
				if (building[edge.front().first][edge.front().second] == '@')
				{
					cout << time + 1 << '\n';
					start = true;
					break;
				}
				edge.pop();
			}

			if (start)
			{
				break;
			}
			start = false;

			if (fullTime.empty())
			{
				cout << "IMPOSSIBLE\n";
				break;
			}

			while (fullTime.size() && fullTime.front().second == time)
			{
				cur = fullTime.front().first;
				fullTime.pop();

				for (int i = 0; i < 4; ++i)
				{
					sub = { cur.first + R4[i], cur.second + C4[i] };
					if (sub.first < 0 || row <= sub.first || sub.second < 0 || col <= sub.second || building[sub.first][sub.second] != '.')
					{
						continue;
					}

					fullTime.push({ sub, time + 1 });
					building[sub.first][sub.second] = '@';

					if (sub.first == 0 || sub.first == row - 1 || sub.second == 0 || sub.second == col - 1)
					{
						edge.push(sub);
					}
				}
			}

			while (fire.size() && fire.front().second == time)
			{
				cur = fire.front().first;
				fire.pop();

				for (int i = 0; i < 4; ++i)
				{
					sub = { cur.first + R4[i], cur.second + C4[i] };
					if (sub.first < 0 || row <= sub.first || sub.second < 0 || col <= sub.second || building[sub.first][sub.second] == '#' || building[sub.first][sub.second] == '*')
					{
						continue;
					}

					fire.push({ sub,time + 1 });
					building[sub.first][sub.second] = '*';
				}
			}

			++time;
		}
	}

	return 0;
}
