#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}
bool CTriangle::IsInside(int x, int y) {
	float A = abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0f);
	float A1 = abs((x * (Corner1.y - Corner2.y) + Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y)) / 2.0f);
	float A2 = abs((x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y)) / 2.0f);
	float A3 = abs((x * (Corner1.y - Corner3.y) + Corner1.x * (Corner3.y - y) + Corner3.x * (y - Corner1.y)) / 2.0f);
	return (A == A1 + A2 + A3);
}
void CTriangle :: PrintInfo(Output* pOut){
	string MESSAGE = "Figure Type: Triangle, ID: " + to_string(ID) + ", Corners Points:(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")-(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")-(" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(MESSAGE);
}