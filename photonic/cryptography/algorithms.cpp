#include <cstring>

class cryptography_algorithms
{
	const char* ceaser_cipher(const char* plain_text, const char shift)
	{
		const size_t len{ strlen(plain_text) };
		char* cipher_text{ new char[len + 1] };
		
		for (int i{}; i < len; ++i)
		{
			cipher_text[i] = static_cast<char>(plain_text[i] + shift);
		}

		cipher_text[len] = '\0';

		return cipher_text;
	}
};
	