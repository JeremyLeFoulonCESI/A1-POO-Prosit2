#include "Services.Decrypter.hpp"
#include <iostream>


namespace Services {
	char Decrypter::cesarTransform(char src, uint8_t key) {
		return src - key;
	}
	char Decrypter::xorTransform(char src, uint8_t key) {
		return src ^ key;
	}

}

