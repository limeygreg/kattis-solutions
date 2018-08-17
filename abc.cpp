#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int a, b, c, q, w, e;
	string letters;
	cin >> a >> b >> c;
	cin >> letters;
	q = a < b ? (a < c ? a : c) : (b < c ? b : c);
	w = q == a ? (b < c ? b : c) : (q == b ? (a < c ? a : c) : (a < b ? a : b));
	e = a > b ? (a > c ? a : c) : (b > c ? b : c);

	for (int i = 0; i < letters.length(); i++) {
		if (letters[i] == 'A') {
			cout << q << " ";
		}
		else if (letters[i] == 'B') {
			cout << w << " ";
		}
		else {
			cout << e << " ";
		}
	}
	cout << endl;
	return 0;
}