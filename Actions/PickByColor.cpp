#include "PickByColor.h"

PickByColor::PickByColor(ApplicationManager* pApp) :Action(pApp) {
	CorrectPicks = 0;
	WrongPicks = 0;
};

void PickByColor::ReadActionParameters() {

}

void PickByColor::Execute() {
	//underconstruction 
	//RHG
	
	//get random figure 
	//whats color of random figure
	//print pick all yellow figure
	// two integers one for right answers and one for to be picked(3dd el figures eli lounha asfr fi figlist)
	//if right answer == picked game over 
		Input* pIn = pManager->GetInput();
		Output* pOut = pManager->GetOutput();

		int CountOfValidFigures = 0;
	

}




void PickByColor::Undo()
{

}

void PickByColor::Redo()
{

}

