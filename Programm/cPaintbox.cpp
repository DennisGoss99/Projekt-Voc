//---------------------------------------------------------------------------

#pragma hdrstop

#include "cPaintbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PaintBox::PaintBox(TPaintBox *graph){
	this->graph = graph;
}

void PaintBox::drawStatistic(std::vector<int> totalWords, std::vector<int> precessedWords, std::vector<int> failedWords){

	if (graph== NULL) return;

	float biggestValue = 0;
	const static int paintBoxTop = 10;
	const static int StartSpacer = 20;
	const static int spacer = 5;
	const static int columnsWidth = 15;
	int paintBoxHight = graph->Height - 15;
	int paintBoxHight2 = paintBoxHight - paintBoxTop;

	int echelon = 6;

	graph->Canvas->MoveTo(StartSpacer -2, this->graph->Height - spacer);
	graph->Canvas->LineTo(StartSpacer -2, spacer);

	graph->Canvas->MoveTo(spacer,paintBoxHight + 1);
	graph->Canvas->LineTo(this->graph->Width - spacer, paintBoxHight +1);

	for (int i = 0; i < totalWords.size(); i++) {

		if (biggestValue < totalWords[i]) {
			biggestValue = totalWords[i];
		}
	}

	if (biggestValue == 0)return;

	for (int i = 0; i < totalWords.size(); i++) {

		if(i >= 99) return;

		float tempFailedWords =  (1 /(float)biggestValue) * (float)failedWords[i];
		float tempPrecessedWords =  (1 /(float)biggestValue) * (float)precessedWords[i];
		float tempTotalWords =  (1 /(float)biggestValue) * (float)(totalWords[i]-(precessedWords[i]+failedWords[i]));

		//draw Failed
		drawRectangle((columnsWidth * i ) + (spacer * i)+StartSpacer,paintBoxHight,(columnsWidth * (i+1) ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * tempFailedWords),clRed);
		//draw Precessed
		drawRectangle((columnsWidth * i ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * tempFailedWords),(columnsWidth * (i+1) ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * (tempFailedWords+tempPrecessedWords)),clLime);
		//draw totalWords
		drawRectangle((columnsWidth * i ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * (tempFailedWords+tempPrecessedWords)),(columnsWidth * (i+1) ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * (tempFailedWords+tempPrecessedWords+tempTotalWords)),clSkyBlue);

		this->graph->Canvas->TextOut((columnsWidth * i ) + (spacer * i)+StartSpacer+2 , paintBoxHight + 3,(UnicodeString)i);
	}



	for (int i = 0; i < (echelon+1); i++) {

		this->graph->Canvas->TextOut(1 , (paintBoxHight -13) * ((float)i/echelon) ,(UnicodeString)round(biggestValue * ((float)((i-echelon)*(-1))/echelon)));
	}
}

void PaintBox::drawRectangle(int X1,int Y1,int X2,int Y2, TColor color){

	this->graph->Canvas->Brush->Color = color;
	this->graph->Canvas->Rectangle(X1,Y1,X2,Y2);
}




