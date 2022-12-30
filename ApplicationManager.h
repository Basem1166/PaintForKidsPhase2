#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream> 
#include"Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int WillRecord;
	int FigCount;//Actual number of figures
	Action* UndoList[5];
	Action* RedoList[5];
	Action* RecordingList[20];
	int RecordingListCount;
	int UndoListCurrentSize;
	int RedoListCurrentSize;
	bool MuteState;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void SetSelectedFigure(CFigure*);
	CFigure* GetSelectedFigure();
	void UndoPrevAction();
	void RedoPrevAction();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigure(CFigure*); //Delete the figure from FigList
	bool IsMute();
	void ToggleMute();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//-- Save Management Functions RHG
	void SaveFigcount(ofstream & outputFile);
	void clearAll();
	void SaveAll(ofstream& outputFile);
	CFigure* drawnFigures(int) const;
	int getFigCount();
	//Recording Functions
	bool IsEmpty();
	void PlayRecording();
	void AddRecordingFigure(Action* rAction);//adds figures to the recording list
	void AddActionToUndoList(Action*);
	bool getWillRecord();// setter and getter fir the will record boolean.
	void setWillRecord(bool willrecord);
};

#endif