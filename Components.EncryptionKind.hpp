#pragma once
#include <cstdint>


namespace Components {
	enum class EncryptionKind : uint8_t {
		CESAR = 1,
		XOR = 2,
		CESAR_XOR = 3,
	};
}

