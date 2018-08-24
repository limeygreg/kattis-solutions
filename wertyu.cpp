#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

std::unordered_map<char, char> fmap;

void init() {
	fmap['\''] = ';';
	fmap[','] = 'M';
	fmap['-'] = '0';
	fmap['.'] = ',';
	fmap['/'] = '.';
	fmap['0'] = '9';
	fmap['1'] = '`';
	fmap['2'] = '1';
	fmap['3'] = '2';
	fmap['4'] = '3';
	fmap['5'] = '4';
	fmap['6'] = '5';
	fmap['7'] = '6';
	fmap['8'] = '7';
	fmap['9'] = '8';
	fmap[';'] = 'L';
	fmap['='] = '-';
	fmap['B'] = 'V';
	fmap['C'] = 'X';
	fmap['D'] = 'S';
	fmap['E'] = 'W';
	fmap['F'] = 'D';
	fmap['G'] = 'F';
	fmap['H'] = 'G';
	fmap['I'] = 'U';
	fmap['J'] = 'H';
	fmap['K'] = 'J';
	fmap['L'] = 'K';
	fmap['M'] = 'N';
	fmap['N'] = 'B';
	fmap['O'] = 'I';
	fmap['P'] = 'O';
	fmap['R'] = 'E';
	fmap['S'] = 'A';
	fmap['T'] = 'R';
	fmap['U'] = 'Y';
	fmap['V'] = 'C';
	fmap['W'] = 'Q';
	fmap['X'] = 'Z';
	fmap['Y'] = 'T';
	fmap['['] = 'P';
	fmap['\\'] = ']';
	fmap[']'] = '[';
}

int main() {
	init();
	std::string s;

	while (std::getline(std::cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				std::cout << " ";
			}
			else {
				std::cout << fmap[s[i]];
			}
		}
		std::cout << std::endl;
	}
	return 0;
}