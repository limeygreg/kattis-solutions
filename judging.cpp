#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <unordered_set>

int main() {
	int n;
	int res = 0;
	std::unordered_map<std::string, int> domj;
	std::unordered_map<std::string, int> kattis;
	std::unordered_set<std::string> vs;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		domj[s]++;
		vs.insert(s);
	}
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		kattis[s]++;
		vs.insert(s);
	}
	for (auto a: vs) {
		res += std::min(domj[a], kattis[a]);
	}
	std::cout << res << std::endl;
	return 0;
}