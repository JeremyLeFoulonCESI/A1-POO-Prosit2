#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"
#include "Services.CryptingHandler.hpp"


namespace Services {
	/*
	Functional class that can decrypt an encrypted file.
	*/
	class Decrypter : public CryptingHandler {
		using CryptingHandler::CryptingHandler;

		char decrypt_cesar(char);
		char decrypt_xor(char);
	public:

		/*
		Decrypt a file given the options specified to the constructor.
		*/
		void decrypt();
	};
}

