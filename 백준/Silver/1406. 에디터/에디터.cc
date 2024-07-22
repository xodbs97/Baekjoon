#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string src;
	cin >> src;
	cin.ignore();

	list<char> str;
	for (auto& c : src)
		str.push_back(c);

	auto cur = str.end();

	int m;
	cin >> m;
	cin.ignore();
	while (m--)
	{
		string op;
		getline(cin, op);

		if (op[0] == 'L' && cur != str.begin())
		{
			--cur;
		}
		else if (op[0] == 'D' && cur != str.end())
		{
			++cur;
		}
		else if (op[0] == 'B' && cur != str.begin())
		{
			cur = str.erase(--cur);
		}
		else if (op[0] == 'P')
		{
			str.insert(cur, op[2]);
		}
	}

	for (auto c : str)
		cout << c;

	return 0;
}