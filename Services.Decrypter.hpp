#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"


namespace Services {
	class Decrypter {
		Components::File* src;
		Components::File* dst;
		Components::EncryptionKind encryption_kind;

		char decrypt_cesar(char);
		char decrypt_xor(char);
	public:
		Decrypter(const char* src_filename, const char* dst_filename, uint8_t encryptionKind);

		void decrypt();
	};
}

