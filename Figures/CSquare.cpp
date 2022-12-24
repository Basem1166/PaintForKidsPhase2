#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a rectangle on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsInside(int x, int y) { //Checking if the point is inside the square
	if ((x >= Center.x-50 && x <= Center.x+50) && (y >= Center.y-50 && y <= Center.y+50 )) {
		return 1;
	}
	else {
		return 0;
	}
}