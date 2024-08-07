#include <iostream>

#include <queue>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	const int X[4] = { 1,-1,0,0 };
	const int Y[4] = { 0,0,1,-1 };

	int i;
	int j;
	int m; // 상자의 가로 칸의 수
	int n; // 상자의 세로 칸의 수
	cin >> m >> n; // 2 ≤ m,n ≤ 1,000

	queue<pair<int, int>> tomato;

	int** box = new int* [n];
	int** days = new int* [n];
	for (i = 0; i < n; ++i)
	{
		box[i] = new int[m];
		days[i] = new int[m];
		for (j = 0; j < m; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				tomato.push({ i,j });
				days[i][j] = 0;
			}
			else
			{
				days[i][j] = -1;
			}
		}
	}

	pair<int, int> cur_pos;
	pair<int, int> sub_pos;
	while (tomato.size())
	{
		cur_pos = tomato.front();
		tomato.pop();

		for (i = 0; i < 4; ++i)
		{
			sub_pos = { cur_pos.first + X[i],cur_pos.second + Y[i] };
			if (sub_pos.first < 0 || n <= sub_pos.first || sub_pos.second < 0 || m <= sub_pos.second || box[sub_pos.first][sub_pos.second] != 0)
			{
				continue;
			}

			box[sub_pos.first][sub_pos.second] = 1;
			days[sub_pos.first][sub_pos.second] = days[cur_pos.first][cur_pos.second] + 1;
			tomato.push(sub_pos);
		}
	}

	int max_days = 0;
	bool all_ripe = true;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (box[i][j] == 0)
			{
				all_ripe = false;
				break;
			}
			max_days = max(max_days, days[i][j]);
		}
	}

	if (all_ripe)
	{
		cout << max_days << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}

	for (i = 0; i < n; ++i)
	{
		delete[] box[i];
		delete[] days[i];
	}
	delete[] box;
	delete[] days;

	return 0;
}
