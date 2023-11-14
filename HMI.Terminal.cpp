#include "HMI.Terminal.hpp"
#include <iostream>


namespace HMI {
	_TerminalClass::_TerminalClass() {}
	const char* _TerminalClass::readLine() {
        char* out;
        std::cout << '>';
        std::string input;
        std::cin >> input;
        out = new char[input.length() + 1];
        std::memcpy(out, input.c_str(), input.length());
        out[input.length()] = 0;
        (void)std::getc(stdin);  // std::cin leaves a hanging '\n' caracter in the stream, get rid of it.
        return out;
	}
    int _TerminalClass::readInt(int min, int max) {
        std::cout << '>';
        int input;
        while (1) {
            std::cin >> input;
            if (input < min || input > max) {
                std::cout << "Veuillez entrer un nombre entier entre " << min << " et " << max << ".\n>";
                continue;
            }
            break;
        }
        (void)std::getc(stdin);
        return input;
    }
    int _TerminalClass::readInt() {
        std::cout << '>';
        int input;
        std::cin >> input;
        return input;
    }
    void _TerminalClass::write(const char* msg) {
        std::cout << msg;
    }
    void _TerminalClass::write(long number) {
        std::cout << number;
    }
    void _TerminalClass::writeLine(const char* msg) {
        std::cout << msg << "\n";
    }
    void _TerminalClass::writeLine(long number) {
        std::cout << number << "\n";
    }
    void _TerminalClass::writeLine() {
        std::cout << "\n";
    }
    void _TerminalClass::pause() {
        int c;
        while (1) {
            c = std::getc(stdin);
            if ((char)c == '\n')
                break;
            std::cout << '\'' << c << "'\n";
        }
    }

    _TerminalClass Terminal;
}

