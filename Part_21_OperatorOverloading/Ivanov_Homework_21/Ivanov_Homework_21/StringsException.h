#pragma once
class StringsException
{
	int error_code;
	char message[128];
public:
	StringsException(const int code, const char* message);
	void PrintException();
};

