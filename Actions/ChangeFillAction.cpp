#include "ChangeFillAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "../DEFS.h"
ChangeFillAction::ChangeFillAction(ApplicationManager* pApp) :Action(pApp)
{}
void ChangeFillAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Choose Fill Colour");
	ColorAct=pIn->GetUserAction();
	pOut->ClearStatusBar();

}
bool ChangeFillAction::GetFillColour(ActionType ColorAct) {
	if (ColorAct == C_BLACK)
	{
		UI.FillColor = BLACK;
		NewGfxInfo.FillClr = BLACK;
		return 1;
	}
	else if (ColorAct == C_YELLOW)
	{
		UI.FillColor = YELLOW;
		NewGfxInfo.FillClr = YELLOW;
		return 1;
	}
	else if (ColorAct == C_ORANGE)
	{
		UI.FillColor = ORANGE;
		NewGfxInfo.FillClr = ORANGE;
		return 1;
	}
	else if (ColorAct == C_RED)
	{
		UI.FillColor = RED;
		NewGfxInfo.FillClr = RED;
		return 1;
	}
	else if (ColorAct == C_GREEN)
	{
		UI.FillColor = GREEN;
		NewGfxInfo.FillClr = GREEN;
		return 1;
	}
	else if (ColorAct == C_BLUE)
	{
		UI.FillColor = BLUE;
		NewGfxInfo.FillClr = BLUE;
		return 1;
	}
	else {
		return 0;
	}
}

//Execute the action
void ChangeFillAction::Execute(bool WillRecord, string filename, bool where ) {
	if(!WillRecord)
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	FigPtr = pManager->GetSelectedFigure();
	OldGfxInfo = FigPtr->GetGfxInfo();
	NewGfxInfo = OldGfxInfo;

	if (GetFillColour(ColorAct)) {
		UI.isFilled = true;
		NewGfxInfo.isFilled = true;
		FigPtr->ChngFillClr(UI.FillColor); //changing the fill color
	}
	else {
		pOut->PrintMessage("Please Click on a Colour icon");
	}
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}

void ChangeFillAction::Undo()
{
	FigPtr->ChngGfxInfo(OldGfxInfo);
}

void ChangeFillAction::Redo()
{
	FigPtr->ChngGfxInfo(NewGfxInfo);
}