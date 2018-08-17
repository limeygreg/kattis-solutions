#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	unordered_map<string, string> dict;
	string line, eng, forg, str;

	while (getline(cin, line)) {
		if (line.empty()) break;
		size_t index = line.find(" ");
		eng = line.substr(0, index);
		forg = line.substr(index + 1);
		dict[forg] = eng;
	}
	while (getline(cin, str)) {
		if (str.empty()) break;
		if (dict.find(str) != dict.end()) {
			cout << dict[str] << endl;
		}
		else {
			cout << "eh" << endl;
		}
	}
	return 0;
}