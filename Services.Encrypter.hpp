#pragma once
#include "Components.File.hpp"
#include "Components.EncryptionKind.hpp"
#include "Services.FileEncryptionOperation.hpp"


namespace Services {
	/*
	Functional class that can encrypt files.
	*/
	class Encrypter : public FileEncryptionOperation {
		using FileEncryptionOperation::FileEncryptionOperation;

		char cesarTransform(char, uint8_t) override;
		char xorTransform(char, uint8_t) override;

	};
}

