#include <iostream>

#include <queue>

using namespace std;

using pos = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const char* impossible = "use the stairs";

	int f; // 건물의 층
	int s; // 강호가 지금 있는 층
	int g; // 스타트링크가 있는 층
	int u; // 위로 U층을 가는 버튼
	int d; // 아래로 D층을 가는 버튼
	cin >> f >> s >> g >> u >> d;

	int r = s - g;
	if (r == 0)
	{
		cout << 0;
	}
	else if (u == 0) // 위로 못감
	{
		if (r > 0 && r % d == 0)
		{
			cout << r / d;
		}
		else
		{
			cout << impossible;
		}
	}
	else if (d == 0) // 아래로 못감
	{
		r *= -1;
		if (r > 0 && r % u == 0)
		{
			cout << r / u;
		}
		else
		{
			cout << impossible;
		}
	}
	else
	{
		int* building = new int[f + 1];
		for (int i = 0; i <= f; ++i)
		{
			building[i] = -1;
		}

		queue<int> q;

		q.push(s);
		building[s] = 0;

		int cur;
		int sub;
		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			sub = cur + u;
			if (0 < sub && sub <= f && building[sub] < 0)
			{
				q.push(sub);
				building[sub] = building[cur] + 1;
			}

			sub = cur - d;
			if (0 < sub && sub <= f && building[sub] < 0)
			{
				q.push(sub);
				building[sub] = building[cur] + 1;
			}

			if (0 < building[g])
			{
				break;
			}
		}

		if (0 < building[g])
		{
			cout << building[g];
		}
		else
		{
			cout << impossible;
		}

		delete[] building;
	}

	return 0;
}
