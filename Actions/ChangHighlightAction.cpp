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
	pOut->PrintMessage("Please Choose Highlight Colour");
	ColorAct = pIn->GetUserAction();

}
bool ChangeHighlightAction::GetHighlightColour(ActionType ColorAct)//changing the draw color
{
	if (ColorAct == C_BLACK)
	{
		UI.DrawColor = BLACK;
		return 1;
	}
	else if (ColorAct == C_YELLOW)
	{
		UI.DrawColor = YELLOW;
		return 1;
	}
	else if (ColorAct == C_ORANGE)
	{
		UI.DrawColor = ORANGE;
		return 1;
	}
	else if (ColorAct == C_RED)
	{
		UI.DrawColor = RED;
		return 1;
	}
	else if (ColorAct == C_GREEN)
	{
		UI.DrawColor = GREEN;
		return 1;
	}
	else if (ColorAct == C_BLUE)
	{
		UI.DrawColor = BLUE;
		return 1;
	}
	else {
		return 0;
	}
}

//Execute the action
void ChangeHighlightAction::Execute() {
	
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* SelectedFigure = pManager->GetSelectedFigure();
	if (GetHighlightColour(ColorAct)) {
		SelectedFigure->ChngDrawClr(UI.DrawColor);//changing draw color for selected figure


	}
	else {
		pOut->PrintMessage("Clicked on an invalid point");
	}
}

void ChangeHighlightAction::Undo() {}
void ChangeHighlightAction::Redo() {}