#include "CRectangle.h"
#include "../Actions/SaveAction.h"
#include "../Actions/SaveAction.cpp"

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

void CRectangle::PrintInfo(Output* pOut) {
	int length = abs(Corner1.x-Corner2.x)>=abs(Corner1.y-Corner2.y)? abs(Corner1.x - Corner2.x): abs(Corner1.y - Corner2.y);
	int width = abs(Corner1.x - Corner2.x) < abs(Corner1.y - Corner2.y) ? abs(Corner1.x - Corner2.x) : abs(Corner1.y - Corner2.y);
	string MESSAGE = "Figure Type: Rectangle, ID: " + to_string(ID) + ", Corners Points:(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")-(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length="+to_string(length)+", Width="+to_string(width);
	pOut->PrintMessage(MESSAGE);
}

//void CRectangle::save(ofstream& outputfile) {
//	outputfile << "RECT" << " " << getID() << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << convertcolorToString(FigGfxInfo.DrawClr) << " " 
//		<<( (convertcolorToString(FigGfxInfo.FillClr).empty()) ? "NO_FILL" : convertcolorToString(FigGfxInfo.FillClr)) << endl;
//	return;
//}

