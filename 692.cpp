#include <iostream>
#include <string>

const int RANGE = 100000;

bool isExist(const std::string& sample, const std::string& target) {
	for (int i = 0; i < sample.size() - target.size() + 1; i++) {
		int j = 0;
		while (j < target.size() && i + j < sample.size()) {
			if (sample[i + j] != target[j]) {
				break;
			}
			j++;
		}
		if (j == target.size()) {
			return true;
		}
	}
	return false;
}

void getPrimeArray(bool* prime) {
	for (int i = 2; i < 320; i++) {
		if (prime[i]) {
			int dup = 2;
			while (i*dup <= RANGE) {
				prime[i*dup] = false;
				dup++;
			}
		}
	}
}

int main() {
	bool prime[RANGE + 1];
	for (int i = 0; i < RANGE; i++) {
		prime[i] = true;
	}
	getPrimeArray(prime);
	while (true) {
		std::string sample;
		std::cin >> sample;
		if (sample == "0") {
			break;
		}
		int i = RANGE;
		while (i > 1) {
			std::string temp = std::to_string(i);
			if (prime[i] && sample.size() >= temp.size() && isExist(sample, temp)) {
				std::cout << i << std::endl;
				break;
			}
			i--;
		}
	}
	system("pause");
	return 0;
}