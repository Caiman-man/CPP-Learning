#pragma once
class Points
{
	int m_x;
	int m_y;
public:
	Points();
	Points(int x, int y);
	Points(const Points& source);
	Points& operator = (const Points& source);
	~Points();
	void Save(Points* pnt, const int& size, const char filepath[128]);
	void Load(Points* pnt, const char filepath[128]);
	void Print();
};

