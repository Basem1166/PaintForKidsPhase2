#include "TO_DRAW.h"
#include <fstream>
TO_DRAW::TO_DRAW(ApplicationManager* pApp):Action(pApp) {}

TO_DRAW::~TO_DRAW(void) {}

void TO_DRAW::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void TO_DRAW::Execute() {

	pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	//pManager->SaveAll(ofstream & outputFile);
}

void TO_DRAW::Undo() {}

void TO_DRAW::Redo() {}