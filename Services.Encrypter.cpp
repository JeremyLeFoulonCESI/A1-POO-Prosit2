#include "Services.Encrypter.hpp"
#include <iostream>


namespace Services {
	char Encrypter::encrypt_cesar(char src) {
		return src + this->key;
	}
	char Encrypter::encrypt_xor(char src) {
		return src ^ this->key;
	}
	void Encrypter::encrypt() {
		if (!this->isValid())
			return;

		char read;
		while (1) {
			if (!this->src->readChar(&read))
				break;
			if ((uint8_t)this->encryption_kind & (uint8_t)Components::EncryptionKind::CESAR) {
				read = this->encrypt_cesar(read);
			}
			if ((uint8_t)this->encryption_kind & (uint8_t)Components::EncryptionKind::XOR) {
				read = this->encrypt_xor(read);
			}
			this->dst->writeChar(read);
		}
	}
}

