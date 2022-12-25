#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	GfxInfo currentGfxInfo;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int) ;
	virtual void PrintInfo(Output*) ;
	void Save(ofstream& outputFile);
};

#endif
