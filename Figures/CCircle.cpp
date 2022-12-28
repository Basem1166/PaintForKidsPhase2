#include "CCircle.h"
#include <fstream> 
#include"..\Actions\SaveAction.h"

CCircle::CCircle() {}

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
	int xtranslate = Point1.x-x;
	int ytranslate = Point1.y-y;
	Point1.x = x;
	Point1.y = y;
	Point2.x -= xtranslate;
	Point2.y -= ytranslate;

}
void CCircle::PrintInfo(Output* pOut) {
	string MESSAGE = "Figure Type: Circle, ID: " + to_string(ID) + ", Center Point:(" + to_string(Point1.x) + "," + to_string(Point1.y) + ")-Radius="+to_string(sqrt(pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point2.y), 2)));
	pOut->PrintMessage(MESSAGE);
}

void CCircle::Save(ofstream& outputFile) {
	outputFile << "CIRC" <<" "<< GetID() << " " 
		<< Point1.x << " " << Point1.y   << " "
		<< Point2.x << " " << Point2.y   << " "
		<< convertcolorToString(FigGfxInfo.DrawClr)<<" "
		<< ((FigGfxInfo.isFilled) ? convertcolorToString(FigGfxInfo.FillClr) : "NO_FILL") << endl;
	
}
void CCircle::Load(ifstream& inputFile) {
	string id, Point1x, Point1y, Point2x, Point2y,currentdrawclr,currentfillclr;
	inputFile >> id >> Point1x >> Point1y >> Point2x >> Point2y >> currentdrawclr >> currentfillclr;

	//set id
	SetID(stoi(id));

	//set point 1
	Point1.x = stoi(Point1x);
	Point1.y = stoi(Point1y);
	//set point 2
	Point2.x = stoi(Point2x);
	Point2.y = stoi(Point2y);
	//set current drawclr and currentfillclr
	if (FigGfxInfo.DrawClr!=MAGENTA)
	{
		Selected = false;
	}
	FigGfxInfo.DrawClr = convertStringToColor(currentdrawclr);
	if (currentfillclr=="NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW;
	}
	else {
		FigGfxInfo.FillClr = convertStringToColor(currentfillclr);
	}
}