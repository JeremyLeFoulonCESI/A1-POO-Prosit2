#include "Components.File.hpp"

// ignore deprecation of function 'fopen':
#pragma warning(disable : 4996)


namespace Components {
	File::File(FILE* fs, const char* filename) {
		if (!fs) {
			this->handle = nullptr;
			this->path = "";
			return;
		}
		this->handle = fs;
		this->path = filename;
	}
	File* File::create(const char* path) {
		return new File(std::fopen(path, "wb+"), path);
	}
	File* File::open(const char* path) {
		return new File(std::fopen(path, "rb+"), path);
	}
	bool File::readChar(char* out) {
		if (!this->isValid())
			return false;
		int res = std::fgetc(this->handle);
		if (res == EOF)
			return false;
		*out = (char)res;
		return true;
	}
	bool File::writeChar(char toWrite) {
		char res = std::fputc(toWrite, this->handle);
		return res != EOF;
	}
	const char* File::getFilePath() {
		if (!this->isValid())
			return nullptr;
		return this->path;
	}
	bool File::isValid() {
		return this->handle != nullptr;
	}
	bool File::exists(const char* path) {
		FILE* fs = std::fopen(path, "rb");
		if (fs) {
			std::fclose(fs);
			return 1;
		}
		return 0;
	}
	File::~File() {
		if (this->isValid()) {
			std::fclose(this->handle);
			this->handle = nullptr;
		}
	}
}

