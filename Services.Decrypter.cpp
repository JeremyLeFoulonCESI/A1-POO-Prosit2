#include "Services.Decrypter.hpp"
#include <iostream>


namespace Services {
	char Decrypter::decrypt_cesar(char src) {
		return src - this->key;
	}
	char Decrypter::decrypt_xor(char src) {
		return src ^ this->key;
	}

	void Decrypter::decrypt() {
		if (!this->isValid())
			return;

		char read;
		while (1) {
			if (!this->src->readChar(&read))
				break;
			if ((uint8_t)this->encryption_kind & (uint8_t)Components::EncryptionKind::XOR) {
				read = this->decrypt_xor(read);
			}
			if ((uint8_t)this->encryption_kind & (uint8_t)Components::EncryptionKind::CESAR) {
				read = this->decrypt_cesar(read);
			}
			this->dst->writeChar(read);
		}
	}

}

