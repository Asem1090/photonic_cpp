#include "cryptography/lab.h"
#include <iostream>

int main() {
	char* key{ get_unsecure_key(16) };

	std::cout << "Key is : \"" << key << '"' << '\n';
	
	int charcters_count{};
	while (true) {
		if (key[charcters_count] != '\0') {
			++charcters_count;
		}
		else {
			break;
		}
	}
	std::cout << "Number of bytes is: " << charcters_count << '\n';
}