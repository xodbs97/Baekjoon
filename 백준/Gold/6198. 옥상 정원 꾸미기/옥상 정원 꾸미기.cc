#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<int> building;

	int height;
	cin >> height;
	building.push(height);

	long long answer = 0;

	for (int i = 1; i < n; ++i)
	{
		cin >> height;

		while (!building.empty() && building.top() <= height)
		{
			building.pop();
		}

		answer += building.size();

		building.push(height);
	}

	cout << answer;

	return 0;
}