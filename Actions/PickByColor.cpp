#pragma once
#include "PickByColor.h"
#include "..\ApplicationManager.h"
#include"SaveAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"LoadAction.h"

PickByColor::PickByColor(ApplicationManager* pApp) :Action(pApp)
{
	numOfcolors = 0; WrongPicks = 0;CorrestPicks = 0;

	for (int i = 0;i < 6;i++) {

		ArrOfColors[i] = 0;
	}
		
}

void PickByColor::ReadActionParameters()
{

	for (int i = 0; i < pManager->getFigCount();i++) {

		Fig = pManager->drawnFigures(i);

		if (Fig->GetGfxInfo().isFilled) //counts color occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
				ArrOfColors[0]++;
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
				ArrOfColors[1]++;
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
				ArrOfColors[2]++;
			else if (Fig->GetGfxInfo().FillClr == RED)
				ArrOfColors[3]++;
			else if (Fig->GetGfxInfo().FillClr == GREEN)
				ArrOfColors[4]++;
			else if (Fig->GetGfxInfo().FillClr == BLUE)
				ArrOfColors[5]++;

		}

	}

	for (int i = 0;i < 6;i++)
		if (ArrOfColors[i] != 0)numOfcolors++;


}


void PickByColor::Execute(bool WillRecord, string filename, bool where )
{
	pManager->Reset();
	//for (int i = 0; i < pManager->getFigCount();i++)
	//	pManager->drawnFigures(i)->SetHidden(false);
	//pManager->UpdateInterface();
	//LoadAction* L = new LoadAction(pManager);
	//L->Execute(false, "Details", 0);
	pManager->UpdateInterface();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();

	if (numOfcolors > 1)
	{

		CFigure* ClickedFigure;
		RandomFigNum = rand() % pManager->getFigCount();
		Fig = pManager->drawnFigures(RandomFigNum);

		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				NumOfColorsToPicked = ArrOfColors[0];
				pOut->PrintMessage("pick all black figures !");
			}
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
			{
				NumOfColorsToPicked = ArrOfColors[1];
				pOut->PrintMessage("pick all yellow figures !");
			}
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
			{
				NumOfColorsToPicked = ArrOfColors[2];
				pOut->PrintMessage("pick all orange figures !");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				NumOfColorsToPicked = ArrOfColors[3];
				pOut->PrintMessage("pick all red figures!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				NumOfColorsToPicked = ArrOfColors[4];
				pOut->PrintMessage("pick all green figures!");

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				NumOfColorsToPicked = ArrOfColors[5];
				pOut->PrintMessage("pick all blue figures!");

			}
		}

		while (NumOfColorsToPicked > 0)
		{

			pIn->GetPointClicked(point.x, point.y);

			if (point.y > UI.ToolBarHeight || point.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				ClickedFigure = pManager->GetFigure(point.x, point.y);

				if (ClickedFigure != NULL)
				{

					if ( Fig->GetGfxInfo().FillClr == ClickedFigure->GetGfxInfo().FillClr)
					{
						PrntScore(1);
						ClickedFigure->SetHidden(0);
						//pManager->DeleteFigure(ClickedFigure);
						pManager->UpdateInterface();
						NumOfColorsToPicked--;
					}
					else
					{
						PrntScore(2);
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pOut->PrintMessage("Game ended ! BYE");
				NumOfColorsToPicked = -1;
			}
		}
		if (NumOfColorsToPicked == 0) {
			PrntScore(3);

		}
			
	}
	else
		pOut->PrintMessage("Sorry you should have 2 or more filled colors to play pick by color");
	
	
	
	//delete L;
}

void PickByColor::PrntScore(int x)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (x == 1)
	{
		CorrestPicks++;
		message = "CORRECT!,Score = " + to_string(CorrestPicks) + " Right, and " + to_string(WrongPicks) + " Wrong.";
	}
	else if (x == 2)
	{
		WrongPicks++;
		message = "WRONG TRY Again!,Score = " + to_string(CorrestPicks) + " Right, and " + to_string(WrongPicks) + " Wrong.";
	}
	else
		message = "Congratulations YOU WIN!, Final Score = " + to_string(CorrestPicks) + " Right, and " + to_string(WrongPicks) + " Wrong.";

	pOut->PrintMessage(message);

}


void PickByColor::Undo() {}

void PickByColor::Redo() {}

PickByColor::~PickByColor()
{
}