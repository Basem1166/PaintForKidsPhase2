#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByColor :
	public Action
{
	CFigure* Fig;
	int  numOfcolors, rand_fig_no, picked_color_no, wrgSel, rigSel;
	int clrs[6];
	Point point;
	color AssignColor(CFigure*);
	void PrntScore(int);
public:
	PickByColor(ApplicationManager*);
	~PickByColor();
	void ReadActionParameters();
	void Execute(bool WillRecord, string filename, bool where = true);
	void Undo() ;
	void Redo() ;

};