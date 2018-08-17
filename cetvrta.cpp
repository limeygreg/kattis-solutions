#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	pair<int, int> a, b, c;
	int xsum;
	int ysum;

	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

	if (a.first != b.first && a.second != b.second) {
		xsum = a.first + b.first;
		ysum = a.second + b.second;
		cout << xsum - c.first << " " << ysum - c.second << endl;
	}
	else if (a.first != c.first && a.second != c.second) {
		xsum = a.first + c.first;
		ysum = a.second + c.second;
		cout << xsum - b.first << " " << ysum - b.second << endl;
	}
	else {
		xsum = b.first + c.first;
		ysum = b.second + c.second;
		cout << xsum - a.first << " " << ysum - a.second << endl;
	}
}