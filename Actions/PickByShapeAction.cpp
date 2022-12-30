#include "PickByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"LoadAction.h"
#include"SelectOneAction.h"

PickByShapeAction::PickByShapeAction(ApplicationManager* pApp) :Action(pApp)
{
	NumberOfFiguresOnScreen = pManager->getFigCount();
	CorrectCounter = 0;
	WrongCounter = 0;
}

PickByShapeAction::~PickByShapeAction()
{

}

void PickByShapeAction::UpdateScore(bool Correct)
{
	Output* pOut = pManager->GetOutput();

	if (Correct)
	{
		CorrectCounter++;


	}
	else
	{

		WrongCounter++;
	}

}

void PickByShapeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);

}

void PickByShapeAction::Execute(bool WillRecord, string filename, bool where)
{
	pManager->Reset();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	if (NumberOfFiguresOnScreen < 2) {
		pOut->PrintMessage("You must have at least two or more colors to play pick by shape!");
		return;
	}
	
	CFigure* PlayFig = pManager->GetRandFig();// Random Figure
	string PlayFigureName = PlayFig->GetFigureType();
	//Check the number of this figure on the screen
	int NumberofPlayFigures = pManager->GetNumberofSelectedFigure(PlayFig);
	pOut->PrintMessage("Please Select All the " + PlayFigureName);



	while (NumberofPlayFigures > 0)
	{
		
		ReadActionParameters();
		CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure


		if (FigNew == NULL)
		{
			pOut->PrintMessage("You Clicked An Empty Area");
			continue;
		}
		

		if (PlayFigureName==FigNew->GetFigureType())
		{

			UpdateScore(1);
			FigNew->SetHidden(false);
			pManager->UpdateInterface();
			NumberofPlayFigures--;
			continue;
		}
		
		UpdateScore(0);
	}

	pOut->PrintMessage("Congratulations! Your Final Score --> Correct:" + to_string(CorrectCounter) + " Wrong: " + to_string(WrongCounter));


}

void PickByShapeAction::Undo()
{
}

void PickByShapeAction::Redo()
{
}
