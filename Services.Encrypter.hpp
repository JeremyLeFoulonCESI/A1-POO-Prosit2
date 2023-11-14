#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"


namespace Services {
	class Encrypter {
		Components::File* src;
		Components::File* dst;
		Components::EncryptionKind encryption_kind;

		char encrypt_cesar(char);
		char encrypt_xor(char);

	public:
		Encrypter(const char* src_filename, const char* dst_filename, uint8_t encryptionKind);

		void encrypt();
	};
}

