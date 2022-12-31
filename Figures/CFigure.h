#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:

	static int count;
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	Point Center; //Center of the figure
	bool Hidden;
	/// Add more parameters if needed.
	static int ArrOfColors[];

public:
	
	 int* getArrOfColors();

	CFigure(); //to allow zero argument constructor in children
	CFigure(GfxInfo FigureGfxInfo);
	void ResetArrOfClrs();
	static void resetID();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	bool IsHidden() const;
	void SetHidden(bool) ;
	int GetID();
	void SetID(int);
	Point GetCenter();
	GfxInfo GetGfxInfo()const;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void ChngGfxInfo(GfxInfo);
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool IsInside(int,int) = 0; //checks if the points clicked are inside a figure
	virtual void Move(int, int) = 0; //Moving center of figures to the new point
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	void incrementArrOfClrs();
	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output*) = 0;	//print all figure info on the status bar

	//converting color type to string to be able to write it in text files
	string convertcolorToString(color color);
	//converting string type to color to be able to read it from text files
	color convertStringToColor(string color);
	virtual string GetFigureType()=0;
	
};

#endif