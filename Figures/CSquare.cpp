#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsInside(int x, int y){ //Checking if the point is inside the square
	if ((x >= Center.x-50 && x <= Center.x+50) && (y >= Center.y-50 && y <= Center.y+50 )) {
		return 1;
	}
	else {
		return 0;
	}
}
void CSquare::Move(int x, int y) {
	Center.x = x; // assigning new centerrr
	Center.y = y;
}
void CSquare::PrintInfo(Output* pOut){
	string MESSAGE = "Figure Type: Square, ID: " + to_string(ID) + ", Center Point:(" + to_string(Center.x) + "," + to_string(Center.y) + "), Side Length=50";
	pOut->PrintMessage(MESSAGE);
}