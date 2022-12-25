#ifndef CHEXA_H
#define CHEXA_H
#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	GfxInfo currentGfxInfo;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	void PrintInfo(Output* pOut);
	void Save(ofstream& outputFile);
	virtual void Move(int, int);
};

#endif