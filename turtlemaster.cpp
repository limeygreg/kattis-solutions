#include <algorithm>
#include <iostream>
#include <string>

int modulo(int a, int b) {
	return (b + (a % b)) % b;
}

bool inBounds(int r, int c) {
	return r >= 0 && r <= 7 && c >= 0 && c <= 7;
}

int main() {
	char grid[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cin >> grid[i][j];
		}
	}
	std::string s;
	std::cin >> s;
	int r = 7;
	int c = 0;
	int nr = 7;
	int nc = 1;
	int move = 2;
	int rmove[4] = {0, -1, 0, 1};
	int cmove[4] = {-1, 0, 1, 0};
	int lrmove[4] = {1, 1, -1, -1};
	int lcmove[4] = {1, -1, -1, 1};
	int rrmove[4] = {-1, 1, 1, -1};
	int rcmove[4] = {1, 1, -1, -1};
	grid[r][c] = '.';

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'F') {
			if (!inBounds(nr, nc) || grid[nr][nc] == 'C' || grid[nr][nc] == 'I') {
				std::cout << "Bug!" << std::endl;
				return 0;
			}
			else {
				r = nr;
				c = nc;
				nr += rmove[move];
				nc += cmove[move];
			}
		}
		else if (s[i] == 'L') {
			nr += lrmove[move];
			nc += lcmove[move];
			move--;
			move = modulo(move, 4);
		}
		else if (s[i] == 'R') {
			nr += rrmove[move];
			nc += rcmove[move];
			move++;
			move = modulo(move, 4);
		}
		else if (s[i] == 'X') {
			if (inBounds(nr, nc) && grid[nr][nc] == 'I') {
				grid[nr][nc] = '.';
			}
			else {
				std::cout << "Bug!" << std::endl;
				return 0;
			}
		}
	}
	if (grid[r][c] == 'D') {
		std::cout << "Diamond!" << std::endl;
	}
	else {
		std::cout << "Bug!" << std::endl;
	}
	return 0;
}