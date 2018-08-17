#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;

int main() {
	int p;
	unordered_map<unsigned long, unsigned long> dp1;
	unordered_map<unsigned long, unsigned long> dp2;
	unordered_map<unsigned long, bool> flags;
	dp1[1] = 1;
	dp2[1] = 1;
	flags[1] = true;
	cin >> p;

	for (int i = 0; i < p; i++) {
		unsigned long k, n;
		cin >> k >> n;
		if (!flags[n]) {
			string b = bitset<32>(n).to_string();
			size_t index = b.find("1");
			b = b.substr(index);
			unsigned long l = 1;
			unsigned long num, denom = 0;
			for (int j = 1; j < b.length(); j++) {
				if (b[j] % 2 == 1) {
					num = (dp1[l] + dp2[l]);
					denom = dp2[l];
					l = (l * 2) + 1;
				}
				else {
					num = dp1[l];
					denom = dp1[l] + dp2[l];
					l <<= 1;
				}
				dp1[l] = num;
				dp2[l] = denom;
				flags[l] = true;
			}
		}
		cout << k << " " << dp1[n] << "/" << dp2[n] << endl;
	}
	return 0;
}