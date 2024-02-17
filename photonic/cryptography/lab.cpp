#include <cstdlib>
#include <ctime>
#include <string>
#include <crypto++/aes.h>
#include <crypto++/modes.h>
#include <crypto++/filters.h>
#include <crypto++/hex.h>

char* get_unsecure_key(unsigned int key_size, time_t _time=time(0))
{
	std::srand(_time);
	char* key{ new char[key_size + 1] };

	for (size_t i{}; i < key_size; ++i) {
		key[i] = std::rand() % 256;
	}

	key[key_size] = '\0';

	return key;
}

char* crack_aes_128_cbc(const char* plaintext, const char* ciphertext, const char* IV, time_t start_time, time_t end_time) {
	for (time_t current_guess{ start_time }; current_guess <= end_time; ++current_guess) {
		char* key{ get_unsecure_key(16, current_guess) };

		const char* text{};  // encrypt
		
		if (text == ciphertext) {
			return key;
		}
	}

	return {};
}

char* encrypt_aes_128_cbc(std::string plaintext, const char* _key, const char* _iv) {
	//std::string key_str = "your_hex_key_here";
	//std::string iv_str = "your_hex_iv_here";

	CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

	CryptoPP::StringSource ss1(_key, true, new CryptoPP::HexDecoder(new CryptoPP::ArraySink(key, CryptoPP::AES::DEFAULT_KEYLENGTH)));
	CryptoPP::StringSource ss2(_iv, true, new CryptoPP::HexDecoder(new CryptoPP::ArraySink(iv, CryptoPP::AES::BLOCKSIZE)));

	// String and its ciphertext containers
	std::string ciphertext;

	// Encryption
	CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

	CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() + 1);
	stfEncryptor.MessageEnd();

	// Now, 'ciphertext' holds the AES encrypted string
	// ...

	return 0;
}