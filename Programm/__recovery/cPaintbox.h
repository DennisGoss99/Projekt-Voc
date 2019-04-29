//---------------------------------------------------------------------------
#ifndef cPaintboxH
#define cPaintboxH

#include <vcl.h>
#include <vector>
#include <math.h>
#include <string>
//---------------------------------------------------------------------------

class PaintBox{

	 private:

		TPaintBox *graph;
		TColor color;

	 public:


		PaintBox(TPaintBox *graph);

		void drawStatistic(std::vector<int> totalWords, std::vector<int> precessedWords, std::vector<int> failedWords);
		void drawRectangle(int X1,int Y1,int X2,int Y2, TColor color);



		void SetColor(TColor color){this->color=color;}
};

#endif
