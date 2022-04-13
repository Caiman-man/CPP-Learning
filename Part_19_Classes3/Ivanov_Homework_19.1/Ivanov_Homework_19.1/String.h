#pragma once
class String
{
	char* m_str;
public:
	String();
	String(const char* str);
	String(const String& source);
	~String();
	String& operator= (const String& source);
	bool operator == (const String& source);
	bool operator != (const String& source);
	bool operator <= (const String& source);
	bool operator >= (const String& source);
	String operator + (String& source);
	String operator - (char ch);
	void Print();
};

