#include "SelectOneAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp)
{}
void SelectOneAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a Figure");

	//Reads a point and stores it in P
	pIn->GetPointClicked(P.x, P.y);
}
void SelectOneAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* FigPtr = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure
	CFigure* SelectedFig = pManager->GetSelectedFigure(); //Returns the old selected figure
	if (SelectedFig == NULL && FigPtr == NULL) {
		pOut->PrintMessage("A Click on an Empty Area");
	}
	else if (SelectedFig == NULL && FigPtr != NULL) {
		FigPtr->SetSelected(1);
		pManager->SetSelectedFigure(FigPtr);
	}
	else if (SelectedFig == FigPtr) {
		SelectedFig->SetSelected(0);
		FigPtr->SetSelected(0);
		pManager->SetSelectedFigure(NULL);
	}
	else if (SelectedFig->IsSelected() == 1 && FigPtr != NULL) {
		SelectedFig->SetSelected(0);
		FigPtr->SetSelected(1);
		pManager->SetSelectedFigure(FigPtr);
	}




	//if (SelectedFig != NULL && SelectedFig->IsSelected() == 1) {//Cases for selected figure
		//if (SelectedFig == FigPtr) {
		//	SelectedFig->SetSelected(0);
		//}
		//else if (SelectedFig != FigPtr) {
			//SelectedFig->SetSelected(0);
		//	FigPtr->SetSelected(1);
		//}
	//}
	//else {
	//	FigPtr->SetSelected(1);
	//}
}