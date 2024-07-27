#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 인원
	cin >> n;

	int height; // 키
	cin >> height;

	stack<pair<int, int>> line; // { 키, 인원 }
	line.push({ height,1 });
	int start = height; // 맨 앞사람의 키

	long long answer = 0;
	for (int i = 1; i < n; ++i)
	{
		cin >> height;

		if (line.top().first > height)
		{
			line.push({ height,1 });
			++answer;
		}
		else if (line.top().first == height)
		{
			if (start > height)
			{
				++answer;
			}

			answer += line.top().second++;
		}
		else
		{
			while (!line.empty() && line.top().first < height)
			{
				answer += line.top().second;
				line.pop();
			}

			if (line.empty())
			{
				line.push({ height,1 });
				start = height;
			}
			else
			{
				if (line.top().first == height)
				{
					if (start > height)
					{
						++answer;
					}

					answer += line.top().second++;
				}
				else
				{
					line.push({ height,1 });
					++answer;
				}
			}
		}
	}

	cout << answer;

	return 0;
}
