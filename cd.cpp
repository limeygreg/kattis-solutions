#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
	long n, m, a;

	while (true) {
		unordered_map<long, bool> fmap;
		long count = 0;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> a;
			fmap[a] = true;
		}
		for (int i = 0; i < m; i++) {
			cin >> a;
			if (fmap[a]) {
				count++;
				fmap[a] = false;
			}
		}
		cout << count << endl;
	}
	return 0;
}