#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a rectangle on the screen	
	pOut->DrawCir(Point1, Point2, FigGfxInfo, Selected);
}
bool CCircle::IsInside(int x, int y) { //Checking if the point is inside the rectangle
	if (sqrt(pow((Point1.x - x), 2) + pow((Point1.y - y), 2)) <= sqrt(pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point2.y), 2))) {
		return 1;
	}
	else {
		return 0;
	}
}
