#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	bool rows[8] = {false};
	bool cols[8] = {false};
	bool diag1[16] = {false};
	bool diag2[16] = {false};
	bool found = false;
	int count = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			if (c == '*') {
				count++;
				int cr = i;
				int cc = j;
				int cd1 = i + j;
				int cd2 = i + (8 - j - 1);
				if (rows[cr] || cols[cc] || diag1[cd1] || diag2[cd2]) found = true;
				rows[i] = true;
				cols[j] = true;
				diag1[i + j] = true;
				diag2[i + (8 - j - 1)] = true;
			}
		}
	}
	if (count != 8) found = true;
	if (found) cout << "invalid" << endl;
	else cout << "valid" << endl;
	return 0;
}