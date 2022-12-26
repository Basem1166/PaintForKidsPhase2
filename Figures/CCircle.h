#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Point1;
	Point Point2;
	GfxInfo currentGfxInfo;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*) const;
	virtual bool IsInside(int, int);
	void PrintInfo(Output*);
	void Save(ofstream& outputFile);
	virtual void Move(int, int);
};

#endif