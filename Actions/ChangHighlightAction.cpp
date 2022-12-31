#include "ChangHighlightAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeHighlightAction::ChangeHighlightAction(ApplicationManager* pApp) :Action(pApp)
{}
//Reading some parameters
void ChangeHighlightAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FigPtr = pManager->GetSelectedFigure();
	pOut->ClearStatusBar();

}
bool ChangeHighlightAction::GetHighlightColour(ActionType ColorAct)//changing the draw color
{
	if (ColorAct == C_BLACK)
	{
		UI.DrawColor = BLACK;
		NewGfxInfo.DrawClr = BLACK;
		return 1;
	}
	else if (ColorAct == C_YELLOW)
	{
		UI.DrawColor = YELLOW;
		NewGfxInfo.DrawClr = YELLOW;
		return 1;
	}
	else if (ColorAct == C_ORANGE)
	{
		UI.DrawColor = ORANGE;
		NewGfxInfo.DrawClr = ORANGE;
		return 1;
	}
	else if (ColorAct == C_RED)
	{
		UI.DrawColor = RED;
		NewGfxInfo.DrawClr = RED;
		return 1;
	}
	else if (ColorAct == C_GREEN)
	{
		UI.DrawColor = GREEN;
		NewGfxInfo.DrawClr = GREEN;
		return 1;
	}
	else if (ColorAct == C_BLUE)
	{
		UI.DrawColor = BLUE;
		NewGfxInfo.DrawClr = BLUE;
		return 1;
	}
	else {
		return 0;
	}
}

//Execute the action
void ChangeHighlightAction::Execute(bool WillRecord, string filename, bool where )
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (!WillRecord)
	{
		ReadActionParameters();
	}
	if (FigPtr == NULL)
	{
		pOut->PrintMessage("Error! Please Select a figure first");
		return;
	}
	pOut->PrintMessage("Please Choose Highlight Colour");
	ColorAct = pIn->GetUserAction();
	//This action needs to read some parameters first
	FigPtr = pManager->GetSelectedFigure();
	OldGfxInfo = FigPtr->GetGfxInfo();
	NewGfxInfo = OldGfxInfo;

	if (GetHighlightColour(ColorAct)) {
		FigPtr->ChngDrawClr(UI.DrawColor);//changing draw color for selected figure
		pManager->AddActionToUndoList(this);
	}
	else
	{
		pOut->PrintMessage("Please Click on a Colour icon");
	}
	if (pManager->getWillRecord())
	{
		pManager->AddRecordingFigure(this);
	}
}

void ChangeHighlightAction::Undo()
{
	FigPtr->ChngGfxInfo(OldGfxInfo);
}

void ChangeHighlightAction::Redo()
{
	FigPtr->ChngGfxInfo(NewGfxInfo);
}

ChangeHighlightAction::~ChangeHighlightAction()
{

}