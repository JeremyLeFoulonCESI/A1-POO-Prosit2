#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"


namespace Services {
	/*
	Base class which implements common behaviour of the
	Encrypter and Decrypter classes.
	*/
	class CryptingHandler
	{
	protected:
		Components::File* src;
		Components::File* dst;
		Components::EncryptionKind encryption_kind;
		uint8_t key;

	public:
		/*
		Initialize the encrypter / decrypter with information
		on how to do the operation.
		*/
		CryptingHandler(const char* src_filename, const char* dst_filename, uint8_t encryptionKind, uint8_t key);
		/*
		The key used to encrypt / decrypt.
		*/
		uint8_t getKey();
		/*
		The path of the file from which to read the input data.
		*/
		const char* getSource();
		/*
		The path of the file in which to write the output data.
		*/
		const char* getDestination();
		/*
		Whether the options provided to this encrypter / decrypter
		are all valid.
		*/
		bool isValid();
		// deallocates the File pointers owned by this class.
		~CryptingHandler();
	};
}

