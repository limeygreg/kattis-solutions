#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	unordered_map<int, int> imap;
	int out[6] = {0};
	bool found = false;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		imap[c] = i + 1;
		out[c - 1]++;
	}
	for (int i = 5; i >= 0; i--) {
		if (out[i] == 1) {
			cout << imap[i + 1] << endl;
			found = true;
			break;
		}
	}
	if (!found) cout << "none" << endl;
	return 0;
}