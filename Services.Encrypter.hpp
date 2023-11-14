#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"
#include "Services.CryptingHandler.hpp"


namespace Services {
	/*
	Functional class that can encrypt files.
	*/
	class Encrypter : public CryptingHandler {
		using CryptingHandler::CryptingHandler;

		char encrypt_cesar(char);
		char encrypt_xor(char);

	public:
		/*
		Encrypt a file given the options specified to the constructor.
		*/
		void encrypt();
	};
}

