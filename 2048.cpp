#include <algorithm>
#include <iostream>

/**
 * We rotate 2048 grid 90 degrees counter-clockwise n times according to move command:
 * left = 0
 * up = 1
 * right = 2
 * down = 3
**/

using namespace std;

int grid[4][4];

void solve(int m);
void rotate(int m);
void printGrid();

int main() {
	int m;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int t;
			cin >> t;
			grid[i][j] = t;
		}
	}
	cin >> m;

	solve(m);
	return 0;
}

void solve(int m) {
	rotate(m);
	for (int i = 0; i < 4; i++) {
		int last = 0;
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] != 0) {
				int k = j + 1;
				int sum = 0;
				while (k < 4 && grid[i][k] == 0) k++;
				if (k < 4 && grid[i][j] == grid[i][k]) {
					sum += (grid[i][j] + grid[i][k]);
					grid[i][j] = 0;
					grid[i][k] = 0;
					grid[i][last] = sum;
				}
				else {
					int temp = grid[i][j];
					grid[i][j] = 0;
					grid[i][last] = temp;
				}
				last++;
			}
		}
	}
	rotate(m == 0 ? 0 : 4 - m);
	printGrid();
}

void rotate(int m) {
	m %= 4; // Check cycle
	for (int l = 0; l < m; l++) {
		for (int i = 0; i < 4; i++) {
			for (int j = i; j < 4; j++) {
				int t = grid[i][j];
				grid[i][j] = grid[j][i];
				grid[j][i] = t;
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 2; i++) {
				int t = grid[i][j];
				grid[i][j] = grid[4 - i - 1][j];
				grid[4 - i - 1][j] = t;
			}
		}
	}
}

void printGrid() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}