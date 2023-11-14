#include "Services.Encrypter.hpp"
#include <iostream>


namespace Services {
	char Encrypter::cesarTransform(char src, uint8_t key) {
		return src + key;
	}
	char Encrypter::xorTransform(char src, uint8_t key) {
		return src ^ key;
	}
}

