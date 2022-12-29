#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);



	HexaGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
//Execute
void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexaGfxInfo);
	ID = H->GetID();
	//Add the rectangle to the list of figures
	pManager->AddFigure(H);
}
void AddHexaAction::Undo()
{
	Hexagon = new CHexagon(P1, HexaGfxInfo);
	Hexagon->SetID(ID);
	pManager->DeleteLastFigure();
}

void AddHexaAction::Redo()
{
	pManager->AddFigure(Hexagon);
}