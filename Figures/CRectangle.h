#ifndef CRECT_H
#define CRECT_H
#include "../Actions/SaveAction.h"
#include <fstream> 
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(void);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int);
	virtual void PrintInfo(Output*);
	string convertcolorToString(color color);
	void save(ofstream& outputfile) ;
	void load(ifstream& inputfile) ;
};

#endif