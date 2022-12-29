#pragma once
#include "PickByColor.h"
#include "..\ApplicationManager.h"
#include"SaveAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PickByColor::PickByColor(ApplicationManager* pApp) :Action(pApp)
{
	numOfcolors = 0;
	wrgSel = 0;
	rigSel = 0;
	for (int i = 0;i < 6;i++)
		clrs[i] = 0;
}


color PickByColor::AssignColor(CFigure* Fig)
{
	if (Fig->GetGfxInfo().isFilled)
	{
		if (Fig->GetGfxInfo().FillClr == BLACK)
			return BLACK;
		else if (Fig->GetGfxInfo().FillClr == YELLOW)
			return YELLOW;
		else if (Fig->GetGfxInfo().FillClr == ORANGE)
			return ORANGE;
		else if (Fig->GetGfxInfo().FillClr == RED)
			return RED;
		else if (Fig->GetGfxInfo().FillClr == GREEN)
			return GREEN;
		else if (Fig->GetGfxInfo().FillClr == BLUE)
			return BLUE;
	}
}

void PickByColor::PrntScore(int S)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (S == 1)
	{
		rigSel++;
		message = "Right!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else 	if (S == 2)
	{
		wrgSel++;
		message = "Wrong!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	pOut->PrintMessage(message);


}



void PickByColor::ReadActionParameters()
{

	for (int i = 0; i < pManager->getFigCount();i++) {
		Fig = pManager->drawnFigures(i);
		if (Fig->GetGfxInfo().isFilled) //counts color occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
				clrs[0]++;
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
				clrs[1]++;
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
				clrs[2]++;
			else if (Fig->GetGfxInfo().FillClr == RED)
				clrs[3]++;
			else if (Fig->GetGfxInfo().FillClr == GREEN)
				clrs[4]++;
			else if (Fig->GetGfxInfo().FillClr == BLUE)
				clrs[5]++;

		}

	}

	for (int i = 0;i < 6;i++)
		if (clrs[i] != 0)numOfcolors++;


}


void PickByColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (numOfcolors > 1)
	{
		//Figure clicked to be hidden
		CFigure* clickedFig;
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->drawnFigures(rand_fig_no);
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				picked_color_no = clrs[0];
				pOut->PrintMessage("Pick up figures colored black!");
			}
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
			{
				picked_color_no = clrs[1];
				pOut->PrintMessage("Pick up figures colored yellow!");
			}
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
			{
				picked_color_no = clrs[2];
				pOut->PrintMessage("Pick up figures colored orange!");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				picked_color_no = clrs[3];
				pOut->PrintMessage("Pick up figures colored red!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				picked_color_no = clrs[4];
				pOut->PrintMessage("Pick up figures colored green!");

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				picked_color_no = clrs[5];
				pOut->PrintMessage("Pick up figures colored blue!");

			}
		}

		while (picked_color_no > 0)
		{

			pIn->GetPointClicked(point.x, point.y);
			if (point.y > UI.ToolBarHeight || point.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(point.x, point.y);
				if (clickedFig != NULL)
				{

					if ((Fig->GetGfxInfo().isFilled && clickedFig->GetGfxInfo().isFilled )&&( Fig->GetGfxInfo().FillClr == clickedFig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->HideShape();
						pManager->DeleteFigure(Fig);
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else
					{
						PrntScore(2);
						clickedFig->HideShape();
						pManager->DeleteFigure(Fig);
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pOut->PrintMessage("Toolbar clicked, game aborted.");
				picked_color_no = -1;
			}


		}
		if (picked_color_no == 0)
			PrntScore(3);

	}
	else
		pOut->PrintMessage("You must have at least two or more colors to play pick by color!");

	for (int i = 0; i < pManager->getFigCount();i++)
	{
		pManager->drawnFigures(i)->ShowShape();
		//pManager->AddFigure(Fig);
	}
		
	pManager->UpdateInterface();
}

PickByColor::~PickByColor()
{
}

void PickByColor::Undo() {}

void PickByColor::Redo() {}