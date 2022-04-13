#pragma once
class String
{
	char* m_str;
public:
	String();
	~String();
	void Load(const char filepath[128]);
	void operator() (char ch1, char ch2);
	void Reverse();
	void Save(const char filepath[128]);
	void Print();
};

