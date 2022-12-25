#include "CRectangle.h"
#include <fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInside(int x, int y){ //Checking if the point is inside the rectangle
	if ((x >= Corner1.x && x <= Corner2.x || x <= Corner1.x && x >= Corner2.x) && (y >= Corner1.y && y <= Corner2.y || y <= Corner1.y && y >= Corner2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}
void CRectangle :: Move(int x, int y) {
	int xcenter = (Corner1.x + Corner2.x) / 2;//getting x coordinates of center of rectangle
	int ycenter = (Corner1.y + Corner2.y) / 2;//getting y coordinates of center of rectangle
	int xtranslate = xcenter-x;
	int ytranslate= ycenter-y;
	Corner1.x -= xtranslate; //translating points
	Corner1.y -= ytranslate;
	Corner2.x -= xtranslate;
	Corner2.y -= ytranslate;
}
void CRectangle::PrintInfo(Output* pOut) {
	int length = abs(Corner1.x-Corner2.x)>=abs(Corner1.y-Corner2.y)? abs(Corner1.x - Corner2.x): abs(Corner1.y - Corner2.y);
	int width = abs(Corner1.x - Corner2.x) < abs(Corner1.y - Corner2.y) ? abs(Corner1.x - Corner2.x) : abs(Corner1.y - Corner2.y);
	string MESSAGE = "Figure Type: Rectangle, ID: " + to_string(ID) + ", Corners Points:(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")-(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length="+to_string(length)+", Width="+to_string(width);
	pOut->PrintMessage(MESSAGE);
}
void CRectangle::Save(ofstream& outputFile) {
	outputFile << "RECT" << " " << getid() << " "
		<< Corner1.x << " " << Corner1.y << " "
		<< Corner2.x << " " << Corner2.y << " "
		<< convertcolorToString(currentGfxInfo.DrawClr) << " "
		<< ((currentGfxInfo.FillClr == BLACK) ? "NO_FILL" : convertcolorToString(currentGfxInfo.FillClr)) << endl;

}