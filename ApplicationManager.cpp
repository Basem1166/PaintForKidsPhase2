
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
#include"Actions\ToDraw.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\ChangeFillAction.h"
#include "Actions\ChangHighlightAction.h"
#include "Actions\PickByColor.h"
#include"Actions\StartRecordingAction.h"
#include"Actions\StopRecordingAction.h"
#include"Actions\PlayRecordingAction.h"
#include"Actions\PickByShapeAction.h"
#include"Actions\ToggleMuteAction.h"
#include"Actions\PickByBothAction.h"
#include"Actions\ClearAllAction.h"
#include"Actions\ExitAction.h"
#include<Windows.h>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	UndoListCurrentSize = 0;
	RedoListCurrentSize = 0;
	RecordingListCount = 0;
	ActionsListCurrentSize = 0;
	WillRecord = 0;
	MuteState = false;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
	for(int i=0;i<5;i++)
	{
		UndoList[i] = NULL;
		RedoList[i] = NULL;
	}
	for (int i = 0; i < 200; i++)
	{
		ActionsList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
void ApplicationManager::AddActionToUndoList(Action* pAct)
{
	if (UndoListCurrentSize < 5)
	{
		UndoList[UndoListCurrentSize++] = pAct;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			UndoList[i] = UndoList[i + 1];
		}
		UndoList[4] = pAct;
	}
	RedoListCurrentSize = 0;
	for (int i = 0; i < 5; i++)
	{
		RedoList[i] = NULL;
	}
}
void ApplicationManager::AddActionToActionsList(Action* pAct)
{
	if (ActionsListCurrentSize < 200)
	{
		ActionsList[ActionsListCurrentSize++] = pAct;
	}
	else
	{
		if (ActionsList[0] != NULL)
		{
			delete ActionsList[0];
		}
		for (int i = 0; i < 199; i++)
		{
			ActionsList[i] = ActionsList[i + 1];
		}
		ActionsList[199] = pAct;
	}
}
void ApplicationManager::UndoPrevAction()
{
	if (UndoListCurrentSize > 0)
	{
		UndoListCurrentSize--;
		RedoList[RedoListCurrentSize++] = UndoList[UndoListCurrentSize];
		UndoList[UndoListCurrentSize]->Undo();
		UndoList[UndoListCurrentSize] = NULL;
	}
}
void ApplicationManager::RedoPrevAction()
{
	if(RedoListCurrentSize>0)
	{
		RedoListCurrentSize--;
		UndoList[UndoListCurrentSize++] = RedoList[RedoListCurrentSize];
		RedoList[RedoListCurrentSize]->Redo();
		RedoList[RedoListCurrentSize] = NULL;
	}
}
bool ApplicationManager::IsFoundInFigList(CFigure* PassedFig)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (PassedFig == FigList[i])
		{
			return true;
		}
	}
	return false;
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
				pAct = new DeleteFigureAction(this);
			break;
		case MOVE_SHAPE:
				pAct = new MoveFigureAction(this);
			break;
		case SAVE_GRAPH:
				pAct = new SaveAction(this);
			break;
		case LOAD_GRAPH:
			pAct = new LoadAction(this);
			break;
		case By_color:
			pAct = new PickByColor(this);
			break;
		case TO_DRAW:
			pAct = new ToDraw(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;
		case FILL:
			pAct = new ChangeFillAction(this);
			break;
		case ChangeDraw:
			pAct = new ChangeHighlightAction(this);
			break;
		case START_RECORDING:
			pAct = new StartRecordingAction(this);
			break;
		case STOP_RECORDING:
			pAct = new StopRecordingAction(this);
			break;
		case PLAY_RECORDING:
				pAct = new PlayRecordingAction(this);
			break;
		case By_Type:
			pAct = new PickByShapeAction(this);
			break;
		case Mute:
			pAct = new ToggleMuteAction(this);
			break;
		case Type_color:
			pAct = new PickByBothAction(this);
			break;
		case CLEAN_ALL:
			pAct = new ClearAllAction(this);
			break;
		case EXIT:
			pAct = new ExitAction(this);
			break;
		default:
			return;
	}

	//Execute the created action
	AddActionToActionsList(pAct);
	pAct->Execute(0, "dummy", 1);
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
	
	for (int i = c; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1];
	}

	FigList[FigCount-1] = NULL;
	--FigCount;
	if (pFig == SelectedFig)
	{
		SelectedFig = NULL;
	}
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

int ApplicationManager:: getFigCount() {
	return FigCount;
}
bool ApplicationManager::IsMute()
{
	return MuteState;
}
void ApplicationManager::ToggleMute()
{
	MuteState = !MuteState;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) {

		if ((FigList[i]->IsHidden()) )
		{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
		
	}
	
	
		
}
CFigure* ApplicationManager::GetRandFig()
{
	int RandIndex = rand() % FigCount + 0;
	return FigList[RandIndex];
}
int ApplicationManager::GetNumberofSelectedFigure(CFigure* PlayFig)
{
	int counter = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (PlayFig->GetFigureType()==FigList[i]->GetFigureType())
		{
			counter++;
		}

	}
	return counter;
}
int ApplicationManager::GetNumberofSelectedFigure(CFigure* PlayFig, GfxInfo GfxInfo)
{
	int counter = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (PlayFig->GetFigureType() == FigList[i]->GetFigureType() && GfxInfo.FillClr == FigList[i]->GetGfxInfo().FillClr)
		{
			counter++;
		}

	}
	return counter;
}
void ApplicationManager::Reset() {
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetHidden(1);
	}
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

bool ApplicationManager::IsEmpty()
{
	if (FigCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	};
}

void ApplicationManager::PlayRecording()
{

	
	for (int i = 0; i < RecordingListCount; i++)
	{

		RecordingList[i]->Execute(1, "dummy", 1);
		UpdateInterface();
		
		if (i%2!=0)
		{
			Sleep(1000);
		}
		

	}
	
}
CFigure* ApplicationManager::drawnFigures(int i) const
{
	return FigList[i];
}
void ApplicationManager::AddRecordingFigure(Action* rAction)
{
	if (RecordingListCount < 20) {
		RecordingList[RecordingListCount++] = rAction;
	}
	else
	{
		pOut->PrintMessage("Recording Capacity Reached");
		Sleep(1000);
		Action* pAct = new StopRecordingAction(this);
		pAct->Execute(0,"dummy",1);
		delete pAct;
	}
}
bool ApplicationManager::getWillRecord()
{
	return WillRecord;
}
void ApplicationManager::setWillRecord(bool willrecord)
{
	WillRecord = willrecord;
}
int ApplicationManager::GetRecordingListCount()
{
	return RecordingListCount;
}
void ApplicationManager::clearAll() {
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) {
		FigList[i] = NULL;
	}
	FigCount = 0;
}
void ApplicationManager::ResetData()
{
	pOut->ClearDrawArea();
	for (int i = 0; i < 200; i++)
	{
		if (ActionsList[i])
		{
			delete ActionsList[i];
			ActionsList[i] = NULL;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		UndoList[i] = NULL;
	}
	for (int i = 0; i < 5; i++)
	{
		RedoList[i] = NULL;
	}
	for (int i = 0; i < RecordingListCount; i++)
	{
		RecordingList[i] = NULL;
	}
	for (int i = 0; i < MaxFigCount; i++)
	{
		if (FigList[i])
			delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	UndoListCurrentSize = 0;
	RedoListCurrentSize = 0;
	RecordingListCount = 0;
	ActionsListCurrentSize = 0;
	WillRecord = 0;
	MuteState = false;
	SelectedFig = NULL;
	CFigure::resetID();
	UI.isFilled = false;
	UI.DrawColor = BLUE;
}
//pick by color 
void ApplicationManager::ArrOfclr() {
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->incrementArrOfClrs();
	}
}

void ApplicationManager::ResetArrOfclr() {
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->ResetArrOfClrs();
	}
}