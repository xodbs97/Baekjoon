#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	deque<int> dq;
	while (n--)
	{
		string op;
		getline(cin, op);

		switch (op[0])
		{
		case 'b': // back
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
			break;
		case 'e': // empty
			if (dq.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
			break;
		case 'f': // front
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
			break;
		case 'p':
			if (op[1] == 'u') // push
			{
				if (op[5] == 'f') // front
				{
					dq.push_front(stoi(op.substr(11)));
				}
				else // back
				{
					dq.push_back(stoi(op.substr(10)));
				}
			}
			else // pop
			{
				if (op[4] == 'f') // front
				{
					if (dq.empty())
					{
						cout << -1 << '\n';
					}
					else
					{
						cout << dq.front() << '\n';
						dq.pop_front();
					}
				}
				else // back
				{
					if (dq.empty())
					{
						cout << -1 << '\n';
					}
					else
					{
						cout << dq.back() << '\n';
						dq.pop_back();
					}
				}
			}
			break;
		case 's': // size
			cout << dq.size() << '\n';
			break;
		}
	}

	return 0;
}