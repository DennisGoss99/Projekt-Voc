//---------------------------------------------------------------------------

#pragma hdrstop

#include "cPaintbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PaintBox::PaintBox(TPaintBox *graph){
	this->graph = graph;								//Sets the local variable grahp
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

	int echelon = 6;									//number of vocabulary left column								

	//draws x axis
	graph->Canvas->MoveTo(StartSpacer -2, this->graph->Height - spacer);
	graph->Canvas->LineTo(StartSpacer -2, spacer);	

	//draws y axis
	graph->Canvas->MoveTo(spacer,paintBoxHight + 1);	
	graph->Canvas->LineTo(this->graph->Width - spacer, paintBoxHight +1);

	for (int i = 0; i < totalWords.size(); i++) {		//determines the largest value	

		if (biggestValue < totalWords[i]) {
			biggestValue = totalWords[i];
		}
	}

	if (biggestValue == 0)return;

	for (int i = 0; i < totalWords.size(); i++) {		//plots column diagram per statistic		

		if(i >= 99) continue;							//If the number of statistics is greater than 99, the last statistics are skipped.

		float tempFailedWords =  (1 /(float)biggestValue) * (float)failedWords[i];
		float tempPrecessedWords =  (1 /(float)biggestValue) * (float)precessedWords[i];
		float tempTotalWords =  (1 /(float)biggestValue) * (float)(totalWords[i]-(precessedWords[i]+failedWords[i]));

		//draw Rectangle: Failed
		drawRectangle((columnsWidth * i ) + (spacer * i)+StartSpacer,paintBoxHight,(columnsWidth * (i+1) ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * tempFailedWords),clRed);
		//draw Rectangle: Precessed
		drawRectangle((columnsWidth * i ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * tempFailedWords),(columnsWidth * (i+1) ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * (tempFailedWords+tempPrecessedWords)),clLime);
		//draw Rectangle: totalWords
		drawRectangle((columnsWidth * i ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * (tempFailedWords+tempPrecessedWords)),(columnsWidth * (i+1) ) + (spacer * i)+StartSpacer,paintBoxHight - round (paintBoxHight2 * (tempFailedWords+tempPrecessedWords+tempTotalWords)),clSkyBlue);

		
		this->graph->Canvas->TextOut((columnsWidth * i ) + (spacer * i)+StartSpacer+2 , paintBoxHight + 3,(UnicodeString)i);
	}



	for (int i = 0; i < (echelon+1); i++) {
		//draws the numbers on the y axis
		this->graph->Canvas->TextOut(1 , (paintBoxHight -13) * ((float)i/echelon) ,(UnicodeString)round(biggestValue * ((float)((i-echelon)*(-1))/echelon)));
	}
}

void PaintBox::drawRectangle(int X1,int Y1,int X2,int Y2, TColor color){

	this->graph->Canvas->Brush->Color = color;
	this->graph->Canvas->Rectangle(X1,Y1,X2,Y2);
}




