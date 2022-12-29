#include "ToDraw.h"


ToDraw::ToDraw(ApplicationManager* pApp):Action(pApp) {}


void ToDraw::ReadActionParameters() {
	
}

void ToDraw::Execute(bool WillRecord) {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");

	pOut->ClearToolBar();
	pOut->ClearDrawArea();
	SaveAction::Excute(false);


	pOut->CreateDrawToolBar();
	pOut->CreateDrawToolBar();
	//any cleanup have been implmented in distructor of appmanager
	//TODO:i should here load the graph saved in toplaymode RHG
	
	pOut->ClearStatusBar();

}

ToDraw::~ToDraw(void) {}

void ToDraw::Undo() {}

void ToDraw::Redo() {}