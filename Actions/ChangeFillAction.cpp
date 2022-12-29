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
		return 1;
	}
	else if (ColorAct == C_YELLOW)
	{
		UI.FillColor = YELLOW;
		return 1;
	}
	else if (ColorAct == C_ORANGE)
	{
		UI.FillColor = ORANGE;
		return 1;
	}
	else if (ColorAct == C_RED)
	{
		UI.FillColor = RED;
		return 1;
	}
	else if (ColorAct == C_GREEN)
	{
		UI.FillColor = GREEN;
		return 1;
	}
	else if (ColorAct == C_BLUE)
	{
		UI.FillColor = BLUE;
		return 1;
	}
	else {
		return 0;
	}
}

//Execute the action
void ChangeFillAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* SelectedFigure = pManager->GetSelectedFigure();
	if (GetFillColour(ColorAct)) {
		UI.isFilled = true;
		SelectedFigure->ChngFillClr(UI.FillColor); //changing the fill color
	}
	else {
		pOut->PrintMessage("Please Click on a Colour icon");
	}
}

void ChangeFillAction::Undo() {}
void ChangeFillAction::Redo() {}