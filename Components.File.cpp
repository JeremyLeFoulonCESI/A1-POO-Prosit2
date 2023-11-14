#include "Components.File.hpp"


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
		return new File(std::fopen(path, "bw+"), path);
	}
	File* File::open(const char* path) {
		return new File(std::fopen(path, "br+"), path);
	}
	bool File::readChar(char* out) {
		if (!this->isValid())
			return false;
		char res = std::fgetc(this->handle);
		if (res == EOF)
			return false;
		*out = res;
		return true;
	}
	bool File::writeChar(char toWrite) {
		char res = std::fputc(toWrite, this->handle);
		return res != EOF;
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

