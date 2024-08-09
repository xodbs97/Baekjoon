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
	int row; // 미로 행의 개수
	int col; // 미로 열의 개수
	cin >> row >> col;

	queue<pair<pair<int, int>, int>> jihun; // { row,col },time
	queue<pair<pair<int, int>, int>> fire; // { row,col },time

	char** maze = new char* [row];
	for (i = 0; i < row; ++i)
	{
		maze[i] = new char[col];
		for (j = 0; j < col; ++j)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'J')
			{
				jihun.push({ { i,j },0 });
			}
			else if (maze[i][j] == 'F')
			{
				fire.push({ { i,j },0 });
			}
		}
	}

	int time = 0;
	bool escaped = false;

	pair<int, int> cur_pos;
	pair<int, int> sub_pos;
	for (;;)
	{
		if (escaped || jihun.empty())
		{
			break;
		}

		while (jihun.size() && jihun.front().second == time)
		{
			cur_pos = jihun.front().first;
			jihun.pop();

			if ((cur_pos.first == 0 || cur_pos.first == row - 1 || cur_pos.second == 0 || cur_pos.second == col - 1) && maze[cur_pos.first][cur_pos.second] == 'J')
			{
				escaped = true;
				break;
			}

			for (i = 0; i < 4; ++i)
			{
				sub_pos = { cur_pos.first + X[i],cur_pos.second + Y[i] };
				if (sub_pos.first < 0 || row <= sub_pos.first || sub_pos.second < 0 || col <= sub_pos.second || maze[sub_pos.first][sub_pos.second] != '.')
				{
					continue;
				}

				maze[sub_pos.first][sub_pos.second] = 'J';
				jihun.push({ sub_pos ,time + 1 });
			}
		}

		while (fire.size() && fire.front().second == time)
		{
			cur_pos = fire.front().first;
			fire.pop();

			for (i = 0; i < 4; ++i)
			{
				sub_pos = { cur_pos.first + X[i],cur_pos.second + Y[i] };
				if (sub_pos.first < 0 || row <= sub_pos.first || sub_pos.second < 0 || col <= sub_pos.second || maze[sub_pos.first][sub_pos.second] == '#' || maze[sub_pos.first][sub_pos.second] == 'F')
				{
					continue;
				}

				maze[sub_pos.first][sub_pos.second] = 'F';
				fire.push({ sub_pos ,time + 1 });
			}
		}

		++time;
	}

	if (escaped)
	{
		cout << time;
	}
	else
	{
		cout << "IMPOSSIBLE";
	}

	for (i = 0; i < row; ++i)
	{
		delete[] maze[i];
	}
	delete[] maze;

	return 0;
}
