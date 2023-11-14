#pragma once


namespace HMI {
	/*
	Class for the 'Terminal' object.
	This simply interfaces the current terminal.
	*/
	class _TerminalClass {
	public:
		_TerminalClass();
		/*
		Read a line of text from the terminal.
		*/
		const char* readLine();
		/*
		Read an integer in range [min, max] from the terminal.
		This waits until a matching and valid integer is entered.
		*/
		int readInt(int min, int max);
		/*
		Read in integer from the terminal.
		This waits until a valid integer is entered.
		*/
		int readInt();
		/*
		Write a character array / string to the terminal.
		*/
		void write(const char*);
		/*
		Write an integer to the terminal.
		*/
		void write(long);
		/*
		Write a caracter array / string to the terminal and then
		skip a line.
		*/
		void writeLine(const char*);
		/*
		Write an integer to the terminal and then skip a line.
		*/
		void writeLine(long);
		/*
		Make the terminal skip a line.
		*/
		void writeLine();
		/*
		Wait until the user presses the 'Enter' key.
		*/
		void pause();
	};

	/*
	Object representing the current Human-Machine Interface.
	In this program, this is the terminal.
	*/
	extern _TerminalClass Terminal;
}

