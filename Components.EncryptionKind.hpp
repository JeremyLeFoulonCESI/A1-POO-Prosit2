#pragma once
#include <cstdint>


namespace Components {
	/*
	Enumeration describing the kind of encryption to use.
	*/
	enum class EncryptionKind : uint8_t {
		CESAR = 0b01,
		XOR = 0b10,
		CESAR_XOR = 0b11,
		INVALID = 0b100,
	};
}

