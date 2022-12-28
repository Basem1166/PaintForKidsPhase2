#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\SelectOneAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\SaveAction.h"
#include".\Figures\CFigure.h"
#include "Actions\MoveFigureAction.h"
#include"Actions\Action.h"
#include"Actions\RedoAction.h"
#include"Actions\UndoAction.h"
#include "Actions\LoadAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	UndoRedoCount = 0;
	ActionListSize = 0;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
void ApplicationManager::UndoPrevAction()
{
	if (UndoRedoCount < 5 && ActionListSize>0) {
		UndoRedoCount++;
		ActionList[--ActionListSize]->Undo();
		SelectedFig = NULL;
	}
}
void ApplicationManager::RedoPrevAction()
{
	if (UndoRedoCount > 0 && ActionListSize < 5) {
		UndoRedoCount--;
		ActionList[ActionListSize++]->Redo();
		SelectedFig = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQR:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case SelectOne:
			pAct = new SelectOneAction(this);
			break;
		case _DELETE:
			if(GetSelectedFigure()!=NULL)
			pAct = new DeleteFigureAction(this);
			break;
		case MOVE_SHAPE:
			if (GetSelectedFigure() != NULL)
				pAct = new MoveFigureAction(this);
			break;
		case SAVE_GRAPH:
				pAct = new SaveAction(this);
			break;
		case LOAD_GRAPH:
			pAct = new LoadAction(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if (pAct != NULL)
	{
		if (ActType <= 12)
		{
			if (ActionListSize < 5)
			{
				ActionList[ActionListSize++] = pAct;
			}
			else
			{
				if (ActionList[0])
					delete ActionList[0];
				for (int i = 0; i < ActionListSize - 1; i++)
				{
					ActionList[i] = ActionList[i + 1];
				}
				ActionList[ActionListSize - 1] = NULL;
			}
			UndoRedoCount = 0;
			pAct->Execute();//Execute
		}
		else
		{
			pAct->Execute();//Execute
			delete pAct;
			pAct = NULL;
		}
	}
}
void ApplicationManager::SetSelectedFigure(CFigure* fig)
{
	SelectedFig = fig;
}
CFigure* ApplicationManager::GetSelectedFigure()//returns a pointer to the selected figure
{
	return SelectedFig;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteFigure(CFigure* pFig) {
	int c=-1 ;

	for (int i = 0; i < FigCount; i++) {
		
		if(FigList[i] == pFig) {
			c = i;
			break;
		}
	}
	
	for (int i = c; i < FigCount - 2; i++) {
		FigList[i] = FigList[i + 1];
	}

	FigList[--FigCount] = NULL;
	SelectedFig = NULL;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->IsInside(x, y)) {
			return FigList[i];
		}
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

///////////////////////////////////////////////////////////////////////////////////
//save & load management functions RHG


void ApplicationManager::SaveFigcount(ofstream& outputFile) { //writing figcount into the file
	outputFile << to_string(FigCount) << endl;
}

void ApplicationManager::SaveAll(ofstream& outputFile) {
	for (int i = 0;i < FigCount;i++) {
		FigList[i]->Save(outputFile);
	}
}
void ApplicationManager::clearAll() {
	pOut->ClearDrawArea();
	for (int i = 0;i < FigCount;i++) {
		FigList[i] = NULL;
	}
	FigCount = 0;
}