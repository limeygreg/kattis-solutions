#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	bool flags[1001] = {false};

	cin >> n;

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		flags[c] = true;
	}

	for (int i = 1; i < 1001; i++) {
		if (flags[i]) {
			string res = to_string(i);
			int j = i;
			while (j + 1 < 1001 && flags[j + 1]) {
				j++;
			}
			if (i + 1 < j) {
				res = res + "-" + to_string(j);
				i = j;
			}
			cout << res << " ";
		}
	}
	cout << endl;
	return 0;
}