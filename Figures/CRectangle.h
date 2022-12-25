#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	GfxInfo currentGfxInfo;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	virtual void PrintInfo(Output*);
	void Save(ofstream& outputFile);
};

#endif