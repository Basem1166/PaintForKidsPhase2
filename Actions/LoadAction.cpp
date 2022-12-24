//#include "LoadAction.h"
//void LoadAction::ReadActionParameters() {
//
//	//Get a Pointer to the Input / Output Interfaces
//	Output* pOut = pManager->GetOutput();
//	Input* pIn = pManager->GetInput();
//
//	pOut->PrintMessage("Enter Name of File: ");
//	//Read name of file to save graph info into from user
//	this->filename = pIn->GetSrting(pOut);
//
//	//get drawing, filling colors 
//	currentGfxInfo.DrawClr = pOut->getCrntDrawColor();
//	currentGfxInfo.FillClr = pOut->getCrntFillColor();
//
//	pOut->ClearStatusBar();
//}
//
//void LoadAction::Execute() {
//
//	ReadActionParameters();
//	pManager->clearAll();
//
//	//open file that we read from
//	ifstream inputFile;
//	inputFile.open(filename, ios::in); //if we 've used ofstream(write into files) we dont need to open file 
//
//	//read two current draw  ,  fill colours   &  number of shapes in graph 
//	string Current_Draw_Color;
//	string Current_Fill_Color;
//	int Number_of_Figures_n;
//
//	inputFile >> Current_Draw_Color >> Current_Fill_Color >> Number_of_Figures_n;
//	//set two current colours 
//	currentGfxInfo.DrawClr = Current_Draw_Color;
//	currentGfxInfo.FillClr = Current_Fill_Color;
//
//	//reading each shape data from txt to add in Figlist
//	CFigure* MyFigure = NULL;
//
//	for (int i = 0; i < Number_of_Figures_n; i++)
//	{
//		string type;
//		inputFile >> type;
//		if (type == "RECT")
//		{
//			MyFigure = new CRectangle;
//		}
//		else if (type == "SQR")
//		{
//			MyFigure = new CSquare;
//		}
//		else if (type == "TRIANG")
//		{
//			MyFigure = new CTriangle;
//		}
//		else if (type == "CIRC")
//		{
//			MyFigure = new CCircle;
//		}
//		else if (type == "HEX")
//		{
//			MyFigure = new CHexagon;
//		}
//
//		MyFigure->Load(inputFile);
//		pManager->AddFigure(MyFigure);
//	}
//
//
//}
