#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"

class PickByColor :
	public Action
{
	CFigure* Fig;
	Point point;
	int  numOfcolors;
	int RandomFigNum;
	int NumOfColorsToPicked;
	int WrongPicks;
	int CorrestPicks;
	//int ArrOfColors[6];
	int* ArrayOfColors;
	
public:

	PickByColor(ApplicationManager*);


	void PrntScore(int);

	void ReadActionParameters();

	void Execute(bool WillRecord, string filename, bool where = true);

	void Undo() ;

	void Redo() ;

	~PickByColor();

};