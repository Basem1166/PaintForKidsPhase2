#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = count++;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
int CFigure::count = 1;

string CFigure::convertcolorToString(color color) {

	if (color == BLACK)
	{
		return "BLACK";
	}
	else if (color == YELLOW)
	{
		return "YELLOW";
	}
	else if (color == ORANGE)
	{
		return "ORANGE";
	}
	else if (color == RED)
	{
		return "RED";
	}
	else if (color == GREEN)
	{
		return "GREEN";
	}
	else if (color == BLUE)
	{
		return "BLUE";
	}
	else
	{
		return "NO_FILL";
	}
}
int CFigure::getid() {
	return ID;
}