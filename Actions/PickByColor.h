#pragma once
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class PickByColor :public Action
{
	CFigure *fig;
	Point point;
	int CorrectPicks;
	int WrongPicks;
	color PlayingColor;
	string Fig;
public:

	PickByColor(ApplicationManager* pApp); //thats allow application manager to execute loadaction

	void ReadActionParameters();

	void Execute();

	color RandClr(int& Count) const;

	void Undo();

	void Redo();
	~PickByColor(void);
};
