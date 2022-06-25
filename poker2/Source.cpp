#include<iostream>
#include<sstream>
using namespace std;
int start = 0, runda = 0, kCartiFolosite = 0, manaJucator1 = 0, manaJucator2 = 0;
string carti[53], cartiMasa[5], cartiJucator1[3], cartiJucator2[3], cartiFolosite[10];

//CreareDeck
void creareDeck(string carti[]) {
	for (int i = 0; i < 52; i++) {
		if (i <= 12) {
			if (i <= 8) {
				carti[i] = to_string(i + 2) + (string)"?";
			}
			else {
				if (i == 9) {
					carti[i] = "J?";
				}
				else if (i == 10) {
					carti[i] = "Q?";
				}
				else if (i == 11) {
					carti[i] = "K?";
				}
				else {
					carti[i] = "A?";
				}
			}	
		}		
		else if (i > 12 && i <= 25) {
			if (i <= 21) {
				carti[i] = to_string(i - 11) + (string)"$";
			}
			else {
				if (i == 22) {
					carti[i] = "J$";
				}
				else if (i == 23) {
					carti[i] = "Q$";
				}
				else if (i == 24) {
					carti[i] = "K$";
				}
				else {
					carti[i] = "A$";
				}
			}
		}
		else if (i > 25 && i <= 38) {
			if (i <= 34) {
				carti[i] = to_string(i - 24) + (string)"&";
			}
			else {
				if (i == 35) {
					carti[i] = "J&";
				}
				else if (i == 36) {
					carti[i] = "Q&";
				}
				else if (i == 37) {
					carti[i] = "K&";
				}
				else {
					carti[i] = "A&";
				}
			}
		}
		else{
			if (i<=47) {
				carti[i] = to_string(i - 37) + (string)"#";
			}
			else {
				if (i == 48) {
					carti[i] = "J#";
				}
				else if (i == 49) {
					carti[i] = "Q#";
				}
				else if (i == 50) {
					carti[i] = "K#";
				}
				else {
					carti[i] = "A#";
				}
			}
		}
	}
	for (int i = 0; i < 52; i++) {
		cout << carti[i]<<" ";
	}
}
//CreareDeck


//alegereCartiJucatori
void alegereCartiJucatori(string jucator[]) {
	int nrIndex = 0;
	int aparitii2 = 0;
	for (int i = 0; i < 2; i++) {
		fflush(stdout);
		nrIndex = 0;
		nrIndex = rand()% 52;
		for(int j = 0; j<9; j++){
			if (cartiFolosite[j] == carti[nrIndex]) {
				aparitii2++;
			}
		}
		if (aparitii2 == 0) {
			jucator[i] = carti[nrIndex];
			cartiFolosite[kCartiFolosite] = carti[nrIndex];
			kCartiFolosite++;

		}
		else {
			alegereCartiJucatori(jucator);
		}
	}
	
}
//alegereCartiJucatori


//AlegereCarti
void alegereCarti(string cartiMasa[]) {
	int nrIndex = 0;
	int aparitii = 0;
	cartiMasa[5] = { NULL };
	fflush(stdin);
	cout << endl;
	for (int i = 0; i < 5; i++) {
		fflush(stdout);
		cout << cartiMasa[i];
	}
	if (runda == 0) {
		for (int i = 0; i < 3; i++) {
			fflush(stdout);
			nrIndex = 0;
			nrIndex = rand() % 51;
			for (int j = 0; j < 9; j++) {
				if (carti[nrIndex] == cartiFolosite[j]) {
					aparitii++;
				}
			}
			if (aparitii == 0) {
				cartiMasa[i] = carti[nrIndex];
				cartiFolosite[kCartiFolosite] = carti[nrIndex];
				kCartiFolosite++;
				
			}
			else {
			alegereCarti(cartiMasa);
			}
		}
		runda++;
		cout << runda;
	}
	else if (runda != 0) {
		fflush(stdout);
		nrIndex = 0;
	nrIndex = rand() % 51;
	for (int j = 0; j < 9; j++) {
		if (carti[nrIndex] == cartiFolosite[j]) {
			aparitii++;
		}
	}
	if (aparitii == 0) {
		cartiMasa[runda + 2] = carti[nrIndex];
		cartiFolosite[kCartiFolosite] = carti[nrIndex];
		kCartiFolosite++;
		if (runda <= 2) {
			runda++;
		}
		cout << runda;
	}
	else {
		alegereCarti(cartiMasa);
	}
	
	}
}
//AlegereCarti












//Verificare
void verificare(string cartiJucator1[], string cartiJucator2[], string cartiMasa[], int manaJucator1, int manaJucator2) {
	int simbolJucator1 = 0;
	int simbolJucator2 = 0;
	int nrPerechi1 = 0;
	int nrPerechi2 = 0;
	char charVerificat1 = NULL;
	int perechiJucator1 = 0;
	int perechiJucator2 = 0;
	int manaAnterioara1 = 0;
	int manaAnterioara2 = 0;
	char charVerificat2 = NULL;

	for (int i = 0; i < 2; i++) {
		perechiJucator1 = 0;
		perechiJucator2 = 0;
		charVerificat1 = (cartiJucator1[i])[0];
		charVerificat2 = (cartiJucator2[i])[0];

		//pereche/three of a kind
		if (i == 0) {
			if (charVerificat1 == (cartiJucator1[i + 1])[0]) {
				perechiJucator1++;
			}
			if (charVerificat2 == (cartiJucator2[i + 1])[0]) {
				perechiJucator2++;
			}
		}
		for (int j = 0; j < 5; j++) {
			if ((cartiMasa[j])[0] == charVerificat1) {
				perechiJucator1++;
			}
			if ((cartiMasa[j])[0] == charVerificat2) {
				perechiJucator2++;
			}
		}
		if (perechiJucator1 == 1 && manaJucator1 < 2) {
			manaJucator1 = 2;
		}
		if (perechiJucator1 == 2) {
			manaJucator1 = 4;
		}
		if (perechiJucator2 == 1 && manaJucator2 < 2) {
			manaJucator2 = 2;
		}
		if (perechiJucator2 == 2) {
			manaJucator2 = 4;
		}
		//pereche/three of a kind


		//Salvare maini pentru  verificare full house
		if (i == 0) {
			manaAnterioara1 = manaJucator1;
			manaAnterioara2 = manaJucator1;
		}
		//Salvare maini pentru verificare full house


		//Two Pair
		if (manaJucator1 < 3) {
			for (int j = 0; j < 5; j++) {
				if ((cartiMasa[j])[0] == (cartiJucator1[i])[0]) {
					nrPerechi1++;
					break;
				}
			}
		}
		if (manaJucator2 < 3) {
			for (int j = 0; j < 5; j++) {
				if ((cartiMasa[j])[0] == (cartiJucator2[i])[0]) {
					nrPerechi2++;
					break;
				}
			}
		}
		//Two Pair




	}
	//Full house
	if (manaJucator1 == 4 && manaAnterioara1 == 2) {
		manaJucator1 = 6;
	}
	if (manaJucator2 == 4 && manaAnterioara2 == 2) {
		manaJucator2 = 6;
	}
	//Full house

	//TwoPair - continuare
	if (manaJucator1 < 3 && nrPerechi1 == 2) {
		manaJucator1 = 3;
	}
	if (manaJucator2 < 3 && nrPerechi2 == 2) {
		manaJucator2 = 3;
	}
	//TwoPair - continuare



	//STRAIGHT-jucator1
	int nrConsec1 = 0;
	int nrConsec2 = 0;
	for (int j = 0; j < 5; j++) {
		if ((int)(cartiMasa[j])[0] == (int)(cartiJucator1[0])[0] + 1 || (int)(cartiMasa[j])[0] == (int)(cartiJucator1[1])[0] + 1 || (int)(cartiMasa[j])[0] == (int)(cartiJucator1[0])[0] - 1 || (int)(cartiMasa[j])[0] == (int)(cartiJucator1[1])[0] - 1) {
			nrConsec1++;
		}
		else if (((int)(cartiJucator1[0])[0] == 49 && (int)(cartiMasa[j])[0] == 57) || ((int)(cartiJucator1[1])[0] == 49 && (int)(cartiMasa[j])[0] == 57) || ((int)(cartiJucator1[0])[0] == 57 && (int)(cartiMasa[j])[0] == 49) || ((int)(cartiJucator1[1])[0] == 57 && (int)(cartiMasa[j])[0] == 49) || ((int)(cartiJucator1[0])[0] == 49 && (int)(cartiMasa[j])[0] == 74) || ((int)(cartiJucator1[1])[0] == 49 && (int)(cartiMasa[j])[0] == 74) || ((int)(cartiJucator1[0])[0] == 74 && (int)(cartiMasa[j])[0] == 49) || ((int)(cartiJucator1[1])[0] == 74 && (int)(cartiMasa[j])[0] == 49)) {
			nrConsec1++;
		}
		else if (((int)(cartiJucator1[0])[0] == 74 && (int)(cartiMasa[j])[0] == 81) || ((int)(cartiJucator1[1])[0] == 74 && (int)(cartiMasa[j])[0] == 81) || ((int)(cartiJucator1[0])[0] == 81 && (int)(cartiMasa[j])[0] == 74) || ((int)(cartiJucator1[1])[0] == 81 && (int)(cartiMasa[j])[0] == 74)) {
			nrConsec1++;
		}
		else if (((int)(cartiJucator1[0])[0] == 81 && (int)(cartiMasa[j])[0] == 75) || ((int)(cartiJucator1[1])[0] == 81 && (int)(cartiMasa[j])[0] == 75) || ((int)(cartiJucator1[0])[0] == 75 && (int)(cartiMasa[j])[0] == 81) || ((int)(cartiJucator1[1])[0] == 75 && (int)(cartiMasa[j])[0] == 81)) {
			nrConsec1++;
		}
		else if (((int)(cartiJucator1[0])[0] == 75 && (int)(cartiMasa[j])[0] == 65) || ((int)(cartiJucator1[1])[0] == 75 && (int)(cartiMasa[j])[0] == 65) || ((int)(cartiJucator1[0])[0] == 65 && (int)(cartiMasa[j])[0] == 75) || ((int)(cartiJucator1[1])[0] == 65 && (int)(cartiMasa[j])[0] == 75)) {
			nrConsec1++;
		}
		else {
			for (int i = 0; i < 5; i++) {
				if ((int)(cartiMasa[j])[0] == (int)(cartiMasa[i])[0] - 1 || (int)(cartiMasa[j])[0] == (int)(cartiMasa[i])[0] + 1) {
					nrConsec1++;
				}
				if (((int)(cartiMasa[j])[0] == 57 && (int)(cartiMasa[i])[0] == 49) || ((int)(cartiMasa[j])[0] == 49 && (int)(cartiMasa[i])[0] == 57)) {
					nrConsec1++;
				}
				if (((int)(cartiMasa[j])[0] == 49 && (int)(cartiMasa[i])[0] == 74) || ((int)(cartiMasa[j])[0] == 74 && (int)(cartiMasa[i])[0] == 49)) {
					nrConsec1++;
				}
				if (((int)(cartiMasa[j])[0] == 74 && (int)(cartiMasa[i])[0] == 81) || ((int)(cartiMasa[j])[0] == 81 && (int)(cartiMasa[i])[0] == 74)) {
					nrConsec1++;
				}
				if (((int)(cartiMasa[j])[0] == 81 && (int)(cartiMasa[i])[0] == 75) || ((int)(cartiMasa[j])[0] == 75 && (int)(cartiMasa[i])[0] == 81)) {
					nrConsec1++;
				}
				if (((int)(cartiMasa[j])[0] == 75 && (int)(cartiMasa[i])[0] == 65) || ((int)(cartiMasa[j])[0] == 65 && (int)(cartiMasa[i])[0] == 75)) {
					nrConsec1++;
				}
			}
		}
	}
	if (nrConsec1 >= 5) {
		manaJucator1 = 5;
	}
	//STRAIGHT-jucator1
	
	//STRAIGHT-jucator2
	for (int j = 0; j < 5; j++) {
		if ((int)(cartiMasa[j])[0] == (int)(cartiJucator2[0])[0] + 1 || (int)(cartiMasa[j])[0] == (int)(cartiJucator2[1])[0] + 1 || (int)(cartiMasa[j])[0] == (int)(cartiJucator2[0])[0] - 1 || (int)(cartiMasa[j])[0] == (int)(cartiJucator2[1])[0] - 1) {
			nrConsec2++;
		}
		else if (((int)(cartiJucator2[0])[0] == 49 && (int)(cartiMasa[j])[0] == 57) || ((int)(cartiJucator2[1])[0] == 49 && (int)(cartiMasa[j])[0] == 57) || ((int)(cartiJucator2[0])[0] == 57 && (int)(cartiMasa[j])[0] == 49) || ((int)(cartiJucator2[1])[0] == 57 && (int)(cartiMasa[j])[0] == 49) || ((int)(cartiJucator1[0])[0] == 49 && (int)(cartiMasa[j])[0] == 74) || ((int)(cartiJucator1[1])[0] == 49 && (int)(cartiMasa[j])[0] == 74) || ((int)(cartiJucator1[0])[0] == 74 && (int)(cartiMasa[j])[0] == 49) || ((int)(cartiJucator1[1])[0] == 74 && (int)(cartiMasa[j])[0] == 49)) {
			nrConsec2++;
		}
		else if (((int)(cartiJucator2[0])[0] == 74 && (int)(cartiMasa[j])[0] == 81) || ((int)(cartiJucator2[1])[0] == 74 && (int)(cartiMasa[j])[0] == 81) || ((int)(cartiJucator2[0])[0] == 81 && (int)(cartiMasa[j])[0] == 74) || ((int)(cartiJucator2[1])[0] == 81 && (int)(cartiMasa[j])[0] == 74)) {
			nrConsec2++;
		}
		else if (((int)(cartiJucator2[0])[0] == 81 && (int)(cartiMasa[j])[0] == 75) || ((int)(cartiJucator2[1])[0] == 81 && (int)(cartiMasa[j])[0] == 75) || ((int)(cartiJucator2[0])[0] == 75 && (int)(cartiMasa[j])[0] == 81) || ((int)(cartiJucator2[1])[0] == 75 && (int)(cartiMasa[j])[0] == 81)) {
			nrConsec2++;
		}
		else if (((int)(cartiJucator2[0])[0] == 75 && (int)(cartiMasa[j])[0] == 65) || ((int)(cartiJucator2[1])[0] == 75 && (int)(cartiMasa[j])[0] == 65) || ((int)(cartiJucator2[0])[0] == 65 && (int)(cartiMasa[j])[0] == 75) || ((int)(cartiJucator2[1])[0] == 65 && (int)(cartiMasa[j])[0] == 75)) {
			nrConsec2++;
		}
		else {
			for (int i = 0; i < 5; i++) {
				if ((int)(cartiMasa[j])[0] == (int)(cartiMasa[i])[0] - 1 || (int)(cartiMasa[j])[0] == (int)(cartiMasa[i])[0] + 1) {
					nrConsec2++;
				}
				if (((int)(cartiMasa[j])[0] == 57 && (int)(cartiMasa[i])[0] == 49) || ((int)(cartiMasa[j])[0] == 49 && (int)(cartiMasa[i])[0] == 57)) {
					nrConsec2++;
				}
				if (((int)(cartiMasa[j])[0] == 49 && (int)(cartiMasa[i])[0] == 74) || ((int)(cartiMasa[j])[0] == 74 && (int)(cartiMasa[i])[0] == 49)) {
					nrConsec2++;
				}
				if (((int)(cartiMasa[j])[0] == 74 && (int)(cartiMasa[i])[0] == 81) || ((int)(cartiMasa[j])[0] == 81 && (int)(cartiMasa[i])[0] == 74)) {
					nrConsec2++;
				}
				if (((int)(cartiMasa[j])[0] == 81 && (int)(cartiMasa[i])[0] == 75) || ((int)(cartiMasa[j])[0] == 75 && (int)(cartiMasa[i])[0] == 81)) {
					nrConsec2++;
				}
				if (((int)(cartiMasa[j])[0] == 75 && (int)(cartiMasa[i])[0] == 65) || ((int)(cartiMasa[j])[0] == 65 && (int)(cartiMasa[i])[0] == 75)) {
					nrConsec2++;
				}
			}
		}
	}
	if (nrConsec2 >= 5) {
		manaJucator2 = 5;
	}
	//STRAIGHT-jucator2
	
	//Flush
	if ((cartiJucator1[0])[1] == (cartiJucator1[1])[1]) {
		simbolJucator1++;
	}
	if ((cartiJucator2[0])[1] == (cartiJucator2[1])[1]) {
		simbolJucator2++;
	}
	for (int i = 0; i < 2; i++) {
		charVerificat1 = (cartiJucator1[i])[1];
		charVerificat2 = (cartiJucator2[i])[1];
		for (int j = 0; j < 5; j++) {
			if ((cartiMasa[j])[1] == charVerificat1) {
				simbolJucator1++;
			}
			if ((cartiMasa[j])[1] == charVerificat2) {
				simbolJucator2++;
			}
		}

	}
	if (simbolJucator1 >= 5 && manaJucator1 == 5) {
		manaJucator1 = 8;
	}
	else if (simbolJucator1 >= 5) {
		manaJucator1 = 7;
	}
	if (simbolJucator2 >= 5 && manaJucator2 == 5) {
		manaJucator2 = 8;
	}
	else if (simbolJucator2 >= 5) {
		manaJucator2 = 7;
	}
	cout << "a";
	//Flush

	//HighCard
	int jucatorMax = 1;
	char carteMax = (cartiJucator1[0])[0];
	if (manaJucator1 == manaJucator2) {
		for (int i = 0; i < 2; i++) {
			if ((cartiJucator1[i])[0] != carteMax) {
				if (((int)carteMax >= 50 && (int)carteMax <= 57) && ((int)(cartiJucator1[i])[0] >= 50 && (int)(cartiJucator1[i])[0] <= 57)) {
					if ((int)carteMax < (int)(cartiJucator1[i])[0]) {
						jucatorMax = 1;
						carteMax = (int)(cartiJucator1[i])[0];
					}
				}
				if (((int)carteMax >= 50 && (int)carteMax <= 57) && ((int)(cartiJucator1[i])[0] > 57 || (int)(cartiJucator1[i])[0] < 50)) {
					jucatorMax = 1;
					carteMax = (int)(cartiJucator1[i])[0];
				}
				if ((int)carteMax != 65 && (int)(cartiJucator1[i])[0] == 65) {
					jucatorMax = 1;
					carteMax = (cartiJucator1[i])[0];
				}
				if ((int)carteMax == 74 && (int)(cartiJucator1[i])[0] > (int)carteMax) {
					carteMax = (cartiJucator1[i])[0];
					jucatorMax = 1;
				}
				if ((int)carteMax == 81 && (int)(cartiJucator1[i])[0] == 75) {
					carteMax = (cartiJucator1[i])[0];
				}
				break;
			}


			for (int j = 0; j < 2; j++) {
				if (((int)carteMax >= 50 && (int)carteMax <= 57) && ((int)(cartiJucator2[j])[0] >= 50 && (int)(cartiJucator2[j])[0] <= 57)) {
					if ((int)carteMax < (int)(cartiJucator2[j])[0]) {
						jucatorMax = 2;
						carteMax = (int)(cartiJucator2[j])[0];
					}
				}
				if (((int)carteMax >= 50 && (int)carteMax <= 57) && ((int)(cartiJucator2[j])[0] > 57 || (int)(cartiJucator2[j])[0] < 50)) {
					jucatorMax = 2;
					carteMax = (int)(cartiJucator2[j])[0];
				}
				if ((int)carteMax != 65 && (int)(cartiJucator2[j])[0] == 65) {
					jucatorMax = 2;
					carteMax = (cartiJucator2[j])[0];
				}
				if ((int)carteMax == 74 && (int)(cartiJucator2[j])[0] > (int)carteMax) {
					carteMax = (cartiJucator2[j])[0];
					jucatorMax = 2;
				}
				if ((int)carteMax == 81 && (int)(cartiJucator2[j])[0] == 75) {
					carteMax = (cartiJucator2[j])[0];
					jucatorMax = 2;
				}
				if ((int)carteMax == (int)(cartiJucator2[j])[0]) {
					jucatorMax = 0;
				}
			}

		}
	}
	//HighCard
	cout << "a";
	if (jucatorMax == 2) {
		cout << endl << "Jucatorul 2 castiga!";
	}
	if (jucatorMax == 1) {
		cout << endl << "Jucatorul 1 castiga!";
	}
	if (jucatorMax == 0) {
		cout << endl << "Egalitate!";
	}

}
//Verificare








//Afisare/Play
void afisare(string cartiMasa[], string cartiJucator1[], string cartiJucator2[]) {
	int response1 = 0;
	int response2 = 0;
	while (start != 0) {
		cout << "Table Cards: ";
		for (int i = 0; i < 3; i++) {
			cout << cartiMasa[i] << " ";
		}
		cout << endl << "Player 1: ";
		for (int i = 0; i < 2; i++) {
			cout << cartiJucator1[i] << " ";
		}
		cout << endl << "Player 2: ";
		for (int i = 0; i < 2; i++) {
			cout << cartiJucator2[i] << " ";
		}
		cout << endl << "Player 1, continue? 1 or 0 -> ";
		cin >> response1;
		cout << endl << "Player2, continue? 1 or 0 -> ";
		cin >> response2;



		if (response1 == 1 && response2 == 1) {
			//runda++;
			system("CLS");
			alegereCarti(cartiMasa);
			
			cout << "Table Cards: ";
			for (int i = 0; i < 4; i++) {
				cout << cartiMasa[i] << " ";
			}
			cout << endl << "Player 1: ";
			for (int i = 0; i < 2; i++) {
				cout << cartiJucator1[i] << " ";
			}
			cout << endl << "Player 2: ";
			for (int i = 0; i < 2; i++) {
				cout << cartiJucator2[i] << " ";
			}
			cout << endl << "Player 1, continue? 1 or 0 -> ";
			cin >> response1;
			cout << endl << "Player2, continue? 1 or 0 -> ";
			cin >> response2;
			if (response1 == 1 && response2 == 1) {
				system("CLS");
				alegereCarti(cartiMasa);
				cout << "Table Cards: ";
				for (int i = 0; i < 4; i++) {
					cout << cartiMasa[i] << " ";
				}
				cout << endl << "Player 1: ";
				for (int i = 0; i < 2; i++) {
					cout << cartiJucator1[i] << " ";
				}
				cout << endl << "Player 2: ";
				for (int i = 0; i < 2; i++) {
					cout << cartiJucator2[i] << " ";
				}
				verificare(cartiJucator1, cartiJucator2, cartiMasa, manaJucator1, manaJucator2);
			}
		}
	}
}
//Afisare/Play



int main() {

	cout << "Enter any number but 0 if you want to start the game";
	cin >> start;
	creareDeck(carti);
	for (int i = 0; i < 9; i++) {
		cartiFolosite[i] = "0";
	}
	fflush(stdin);
	//cout <<endl<<"runda initiala:"<< runda;
	alegereCarti(cartiMasa);
	//cout <<endl<<"runda finala:"<< runda;
	alegereCartiJucatori(cartiJucator1);
	alegereCartiJucatori(cartiJucator2);
	afisare(cartiMasa, cartiJucator1, cartiJucator2);
	
	return 0;
}