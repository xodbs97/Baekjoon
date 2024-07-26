#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	queue<int> q;
	while (n--)
	{
		string op;
		getline(cin, op);

		switch (op[0])
		{
		case 'b':
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
			break;
		case 'e':
			if (q.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
			break;
		case 'f':
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
			break;
		case 'p':
			if (op[1] == 'u')
			{
				q.push(stoi(op.substr(5)));
			}
			else if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
			break;
		case 's':
			cout << q.size() << '\n';
			break;
		}
	}

	return 0;
}