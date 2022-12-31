#include "PickByBothAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"LoadAction.h"
#include"SelectOneAction.h"

PickByBothAction::PickByBothAction(ApplicationManager* pApp) :Action(pApp)
{
	NumberOfFiguresOnScreen = pManager->getFigCount();
	CorrectCounter = 0;
	WrongCounter = 0;
}

void PickByBothAction::UpdateScore(bool Correct)
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

void PickByBothAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);

}

void PickByBothAction::Execute(bool WillRecord, string filename, bool where)
{
	pManager->Reset();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	if (NumberOfFiguresOnScreen < 2) {
		pOut->PrintMessage("You must have at least two or more Shapes to play pick by both Shape and Color!");
		return;
	}

	CFigure* PlayFig = pManager->GetRandFig();// Random Figure
	string PlayFigureName = PlayFig->GetFigureType();
	GfxInfo FigureGfxInfo = PlayFig->GetGfxInfo();
	if (FigureGfxInfo.isFilled)
	{
		PlayFigureColor = FigureGfxInfo.FillClr;
		StringColor = PlayFig->convertcolorToString(PlayFigureColor);

	}
	else
	{
		StringColor = "NON-FILLED";
	}
	
	//Check the number of this figure on the screen
	int NumberofPlayFigures = pManager->GetNumberofSelectedFigure(PlayFig,PlayFig->GetGfxInfo());
	pOut->PrintMessage("Please Select All the " + StringColor +" " + PlayFigureName + "s");



	while (NumberofPlayFigures > 0)
	{

		ReadActionParameters();
		CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure


		if (FigNew == NULL)
		{
			pOut->PrintMessage("You Clicked An Empty Area");
			continue;
		}


		if (PlayFigureName == FigNew->GetFigureType() && PlayFig->GetGfxInfo().FillClr == FigNew->GetGfxInfo().FillClr )
		{

			UpdateScore(1);
			FigNew->SetHidden(false);
			pManager->UpdateInterface();
			NumberofPlayFigures--;
			pOut->PrintMessage("Correct! Current Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");
			continue;
		}
		UpdateScore(0);
		FigNew->SetHidden(false);
		pManager->UpdateInterface();
		pOut->PrintMessage("Wrong! Try Again! Current Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");

		
	}

	pOut->PrintMessage("Congratulations YOU WIN!, Final Score = " + to_string(CorrectCounter) + " Right, and " + to_string(WrongCounter) + " Wrong.");


}

void PickByBothAction::Undo()
{

}

void PickByBothAction::Redo()
{

}

PickByBothAction::~PickByBothAction()
{

}