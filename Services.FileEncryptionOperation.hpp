#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"


namespace Services {
	/*
	Base class which implements common behaviour of the
	Encrypter and Decrypter classes.
	*/
	class FileEncryptionOperation
	{
		Components::File* src;
		Components::File* dst;
		Components::EncryptionKind encryption_kind;
		uint8_t key;
		bool order;

	protected:
		virtual char cesarTransform(char src, uint8_t key) = 0;
		virtual char xorTransform(char src, uint8_t key) = 0;
	public:
		void transform();
		/*
		Initialize the encrypter / decrypter with information
		on how to do the operation.
		*/
		FileEncryptionOperation(bool order, const char* src_filename, const char* dst_filename, uint8_t encryptionKind, uint8_t key);
		/*
		Whether the options provided to this encrypter / decrypter
		are all valid.
		*/
		bool isValid();
		// deallocates the File pointers owned by this class.
		~FileEncryptionOperation();
	};
}

