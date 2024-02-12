#include <bits/stdc++.h>

using namespace std;

int month[12]{ 1,4,4,0,2,5,0,3,6,1,4,6 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	int day = (month[x - 1] + y - 1) % 7;
	switch (day)
	{
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
	default:
		cout << "SAT";
		break;
	}

	return 0;
}