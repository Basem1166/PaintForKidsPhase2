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
	pOut->ClearStatusBar();
}
void SelectOneAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* FigNew = pManager->GetFigure(P.x, P.y); //Checks if the points clicked are inside a figure
	CFigure* SelectedFig = pManager->GetSelectedFigure(); //Returns the old selected figure
	if (FigNew == NULL) {
		pOut->PrintMessage("A Click on an Empty Area");
	}
	else if (SelectedFig == NULL && FigNew != NULL) {
		FigNew->SetSelected(1);
		pManager->SetSelectedFigure(FigNew);
		FigNew->PrintInfo(pOut);
	}
	else if (SelectedFig == FigNew) {
		SelectedFig->SetSelected(0);
		FigNew->SetSelected(0);
		pManager->SetSelectedFigure(NULL);
		pOut->PrintMessage("Figure Unselected");
	}
	else if (SelectedFig->IsSelected() == 1 && FigNew != NULL) {
		SelectedFig->SetSelected(0);
		FigNew->SetSelected(1);
		pManager->SetSelectedFigure(FigNew);
		FigNew->PrintInfo(pOut);
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