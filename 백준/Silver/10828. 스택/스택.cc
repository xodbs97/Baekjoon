#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	stack<int> stk;
	while (n--)
	{
		string op;
		getline(cin, op);

		switch (op[0])
		{
		case 'e': // empty()
			if (stk.empty()) // 참
			{
				cout << 1 << '\n';
			}
			else // 거짓
			{
				cout << 0 << '\n';
			}
			break;
		case 'p':
			if (op[1] == 'u') // push()
			{
				stk.push(stoi(op.substr(5)));
			}
			else if (stk.empty()) // pop() 불가능
			{
				cout << -1 << '\n';
			}
			else // pop() 가능
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
			break;
		case 's': // size()
			cout << stk.size() << '\n';
			break;
		case 't': // top()
			if (stk.empty()) // 불가능
			{
				cout << -1 << '\n';
			}
			else // 가능
			{
				cout << stk.top() << '\n';
			}
			break;
		}
	}

	return 0;
}
