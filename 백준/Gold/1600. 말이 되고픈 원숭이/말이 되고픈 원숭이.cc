#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using MAP = vector<vector<int>>;

struct POS3
{
	int cnt;
	int row;
	int col;
};

static const int R4[4] = { 0,0,1,-1 };
static const int C4[4] = { 1,-1,0,0 };
static const int RH[8] = { 2,1,-1,-2,-2,-1,1,2 };
static const int CH[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int horse;
	int row;
	int col;
	int answer = -1;

	cin >> horse >> col >> row;

	if (row == 1 && col == 1)
	{
		cout << 0;
		return 0;
	}

	vector<MAP> monkeys(horse + 1, MAP(row, vector<int>(col, -1)));
	MAP map(row, vector<int>(col));

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			cin >> map[r][c];
		}
	}

	queue <POS3> q;
	q.push({ 0,0,0 });
	monkeys[0][0][0] = 0;

	while (!q.empty())
	{
		POS3 cur = q.front();
		q.pop();

		if (cur.row == row - 1 && cur.col == col - 1)
		{
			answer = monkeys[cur.cnt][cur.row][cur.col];
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			POS3 sub{ cur.cnt,cur.row + R4[i], cur.col + C4[i] };
			if (sub.row < 0 || row <= sub.row || sub.col < 0 || col <= sub.col || map[sub.row][sub.col] == 1 || monkeys[sub.cnt][sub.row][sub.col] != -1) // 범위 벗어남, 장애물, 중복 방문
			{
				continue;
			}
			q.push(sub);
			monkeys[sub.cnt][sub.row][sub.col] = monkeys[cur.cnt][cur.row][cur.col] + 1;
		}

		if (cur.cnt < horse)
		{
			for (int i = 0; i < 8; ++i)
			{
				POS3 sub{ cur.cnt + 1,cur.row + RH[i], cur.col + CH[i] };
				if (sub.row < 0 || row <= sub.row || sub.col < 0 || col <= sub.col || map[sub.row][sub.col] == 1 || monkeys[sub.cnt][sub.row][sub.col] != -1) // 범위 벗어남, 장애물, 중복 방문
				{
					continue;
				}
				q.push(sub);
				monkeys[sub.cnt][sub.row][sub.col] = monkeys[cur.cnt][cur.row][cur.col] + 1;
			}
		}
	}

	cout << answer;

	return 0;
}
