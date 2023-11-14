#pragma once
#include <cstdio>


namespace Components {
	class File {
		FILE* handle;
		const char* path;

		File(FILE*, const char* path);
	public:
		static File* create(const char* path);
		static File* open(const char* path);

		bool readChar(char* out);
		bool writeChar(char toWrite);
		bool isValid();

		static bool exists(const char* path);

		~File();
	};
}

