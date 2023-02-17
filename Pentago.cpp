// Pentago.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <clocale>
using namespace std;

void opis();
void start();
void nazwij_graczy (string& gracz1, string& gracz2);
void rysuj_plansze();
void LG();
void opis()
{
	char back;
	system("cls");
	cout << "|Pentago jest grĄ dwuosobowĄ na planszy. Plansza skada si© z 4 ruchomych cz©ci, kt˘re moľna\n";
	cout << "|obraca†. Kaľda cz©† zawiera 9 miejsc na ľetony\n";
	cout << "|Gracze po kolei oddajĄ ruch skadajĄcy si© z 2 cz©ci:\n";
	cout << "|obr˘t jednej z cz©ci planszy o 90 stopni w dowolnym kierunku. ; \n";
	cout << "|dooľenia swojego ľetonu na niezaj©te pole planszy; \n";
	cout << "|obr˘t jednej z cz©ci planszy o 90 stopni w dowolnym kierunku\n";
	cout << "|Nie moľna zrezygnowa† z ľadnej cz©ci ruchu.\n";
	cout << "|Wygrywa osoba, kt˘rej 5 ľeton˘w, po penym ruchu, sĄ uoľone w rz©dzie/kolumnie/po skosach\n";
	cout << "|(podobnie do gry k˘ko krzyľyk).\n";
	cout << endl << "aby wr˘ci† do menu nacinij (p) lub (m) lub (h)";
	cin >> back;
	
	switch (back)
	{
		case'p':
		case 'm':
		case 'h':
			start();

	}
}



void nazwij_graczy(string& gracz1, string& gracz2)
{
	system("cls");
	cout << "Wpisz imi© gracza 1. ";
	cin >> gracz1;
	cout << "Wpisz imi© gracza 2. ";
	cin >> gracz2;
}

void LG() //budka lewy gorny rog
{
	const char a = 200; // L
	const char b = 201; // -
	const char c = 202; // ¦
	const char d = 203; // T
	const char e = 204; // ¦
	const char f = 205; // =
	const char g = 206; // +
	const char h = 186; // ¦
	const char x = 187; //  ¬
	const char y = 188;

	// 3x3 kratka




	for (int j = 0; j < 3; j++)
	{
		int TAB_1x1[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
		for (int i = 0; i < 3; i++)
		{
			cout << b << f << f << f << x;
			if (i == 2) cout << h;
		}

		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << h << ' ' << TAB_1x1[j][i] << ' ' << h;
			if (i == 2) cout << h;
		}

		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << a << f << f << f << y;
			if (i == 2) cout << h;
		}
		cout << endl;
	}
	for (int i = 0; i < 15; i++) cout << f;
	cout << g << endl;
}

void rysuj_plansze()
{
	
	LG();
	
}




void start()
{
	char a =201; // ╔
	char b = 205;//═
	string gracz1, gracz2;
	system("cls");
	char opcjaMenu;
	cout << "Gra projektowa PENTAGO\n";
	for (int i = 0; i < 35; i++) cout << b; 
	cout << "\n\n";
	cout << "MENU:\n\n";
	cout << "(g)- zacznij gr©\n";
	cout << "(o)- wczytaj predefiniowanĄ plansz©\n";
	cout << "(m)- opcje\n";
	cout << "(h)- opis i zasady gry\n";
	for(int i=0; i<35; i++) cout << b; 
	cout << "\n";
	cin >> opcjaMenu;

	switch (opcjaMenu)
	{

		case'g': cout << "zaczyna gr©" << endl;
			nazwij_graczy(gracz1, gracz2);
			rysuj_plansze();
			break;
			

		case'o': cout << "wczytuje predefiniowanĄ plansz©";
			break;

		case'm': cout << "wczytuje opcje";
			break;

		case'h': cout << "opis i zasady gry\n";
			opis();
			break;
		default: system("cls");
			start();

	}
}





int main()
{
	
	//menu
	start();

}

