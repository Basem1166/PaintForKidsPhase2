#include "ClearAllAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}

void ClearAllAction::ReadActionParameters()
{}

void ClearAllAction::Execute(bool WillRecord, string filename, bool where)
{
	Output* pOut = pManager->GetOutput();

	pManager->ResetData();

	pOut->PrintMessage("Cleared All Data");
}

void ClearAllAction::Undo()
{

}

void ClearAllAction::Redo()
{

}

ClearAllAction::~ClearAllAction()
{

}