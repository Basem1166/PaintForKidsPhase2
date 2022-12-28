#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class  TO_DRAW :public Action
{
	Output* pOut ;
	Input* pIn ;
public:

	TO_DRAW(ApplicationManager* pApp);

	~TO_DRAW(void);

	void ReadActionParameters();
	void Execute();

	void Undo();

	void Redo();
};