#pragma once
#include <cstdio>


namespace Components {
	/*
	Class describing a file.
	This type is required to be dynamically allocated.
	*/
	class File {
		FILE* handle;
		const char* path;

		File(FILE*, const char*);
	public:
		/*
		Allocates dynamically and returns a new File object 
		pointing to a newly created file on disk.
		Returns an invalid File object in case of error.
		*/
		static File* create(const char* path);
		/*
		Allocates dynamically and returns a new File object
		pointing to an already existing file on disk.
		Returns an invalid File object in case of error.
		*/
		static File* open(const char* path);

		/*
		Read a single character from the current file.
		Returns 0 on error, and 1 otherwise.
		*/
		bool readChar(char* out);
		/*
		Write a single character to the current file.
		Returns 0 on error, and 1 otherwise.
		*/
		bool writeChar(char toWrite);
		/*
		Return whether the current File object is valid.
		Invalid File objects cannot be written to nor read from.
		*/
		bool isValid();

		/*
		Return if the file designated by the specified
		path on disk exists. 
		Returns 0 if the path is not a file.
		*/
		static bool exists(const char* path);

		~File();
	};
}

