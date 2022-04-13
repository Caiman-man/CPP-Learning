#include "StringsException.h"
#include <iostream>
using namespace std;
StringsException::StringsException(const int code, const char* msg)
{
	error_code = code;
	if (strlen(msg) < 128) 
		strcpy(this->message, msg);
}

void StringsException::PrintException()
{
	cout << "ERROR! " << message << ", Code: " << error_code << endl;
}