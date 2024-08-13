#include <iostream>

#include <algorithm>
#include <string>
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

	int n; // 지도의 크기
	cin >> n;

	string str;
	vector<vector<bool>> map(n, vector<bool>(n));
	for (int r = 0; r < n; ++r)
	{
		cin >> str;
		for (int c = 0; c < n; ++c)
		{
			map[r][c] = str[c] - '0';
		}
	}

	int cnt;
	vector<int> house;

	queue<pos> q;
	pos cur;
	int sr;
	int sc;
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			if (map[r][c])
			{
				q.push({ r,c });
				map[r][c] = false;
				cnt = 1;

				while (!q.empty())
				{
					cur = q.front();
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						sr = cur.first + R4[i];
						sc = cur.second + C4[i];

						if (sr < 0 || n <= sr || sc < 0 || n <= sc || !map[sr][sc])
						{
							continue;
						}

						q.push({ sr,sc });
						map[sr][sc] = false;
						++cnt;
					}
				}

				house.push_back(cnt);
			}
		}
	}

	sort(house.begin(), house.end());
	cout << house.size() << '\n';
	for (const int& num : house)
	{
		cout << num << '\n';
	}

	return 0;
}
