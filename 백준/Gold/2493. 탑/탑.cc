#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<pair<int, int>> skyline;

	int first;
	cin >> first;

	int big = first;
	skyline.push({ first ,1 });

	cout << "0 ";

	for (int i = 2; i <= n; ++i)
	{
		int building;
		cin >> building;

		if (big < building)
		{
			cout << "0 ";
			big = building;
		}
		else {
			while (skyline.top().first < building)
			{
				skyline.pop();
			}
			cout << skyline.top().second << ' ';
		}

		skyline.push({ building,i });
	}

	return 0;
}