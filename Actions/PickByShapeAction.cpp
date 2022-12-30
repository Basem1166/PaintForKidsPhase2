#include "PickByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp) :Action(pApp)
{
	NumberOfFiguresOnScreen = pManager->getFigCount();
}

PickByShapeAction::~PickByShapeAction()
{
}

void PickByShapeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
}

void PickByShapeAction::Execute(bool WillRecord,string filename, bool where)
{
	Output* pOut = pManager->GetOutput();
	if (NumberOfFiguresOnScreen < 2) {
		pOut->PrintMessage("You must have at least two or more colors to play pick by shape!");
		return;
	}

	while (pManager->getFigCount() > 0)
	{
		ReadActionParameters();
		CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure
		CFigure* SelectedFig = pManager->GetSelectedFigure(); //Returns the old selected figure

		if (SelectedFig == NULL)
		{
			pOut->PrintMessage("You Clicked An Empty Area");
		}


	}



}

void PickByShapeAction::Undo()
{
}

void PickByShapeAction::Redo()
{
}
