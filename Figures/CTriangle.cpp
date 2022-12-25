#include "CTriangle.h"
#include <fstream>
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
void CTriangle::Move(int x, int y) {
	int xcenter = (Corner1.x + Corner2.x + Corner3.x) / 3; //getting intersection of medians of triangle

	int ycenter = (Corner1.y + Corner2.y + Corner3.y) / 3;
	int xtranslate = xcenter - x;//calculating the needed translation in both axis
	int ytranslate = ycenter - y;
	Corner1.x -= xtranslate;//getting y,x coordinates of center of rectangle
	Corner1.y -= ytranslate;
	Corner2.x -= xtranslate;
	Corner2.y -= ytranslate;
	Corner3.x -= xtranslate;
	Corner3.y -= ytranslate;

}
void CTriangle :: PrintInfo(Output* pOut){
	string MESSAGE = "Figure Type: Triangle, ID: " + to_string(ID) + ", Corners Points:(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")-(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")-(" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(MESSAGE);
}
void CTriangle::Save(ofstream& outputFile) {
	outputFile << "TRIANG" << " " << getid() << " "
		<< Corner1.x << " " << Corner1.y << " "
		<< Corner2.x << " " << Corner2.y << " "
		<< Corner3.x << " " << Corner3.y << " "
		<< convertcolorToString(currentGfxInfo.DrawClr) << " "
		<< ((currentGfxInfo.FillClr==BLACK) ? "NO_FILL" : convertcolorToString(currentGfxInfo.FillClr)) << endl;

}