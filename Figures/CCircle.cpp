#include "CCircle.h"
#include <fstream> 
#include"..\Actions\SaveAction.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;

}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCir(Point1, Point2, FigGfxInfo, Selected);
}
bool CCircle::IsInside(int x, int y){ //Checking if the point is inside the rectangle
	float radius = sqrt(pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point2.y), 2));//calculating radius
	if (sqrt(pow((Point1.x - x), 2) + pow((Point1.y - y), 2)) <= radius) {
		return 1;
	}
	else {
		return 0;
	}
}
void CCircle::Move(int x, int y) {
	int xtranslate = Point1.x-x;//calculating the needed translate for new point 2 x cooridantes
	int ytranslate = Point1.y-y;//calculating the needed translate for new point 2 y cooridantes
	Point1.x = x; //translating points to new coordinates
	Point1.y = y;
	Point2.x -= xtranslate;
	Point2.y -= ytranslate;

}
void CCircle::PrintInfo(Output* pOut) {
	string MESSAGE = "Figure Type: Circle, ID: " + to_string(ID) + ", Center Point:(" + to_string(Point1.x) + "," + to_string(Point1.y) + ")-Radius="+to_string(sqrt(pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point2.y), 2)));
	pOut->PrintMessage(MESSAGE);
}

void CCircle::Save(ofstream& outputFile) {
	outputFile << "CIRC" <<" "<< getid() << " " 
		<< Point1.x << " " << Point1.y   << " "
		<< Point2.x << " " << Point2.y   << " "
		<< convertcolorToString(currentGfxInfo.DrawClr)<<" "
		<< ((currentGfxInfo.FillClr == BLACK) ? "NO_FILL" : convertcolorToString(currentGfxInfo.FillClr)) << endl;
	
}