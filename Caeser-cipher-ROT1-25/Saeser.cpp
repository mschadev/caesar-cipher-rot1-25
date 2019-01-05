#include "Saeser.h"
Caeser::Caeser(int Key) : Key(Key) {
}
std::string * Caeser::Encrypt(const char * str) {
	if (Key > 25 || Key < 0) {
		return nullptr;
	}
	std::string * Result = new std::string(str);
	for (int i = 0; i < Result->length(); i++) {
		if ((*Result)[i] >= 'A' && (*Result)[i] <= 'Z' || (*Result)[i] >= 'a' && (*Result)[i] <= 'z') {
			if ((*Result)[i] >= 'A' && (*Result)[i] <= 'Z') {
				if (((*Result)[i] + Key) >= 'Z') {
					(*Result)[i] -= 'Z' - 'A';
					(*Result)[i] += Key;
				}
				else {
					(*Result)[i] += Key;
				}
			}
			if ((*Result)[i] >= 'a' && (*Result)[i] <= 'z') {
				if (((*Result)[i] + Key) >= 'z') {
					(*Result)[i] -= 'z' - 'a';
					(*Result)[i] += Key;
				}
				else {
					(*Result)[i] += Key;
				}
			}
		}
	}
	return Result;
}
std::string *  Caeser::Decrypt(const char * str) {
	if (Key > 25 || Key < 0) {
		return nullptr;
	}
	std::string * Result = new std::string(str);
	for (int i = 0; i < Result->length(); i++) {
		if ((*Result)[i] >= 'A' && (*Result)[i] <= 'Z' || (*Result)[i] >= 'a' && (*Result)[i] <= 'z') {
			if ((*Result)[i] >= 'A' && (*Result)[i] <= 'Z') {
				if (((*Result)[i] - Key) <= 'A') {
					(*Result)[i] += 'Z' - 'A';
					(*Result)[i] -= Key;
				}
				else {
					(*Result)[i] -= Key;
				}
			}
			if ((*Result)[i] >= 'a' && (*Result)[i] <= 'z') {
				if (((*Result)[i] - Key) <= 'a') {
					(*Result)[i] += 'z' - 'a';
					(*Result)[i] -= Key;
				}
				else {
					(*Result)[i] -= Key;
				}
			}
		}
	}
	return Result;
}