#pragma once
#ifndef Saeser
#define Saeser
#include <string>
class Caeser {
private:
	int Key;
public:
	Caeser(int Key = 3);
	std::string & Encrypt(const char * str);
	std::string &  Decrypt(const char * str);
};

#endif // !Saeser
