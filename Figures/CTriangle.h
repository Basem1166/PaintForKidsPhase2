#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	GfxInfo currentGfxInfo;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	virtual void Move(int, int);
	virtual void PrintInfo(Output*);
	void Save(ofstream& outputFile);
};

#endif