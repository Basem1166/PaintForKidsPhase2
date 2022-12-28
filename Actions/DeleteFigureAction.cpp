#include "DeleteFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}
void DeleteFigureAction::ReadActionParameters()
{}

//Execute the action
void DeleteFigureAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	FigPtr = pManager->GetSelectedFigure();

	//Delete  selected  figure

	pManager->DeleteFigure(FigPtr);
	pOut->PrintMessage("Deleted Figure");
}
void DeleteFigureAction::Undo()
{
	
}

void DeleteFigureAction::Redo()
{

}