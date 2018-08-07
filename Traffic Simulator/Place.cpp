/*
Purpose: This clss be used to produce the map of the traffic simulation
which will provide all the graphic output such as lights, grass,
road intersection etc.
*/
#include "Place.h"
#include <iostream>
#include "Functions.h"

using namespace std;

Place::Place(){
}

Place::~Place(){
}

/***
This function outputs the traffic light icon on to the map a
***/
void Place::setLights(){

	//left traffic light
	gotoxy(27, 17);
	coutchar(0, 127);
	gotoxy(26, 17);
	coutchar(0, 127);
	gotoxy(25, 17);
	coutchar(0, 127);
	
	//north traffic light
	gotoxy(42, 7);
	coutchar(0, 127);
	gotoxy(42, 6);
	coutchar(0, 127);
	gotoxy(42, 5);
	coutchar(0, 127);

	//east traffic light
	gotoxy(57, 17);
	coutchar(0, 127);
	gotoxy(58, 17);
	coutchar(0, 127);
	gotoxy(59, 17);
	coutchar(0, 127);
	
	//southbound traffic light
	gotoxy(42, 26);
	coutchar(0, 127);
	gotoxy(42, 27);
	coutchar(0, 127);
	gotoxy(42, 28);
	coutchar(0, 127);



}


/***
Outputs the grass areas on the to traffic map simulator
and as well as printing the roads, lane indetifiers and intersection
***/
void Place::setGrass(){

	//prints the grey road
	for (int i = 0; i < 85; i++){
		for (int j = 0; j < 34; j++){
			gotoxy(i, j);
			coutchar(8, 219);
		}

	}
	
	//intialize the grass area
	gotoxy(0,0);
	for (int i = 0; i < 9; i++){
		
		for (int j = 0; j < 29; j++){
			coutchar(2, 219);
		}
		cout << endl;
	}
	gotoxy(0, 25);

	for (int i = 0; i < 9; i++){
		
		for (int j = 0; j < 29; j++){
			coutchar(2, 219);
		}
		cout << endl;
	}

	gotoxy(56, 0);
	for (int i = 0; i < 9; i++){

		for (int j = 0; j < 29; j++){
			coutchar(2, 219);
		}
		gotoxy(56, i+1);
	}

	gotoxy(56, 25);
	for (int i = 0; i < 9; i++){

		for (int j = 0; j < 29; j++){
			coutchar(2, 219);
		}
		gotoxy(56, 25 + i + 1);
	}

	//prints lane indentifiers

	gotoxy(0, 17);
	for (int i = 0; i < 29; i++){

		coutchar(5, 205);
	}

	gotoxy(56, 17);
	for (int i = 0; i < 29; i++){

		coutchar(5, 205);
	}

	
	for (int i = 0; i < 9; i++){
		gotoxy(42, i);
		coutchar(5, 186);

	}

	
	for (int i = 0; i < 9; i++){
		gotoxy(42, 25 + i);
		coutchar(5, 186);
	}

	//prints boundries onto map
	gotoxy(0, 9);
	for (int i = 0; i < 30; i++){
		gotoxy(i, 9);
		coutchar(8, 176);

	}
	gotoxy(29, 0);
	for (int i = 0; i < 9; i++){
		gotoxy(29, i);
		coutchar(8, 176);

	}
	
	gotoxy(0, 24);
	for (int i = 0; i < 30; i++){
		gotoxy(i, 24);
		coutchar(8, 176);

	}

	gotoxy(29,25);
	for (int i = 0; i < 9; i++){
		gotoxy(29, 25 + i);
		coutchar(8, 176);

	}

	gotoxy(55, 9);
	for (int i = 0; i < 30; i++){
		gotoxy(55 + i, 9);
		coutchar(8, 176);

	}
	
	gotoxy(55,0);
	for (int i = 0; i < 9; i++){
		gotoxy(55, i);
		coutchar(8, 176);

	}
	gotoxy(55, 24);
	for (int i = 0; i < 30; i++){
		gotoxy(55 + i, 24);
		coutchar(8, 176);

	}

	gotoxy(55, 24);
	for (int i = 0; i < 9; i++){
		gotoxy(55, 25 + i);
		coutchar(8, 176);

	}

	//intersection line on west side
	gotoxy(29, 23);
	for (int i = 0; i < 6; i++){
		gotoxy(29, 23 - i);
		coutchar(0, 179);

	}

	//intersection line on east side
	gotoxy(55, 16);
	for (int i = 0; i < 7; i++){
		gotoxy(55, 16 - i);
		coutchar(0, 179);

	}

	//intersection line on north side
	gotoxy(30, 9);
	for (int i = 0; i < 12; i++){
		gotoxy(30 + i, 9);
		coutchar(0, 179);

	}

	//intersection line on south side
	gotoxy(42, 24);
	for (int i = 0; i < 12; i++){
		gotoxy(43 + i, 24);
		coutchar(0, 179);

	}



}