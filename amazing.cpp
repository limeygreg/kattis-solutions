#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdlib.h>

/**
 * Perform DFS where each expansion visits the direction it came from last.
**/

using namespace std;

unordered_map<int, vector<string> > cells;
unordered_map<string, int> mmap;
unordered_map<string, vector<string> > moves;

string makeMove(int c);
void initMoves();

int main() {
	initMoves();
	
	cells[0] = moves["right"];
	int c = 0;
	string res;
	mmap["left"] = -1;
	mmap["right"] = 1;
	mmap["up"] = 200;
	mmap["down"] = -200;

	while (true) {
		string m = makeMove(c);
		cin >> res;
		if (res == "solved" || res == "wrong") {
			break;
		}
		else if (res == "ok") {
			c += mmap[m];
			if (cells.find(c) == cells.end()) {
				cells[c] = moves[m];
			}
		}
	}
	return 0;
}

string makeMove(int c) {
	if (cells[c].empty()) {
		cout << flush << "no way out" << endl;
		return "no way out";
	}
	string s = cells[c].at(0);

	cout << flush << s << endl;
	cells[c].erase(cells[c].begin() + 0);
	return s;
}

void initMoves() {
	string arr1[] = {"down", "right", "left", "up"};
	string arr2[] = {"up", "left", "right", "down"};
	string arr3[] = {"right", "up", "down", "left"};
	string arr4[] = {"left", "up", "down", "right"};
	vector<string> dMoves (arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
	vector<string> uMoves (arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));
	vector<string> rMoves (arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0])));
	vector<string> lMoves (arr4, arr4 + (sizeof(arr4) / sizeof(arr4[0])));
	moves["left"] = lMoves;
	moves["down"] = dMoves;
	moves["up"] = uMoves;
	moves["right"] = rMoves;
}
