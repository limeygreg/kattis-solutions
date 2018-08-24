#include <iostream>
#include <algorithm>

int main() {
	long a, b;
	while (std::cin >> a >> b) {
		if (a == 0 && b == 0) break;
		int c = 0;
		int carry = 0;
		while (a != 0 || b != 0) {
			carry += (a % 10 + b % 10);
			a /= 10;
			b /= 10;
			c += (carry / 10) % 10;
			carry /= 10;
		}
		if (c == 0) std::cout << "No carry operation." << std::endl;
		else if (c == 1) std::cout << "1 carry operation." << std::endl;
		else std::cout << c << " carry operations." << std::endl;
	}
	return 0;
}