#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

struct Position {
	int row;
	int col;
};

unordered_map<char, Position> fmap;

int computeDist(string s, string t) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += abs(fmap[s[i]].row - fmap[t[i]].row);
		sum += abs(fmap[s[i]].col - fmap[t[i]].col);
	}
	return sum;
}

void init() {
	fmap['q'] = (Position) {0, 0};
	fmap['w'] = (Position) {0, 1};
	fmap['e'] = (Position) {0, 2};
	fmap['r'] = (Position) {0, 3};
	fmap['t'] = (Position) {0, 4};
	fmap['y'] = (Position) {0, 5};
	fmap['u'] = (Position) {0, 6};
	fmap['i'] = (Position) {0, 7};
	fmap['o'] = (Position) {0, 8};
	fmap['p'] = (Position) {0, 9};
	fmap['a'] = (Position) {1, 0};
	fmap['s'] = (Position) {1, 1};
	fmap['d'] = (Position) {1, 2};
	fmap['f'] = (Position) {1, 3};
	fmap['g'] = (Position) {1, 4};
	fmap['h'] = (Position) {1, 5};
	fmap['j'] = (Position) {1, 6};
	fmap['k'] = (Position) {1, 7};
	fmap['l'] = (Position) {1, 8};
	fmap['z'] = (Position) {2, 0};
	fmap['x'] = (Position) {2, 1};
	fmap['c'] = (Position) {2, 2};
	fmap['v'] = (Position) {2, 3};
	fmap['b'] = (Position) {2, 4};
	fmap['n'] = (Position) {2, 5};
	fmap['m'] = (Position) {2, 6};
}

int main() {
	int t, l;
	string s;
	cin >> t;
	init();

	for (int i = 0; i < t; i++) {
		map<int, vector<string> > res;
		cin >> s >> l;
		string temp;
		for (int j = 0; j < l; j++) {
			cin >> temp;
			int cost = computeDist(s, temp);
			res[cost].push_back(temp);
			if (res[cost].size() > 0) {
				sort(res[cost].begin(), res[cost].end());
			}
		}
		for (auto it = res.begin(); it != res.end(); ++it) {
			for (int k = 0; k < it->second.size(); k++) {
				cout << it->second.at(k) << " " << it->first << endl;
			}
		}
	}
	return 0;
}