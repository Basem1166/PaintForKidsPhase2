#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Point1;
	Point Point2;
public:
	CCircle(void);
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output*) const;
	virtual bool IsInside(int, int);
	void PrintInfo(Output*);
};

#endif