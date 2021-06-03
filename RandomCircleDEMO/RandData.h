#pragma once
class RandData
{

public:
	RandData();
	void randomShape();
	COLORREF GetColor();
	CPoint GetPosition();
	int GetShapeSize();
	void GetShapeType();
	void SetPositionRange(int nX, int nY);
	int SetShapeRange(int min, int max);
	int MAX;
	int MAXX;
	int MAXY;
	//int MIN();
	int MIN;
};

