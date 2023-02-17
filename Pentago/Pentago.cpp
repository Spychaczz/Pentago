#include <iostream>
using namespace std;

void opis(char b);
void start();
void nazwij_graczy (string& gracz1, string& gracz2);
void LG();
void PLANSZA(char TAB_LG[3][3], char TAB_PG[3][3], char TAB_LD[3][3], char TAB_PD[3][3], string gracz1, string gracz2, char zeton1, char zeton2);
void ZROB_PREDEFINIOWANA(char TAB_LG[][3], char TAB_PG[][3], char TAB_LD[][3], char TAB_PD[][3], char zeton1, char zeton2);
void wybierzZeton(string gracz1, string gracz2, char& zeton1, char& zeton2);
bool wyborGry();
void kolko_Krzyzyk(string gracz1, string gracz2, char zeton1, char zeton2, char TAB_LG[][3], char TAB_PG[][3], char TAB_LD[][3], char TAB_PD[][3]);
void cwiartkaLG(char zeton1, char zeton2, char TAB_LG[][3], string numerPola, int &runda);
void cwiartkaPG(char zeton1, char zeton2, char TAB_PG[][3], string numerPola, int &runda);
void cwiartkaLD(char zeton1, char zeton2, char TAB_LD[][3], string numerPola, int &runda);
void cwiartkaPD(char zeton1, char zeton2, char TAB_PD[][3], string numerPola, int &runda);
bool SprawdzWygrana(char TAB_LG[3][3], char TAB_PG[3][3], char TAB_LD[3][3], char TAB_PD[3][3],  string gracz1, string gracz2, char zeton1, char zeton2, int runda, bool &wygrana);

void opis(char b)
{
	bool powrot=false;	
	while(!powrot)	
	{
	char back;
	system("cls");
	for (int i = 0; i < 80; i++) cout << b; 
	cout << "|Pentago jest gra dwuosobowa na planszy.\n";
	cout << "|Plansza sklada sie z 4 ruchomych czesci ktore mozna\n";
	cout << "|obracac. Kazda czesc zawiera 9 miejsc na zetony\n";
	cout << "|Gracze po kolei oddaja ruch skladajacy sie z 2 czesci\n";
	cout << "|obrotu jednej z czterech czesci˜planszy o 90 stopni w dowolnym kierunku.\n";
	cout << "|dolozenia swojego zetonu na niezajete pole planszy; \n";
	cout << "|obrotu jednej z czesci planszy o 90 stopni w dowolnym kierunku\n";
	cout << "|Nie mozna zrezygnowac z zadnej czesci ruchu.\n";
	cout << "|Wygrywa osoba, ktorej 5 zetonow,\n";
	cout << "|po pelnym ruchu, sa ulozone w rzadzie/kolumnie/po skosach\n";
	cout << "|(podobnie do gry kolko krzyzyk).\n";
	for (int i = 0; i < 80; i++) cout << b; 
	cout << endl << "aby wrocic do menu nacisnij (p) lub (m) lub (h)";
	
	powrot=true;
	cin >> back;
	switch (back)
	{
		case'p':
		case 'm':
		case 'h':
			
			start();
		default:system("cls"); powrot=false;
	}
	}
}

void nazwij_graczy(string& gracz1, string& gracz2)
{
	bool RozneImiona =false;
	system("cls");
	cout << "Wpisz imie gracza 1. ";
	cin >> gracz1;
	
	while(!RozneImiona)
	{
		cout << "Wpisz imie gracza 2. ";
		cin >> gracz2;
		if(gracz1 != gracz2){
			
		 RozneImiona=true;
		 }
		 else cout << "\nImiona musza byc rozne! \n";
	}

}

void WybierzZeton(string gracz1, string gracz2, char& zeton1, char& zeton2)
{
	system("cls");
	cout << "Jakim zetonem chce grac " << gracz1 << "\n" << "(do wyboru: (1)kolko, (2)krzyzyk, (3)pik, (4)serce):";
	bool nieprawidlowyWybor=true;
	
	while(nieprawidlowyWybor)
	{	
		cin >> zeton1;
		switch(zeton1)
		{
			case '1': zeton1 = 'o';
				 nieprawidlowyWybor=false; break;
				 
			case '2': zeton1 = 'x';
				 nieprawidlowyWybor=false; break;
				 
			case '3': zeton1 = 6;
				 nieprawidlowyWybor= false; break;
				 
			case '4': zeton1 = 3;
				 nieprawidlowyWybor= false;break;
				 
			default: cout << "wybierz prawidlowa liczbe! \n"; break;
		}
	}
	system("cls");
		
	zeton2=zeton1;
	
	while(zeton2 == zeton1){
		cout << "Jakim zetonem chce grac " << gracz2 << "\n"<< "(do wyboru: (1)kolko, (2)krzyzyk, (3)pik, (4)serce):";
		
		nieprawidlowyWybor=true;
		while(nieprawidlowyWybor)
		{	
			cin >> zeton2;
			switch(zeton2)
			{
				case '1': zeton2 = 'o'; 
					nieprawidlowyWybor= false; break;
					
				case '2': zeton2 = 'x'; 
					nieprawidlowyWybor= false;	break;
					
				case '3': zeton2 = 6;
					nieprawidlowyWybor= false;	break;
					
				case '4': zeton2 = 3; 
					nieprawidlowyWybor= false;	break;
			
				default: cout << "Wybierz prawidlowa liczbe! \n"; break;
			}
			system("cls");	
			if(zeton2==zeton1)	cout << "Zetony nie moga byc takie same! \n \n";
		}
	}
}

void PLANSZA(char TAB_LG[3][3], char TAB_PG[3][3], char TAB_LD[3][3], char TAB_PD[3][3], string gracz1, string gracz2, char zeton1, char zeton2)
{
	//PRZESUWANIE PLANSZY
	const int przesuniecie_Dol = 4;
	const int przesuniecie_Prawo = 4;
	///////////////////////////////
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
	
	for(int i=0; i< przesuniecie_Dol; i++) cout << endl; //przesuwanie planszy w dol

	for(int j=0 ; j < 3 ; j++)
	{
		for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
		for(int i=0; i< 6; i++)
		{
				cout << b << f <<  f << f << x << ' ';
			if(i==2) cout<< h << ' ';
		}
		cout << endl;
		for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
		
		for(int i=0; i< 6; i++)
		{	
			
			if(i<3) {
			 	 cout << h << ' ' << TAB_LG[j][i]     << ' '<< h << ' ';
			 }
			if(i>=3){
				cout << h << ' ' << TAB_PG[j][i-3] << ' ' << h << ' ';
			} 
			if(i== 2) {
				cout << h << ' ';
			}
		}
		
		cout << endl;
		for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
		
		for(int i=0; i< 6; i++)
		{
			
			cout << a  <<  f << f  << f << y << ' ';
			if(i== 2) {
				cout << h << ' ';
			}
		}
		cout << endl;
	}  //Wypisanie dwoch gornych kwadratow 3x3
	 
	for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
	for(int i=0; i<37; i++) // wypisanie linii oddzielajacej gore i dol
		{
			if(i!=18) cout << f;
			if(i==18)cout << g  ;
		}
		
		cout << endl;

	for(int j=0 ; j < 3 ; j++)
	{
		for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
		for(int i=0; i< 6; i++)
		{
			cout << b << f <<  f << f << x << ' ';
			if(i== 2) cout << h << ' ';
		}
		
		cout << endl;
		for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
		
		for(int i=0; i< 6; i++)
		{	
			if(i<3)  cout << h << ' ' << TAB_LD[j][i]     << ' '<< h << ' ';// lewy kwadrat 3x3
			if(i>=3) cout << h << ' ' << TAB_PD[j][i-3] << ' ' << h << ' ';// prawy kwadrat 3x3
			if(i== 2) cout << h << ' ';
		}
		
		cout << endl;
		for (int i=0; i< przesuniecie_Prawo; i++) cout << ' ';
		
		for(int i=0; i< 6; i++)
		{
			cout << a  <<  f << f  << f << y << ' ';
			if(i== 2) cout << h << ' ';
		}
		cout << endl;
		
	}	// wypisanie dwoch dolnych kwadratow 3x3
	cout << gracz1 << " gra: "<< zeton1 << endl;
	cout << gracz2 << " gra: "<< zeton2 << endl;
}

void ZROB_PREDEFINIOWANA(char TAB_LG[][3], char TAB_PG[][3], char TAB_LD[][3], char TAB_PD[][3], char zeton1, char zeton2)
{
TAB_LG[1][0] = zeton1;
TAB_LG[1][1] = zeton1;
TAB_LG[2][1] = zeton1;
TAB_PG[1][0] = zeton1;
TAB_PG[0][1] = zeton1;
TAB_LD[0][0] = zeton1;
TAB_LD[0][1] = zeton1;
TAB_LD[1][2] = zeton1;

TAB_LG[0][1] = zeton2;
TAB_LG[1][2] = zeton2;
TAB_PG[1][1] = zeton2;
TAB_LD[1][0] = zeton2;
TAB_LD[2][1] = zeton2;
TAB_PD[1][1] = zeton2;
TAB_PD[2][1] = zeton2;
TAB_PD[2][2] = zeton2;
}

void start()
{
	char TAB_LG[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};// LEWY GORNY KWADRAT
	char TAB_PG[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};// PRAWY GORNY KWADRAT		
	char TAB_LD[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};// LEWY DOLNY KWADRAT
	char TAB_PD[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};// PRAWY DOLNY KWADRAT
	const char a =201; // â•”
	const char b = 205;//â•
	string gracz1, gracz2;
	char opcjaMenu, zeton1, zeton2;
	
	
	system("cls");	
	cout << "Gra projektowa PENTAGO\n";
	for (int i = 0; i < 80; i++) cout << b; 
	cout << "\n\n";
	cout << "MENU:\n\n";
	cout << "(g)- zacznij gre\n";
	cout << "(o)- wczytaj predefiniowana plansze\n";
	cout << "(m)- opcje\n";
	cout << "(h)- opis i zasady gry\n";
	for(int i=0; i<80; i++) cout << b; 
	cout << "\n";
	cin >> opcjaMenu;

	switch (opcjaMenu)
	{
		case'g': 
			nazwij_graczy(gracz1, gracz2);
			WybierzZeton(gracz1, gracz2, zeton1, zeton2);
			system("cls");			
			if(wyborGry() ){
				system("cls");
			 kolko_Krzyzyk(gracz1, gracz2, zeton1, zeton2, TAB_LG, TAB_PG, TAB_LD, TAB_PD);// wyborGry zwraca true dla kolko i krzyzyk
			}
			else cout << "Trwaja prace techniczne nad pentago...";
			//PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD);
			
			break;
			
		case'o': 
			nazwij_graczy(gracz1, gracz2);			
			WybierzZeton(gracz1, gracz2, zeton1, zeton2);			
			ZROB_PREDEFINIOWANA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, zeton1, zeton2);			
			if(wyborGry() ) kolko_Krzyzyk(gracz1, gracz2, zeton1, zeton2, TAB_LG, TAB_PG, TAB_LD, TAB_PD);// wyborGry zwraca true dla kolko i krzyzyk	
			else cout << "nie wybrales o i x";
			break;

		case'm': cout << "wczytuje opcje";
			break;

		case'h': cout << "opis i zasady gry\n";
			opis(b);
			break;
			
		default: start();
	}
}

bool wyborGry()
{
	string ktoraGra; // string aby zapobiec bledom kiedy wprowadzi sie ciag znakow;
	cout << "W co chcesz zagrac:\n";
	cout << "(1) Kolko krzyzyk na planszy 6x6 (Pentago bez obracania)\n";
	cout << "(2) Pentago\n";
	cin >> ktoraGra;
	if(ktoraGra == "1") return true ;
	if(ktoraGra== "2") return false;
	else wyborGry();
}

void kolko_Krzyzyk(string gracz1, string gracz2, char zeton1, char zeton2, char TAB_LG[][3], char TAB_PG[][3], char TAB_LD[][3], char TAB_PD[][3])
{
	string cwiartkaPlanszy; // string aby zapobiec bledom przy wprowadzeniu zlych danych
	string numerPola = "0"; // string aby zapobiec bledom przy wprowadzeniu zlych danych
	
	PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
	bool remis = false;
	bool wygrana = false;
	int runda =1;
	const int SpacjaRemis = 2;
	while(runda <38)
	{

		if(runda== 37){
			for(int i =0; i<SpacjaRemis; i++) cout << '\t'; //
			cout <<   "   REMIS" << endl;
			break;
		}
		else{
			cout << "RUNDA:" << runda;
			cout << "(z) aby zmienic zetony\n";
			cout << "(p) aby wlaczyc pauze\n";
			if(runda %2 == 1) cout << gracz1;
			if(runda %2 ==0 ) cout << gracz2;
			
			cout << " wybierz cwiartke planszy (Q,W,A,S): " ;
			cin>> cwiartkaPlanszy;
			cout << "wybierz numer pola (1..9) na ktorym chcesz dostawic zeton: ";
			
			if(cwiartkaPlanszy == "q") 
			{
				cwiartkaLG(zeton1, zeton2, TAB_LG, numerPola, runda);
				system("cls");
				PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
			}
			
			if(cwiartkaPlanszy == "w") 
			{
				cwiartkaPG(zeton1, zeton2, TAB_PG, numerPola, runda);
				system("cls");
				PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
			}
		
			if(cwiartkaPlanszy == "a") 
			{
				cwiartkaLD(zeton1, zeton2, TAB_LD, numerPola, runda);
				system("cls");
				PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
			}
			
			if(cwiartkaPlanszy == "s") 
			{
			cwiartkaPD(zeton1, zeton2, TAB_PD, numerPola, runda);
			system("cls");
			PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
			}
		
		//	if(cwiartkaPlanszy == 'z'){
		//		WybierzZeton(gracz1, gracz2, zeton1, zeton2);
		//	system("cls");
		//		PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
		//		kolko_Krzyzyk(gracz1, gracz2, zeton1, zeton2, TAB_LG, TAB_PG, TAB_LD, TAB_PD);				
		//	} 
		
			if(cwiartkaPlanszy == "p"){
				char powrot;
				system("cls");
				cout << "Nastapila PAUZA, aby powrocic do rozgrywki prosze wpisac dowolny znak";
				cin >> powrot;
				PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
				runda--; // runda-- aby nie zmienila sie runda po pauzie przez "runda++" na koncu petli
			};
			if(cwiartkaPlanszy !="q" and cwiartkaPlanszy !="w" and cwiartkaPlanszy !="a" and cwiartkaPlanszy !="s" and cwiartkaPlanszy !="p" and cwiartkaPlanszy != "z"){
			system("cls");
			PLANSZA(TAB_LG, TAB_PG, TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2);
				continue;
			}
			
			SprawdzWygrana(TAB_LG, TAB_PG,  TAB_LD, TAB_PD, gracz1, gracz2, zeton1, zeton2, runda, wygrana);
		
			if(wygrana) break;
			

			runda++;
		}
	}
}

void cwiartkaLG(char zeton1, char zeton2, char TAB_LG[][3], string numerPola, int &runda)
{
	cin >> numerPola;
	
	if(numerPola== "1" && TAB_LG[2][0] != ' ') runda--; // odjecie rundy w przypadku proby blednego ruchu spowoduje ze gracz nie straci tury bo na koncu petli jest runda++;
	if(numerPola== "1" && TAB_LG[2][0] == ' ' && runda %2 == 1) TAB_LG[2][0] = zeton1; //w zaleznosci od rundy wstawia zeton odpowiedniemu graczowi;
	if(numerPola== "1" && TAB_LG[2][0] == ' ' && runda %2 == 0) TAB_LG[2][0] = zeton2;
	
	if(numerPola== "2" && TAB_LG[2][1] != ' ') runda--;
	if(numerPola== "2" && TAB_LG[2][1] == ' ' && runda %2 == 1) TAB_LG[2][1] = zeton1;
	if(numerPola== "2" && TAB_LG[2][1] == ' ' && runda %2 == 0) TAB_LG[2][1] = zeton2;
	
	if(numerPola== "3" && TAB_LG[2][2] != ' ') runda--;
	if(numerPola== "3" && TAB_LG[2][2] == ' ' && runda %2 == 1) TAB_LG[2][2] = zeton1;
	if(numerPola== "3" && TAB_LG[2][2] == ' ' && runda %2 == 0) TAB_LG[2][2] = zeton2;
	
	if(numerPola== "4" && TAB_LG[1][0] != ' ') runda--;
	if(numerPola== "4" && TAB_LG[1][0] == ' ' && runda %2 == 1) TAB_LG[1][0] = zeton1;
	if(numerPola== "4" && TAB_LG[1][0] == ' ' && runda %2 == 0) TAB_LG[1][0] = zeton2;
	
	if(numerPola== "5" && TAB_LG[1][1] != ' ') runda--;	
	if(numerPola== "5" && TAB_LG[1][1] == ' ' && runda %2 == 1) TAB_LG[1][1] = zeton1;
	if(numerPola== "5" && TAB_LG[1][1] == ' ' && runda %2 == 0) TAB_LG[1][1] = zeton2;
	
	if(numerPola== "6" && TAB_LG[1][2] != ' ') runda--;
	if(numerPola== "6" && TAB_LG[1][2] == ' ' && runda %2 == 1) TAB_LG[1][2] = zeton1;
	if(numerPola== "6" && TAB_LG[1][2] == ' ' && runda %2 == 0) TAB_LG[1][2] = zeton2;
	
	if(numerPola== "7" && TAB_LG[0][0] != ' ') runda--;
	if(numerPola== "7" && TAB_LG[0][0] == ' ' && runda %2 == 1) TAB_LG[0][0] = zeton1;
	if(numerPola== "7" && TAB_LG[0][0] == ' ' && runda %2 == 0) TAB_LG[0][0] = zeton2;
	
	if(numerPola== "8" && TAB_LG[0][1] != ' ') runda--;
	if(numerPola== "8" && TAB_LG[0][1] == ' ' && runda %2 == 1) TAB_LG[0][1] = zeton1;
	if(numerPola== "8" && TAB_LG[0][1] == ' ' && runda %2 == 0) TAB_LG[0][1] = zeton2;
	
	if(numerPola== "9" && TAB_LG[0][2] != ' ') runda--;
	if(numerPola== "9" && TAB_LG[0][2] == ' ' && runda %2 == 1) TAB_LG[0][2] = zeton1;	
	if(numerPola== "9" && TAB_LG[0][2] == ' ' && runda %2 == 0) TAB_LG[0][2] = zeton2;
	
	
	if(numerPola!="1" and numerPola!="2" and numerPola!="3" and numerPola!="4" and numerPola!="5" and numerPola!="6" and numerPola!="7" and numerPola!="8" and numerPola!="9"){
		cout << "wybierz prawidlowa liczbe!(1-9): ";
		cwiartkaLG(zeton1, zeton2, TAB_LG, numerPola, runda); 
	}
		
}

void cwiartkaPG(char zeton1, char zeton2, char TAB_PG[][3], string numerPola, int &runda)
{
	cin >> numerPola;
	
	if(numerPola== "1" && TAB_PG[2][0] != ' ') runda--; // dodanie rundy w przypadku proby blednego ruchu spowoduje ze gracz nie straci tury;
	if(numerPola== "1" && TAB_PG[2][0] == ' ' && runda %2 == 1) TAB_PG[2][0] = zeton1;
	if(numerPola== "1" && TAB_PG[2][0] == ' ' && runda %2 == 0) TAB_PG[2][0] = zeton2;
	
	if(numerPola== "2" && TAB_PG[2][1] != ' ') runda--;
	if(numerPola== "2" && TAB_PG[2][1] == ' ' && runda %2 == 1) TAB_PG[2][1] = zeton1;
	if(numerPola== "2" && TAB_PG[2][1] == ' ' && runda %2 == 0) TAB_PG[2][1] = zeton2;
	
	if(numerPola== "3" && TAB_PG[2][2] != ' ') runda--;
	if(numerPola== "3" && TAB_PG[2][2] == ' ' && runda %2 == 1) TAB_PG[2][2] = zeton1;
	if(numerPola== "3" && TAB_PG[2][2] == ' ' && runda %2 == 0) TAB_PG[2][2] = zeton2;
	
	if(numerPola== "4" && TAB_PG[1][0] != ' ') runda--;
	if(numerPola== "4" && TAB_PG[1][0] == ' ' && runda %2 == 1) TAB_PG[1][0] = zeton1;
	if(numerPola== "4" && TAB_PG[1][0] == ' ' && runda %2 == 0) TAB_PG[1][0] = zeton2;
	
	if(numerPola== "5" && TAB_PG[1][1] != ' ') runda--;
	if(numerPola== "5" && TAB_PG[1][1] == ' ' && runda %2 == 1) TAB_PG[1][1] = zeton1;
	if(numerPola== "5" && TAB_PG[1][1] == ' ' && runda %2 == 0) TAB_PG[1][1] = zeton2;
	
	if(numerPola== "6" && TAB_PG[1][2] != ' ') runda--;
	if(numerPola== "6" && TAB_PG[1][2] == ' ' && runda %2 == 1) TAB_PG[1][2] = zeton1;
	if(numerPola== "6" && TAB_PG[1][2] == ' ' && runda %2 == 0) TAB_PG[1][2] = zeton2;
	
	if(numerPola== "7" && TAB_PG[0][0] != ' ') runda--;
	if(numerPola== "7" && TAB_PG[0][0] == ' ' && runda %2 == 1) TAB_PG[0][0] = zeton1;
	if(numerPola== "7" && TAB_PG[0][0] == ' ' && runda %2 == 0) TAB_PG[0][0] = zeton2;
	
	if(numerPola== "8" && TAB_PG[0][1] != ' ') runda--;
	if(numerPola== "8" && TAB_PG[0][1] == ' ' && runda %2 == 1) TAB_PG[0][1] = zeton1;
	if(numerPola== "8" && TAB_PG[0][1] == ' ' && runda %2 == 0) TAB_PG[0][1] = zeton2;
	
	if(numerPola== "9" && TAB_PG[0][2] != ' ') runda--;
	if(numerPola== "9" && TAB_PG[0][2] == ' ' && runda %2 == 1) TAB_PG[0][2] = zeton1;	
	if(numerPola== "9" && TAB_PG[0][2] == ' ' && runda %2 == 0) TAB_PG[0][2] = zeton2;
	
	if(numerPola!="1" and numerPola!="2" and numerPola!="3" and numerPola!="4" and numerPola!="5" and numerPola!="6" and numerPola!="7" and numerPola!="8" and numerPola!="9"){
		cout << "wybierz prawidlowa liczbe!(1-9): ";
		cwiartkaPG(zeton1, zeton2, TAB_PG, numerPola, runda);
	}			
}

void cwiartkaLD(char zeton1, char zeton2, char TAB_LD[][3], string numerPola, int &runda)
{
	cin >> numerPola;
	if(numerPola== "1" && TAB_LD[2][0] != ' ') runda--;// dodanie rundy w przypadku proby blednego ruchu spowoduje ze gracz nie straci tury;
	if(numerPola== "1" && TAB_LD[2][0] == ' ' && runda %2 == 1) TAB_LD[2][0] = zeton1;
	if(numerPola== "1" && TAB_LD[2][0] == ' ' && runda %2 == 0) TAB_LD[2][0] = zeton2;
	
	if(numerPola== "2" && TAB_LD[2][1] != ' ') runda--;
	if(numerPola== "2" && TAB_LD[2][1] == ' ' && runda %2 == 1) TAB_LD[2][1] = zeton1;
	if(numerPola== "2" && TAB_LD[2][1] == ' ' && runda %2 == 0) TAB_LD[2][1] = zeton2;
	
	if(numerPola== "3" && TAB_LD[2][2] != ' ') runda--;
	if(numerPola== "3" && TAB_LD[2][2] == ' ' && runda %2 == 1) TAB_LD[2][2] = zeton1;
	if(numerPola== "3" && TAB_LD[2][2] == ' ' && runda %2 == 0) TAB_LD[2][2] = zeton2;
	
	if(numerPola== "4" && TAB_LD[1][0] != ' ') runda--;
	if(numerPola== "4" && TAB_LD[1][0] == ' ' && runda %2 == 1) TAB_LD[1][0] = zeton1;
	if(numerPola== "4" && TAB_LD[1][0] == ' ' && runda %2 == 0) TAB_LD[1][0] = zeton2;
	
	if(numerPola== "5" && TAB_LD[1][1] != ' ') runda--;
	if(numerPola== "5" && TAB_LD[1][1] == ' ' && runda %2 == 1) TAB_LD[1][1] = zeton1;
	if(numerPola== "5" && TAB_LD[1][1] == ' ' && runda %2 == 0) TAB_LD[1][1] = zeton2;
	
	if(numerPola== "6" && TAB_LD[1][2] != ' ') runda--;
	if(numerPola== "6" && TAB_LD[1][2] == ' ' && runda %2 == 1) TAB_LD[1][2] = zeton1;
	if(numerPola== "6" && TAB_LD[1][2] == ' ' && runda %2 == 0) TAB_LD[1][2] = zeton2;
	
	if(numerPola== "7" && TAB_LD[0][0] != ' ') runda--;
	if(numerPola== "7" && TAB_LD[0][0] == ' ' && runda %2 == 1) TAB_LD[0][0] = zeton1;
	if(numerPola== "7" && TAB_LD[0][0] == ' ' && runda %2 == 0) TAB_LD[0][0] = zeton2;
	
	if(numerPola== "8" && TAB_LD[0][1] != ' ') runda--;
	if(numerPola== "8" && TAB_LD[0][1] == ' ' && runda %2 == 1) TAB_LD[0][1] = zeton1;
	if(numerPola== "8" && TAB_LD[0][1] == ' ' && runda %2 == 0) TAB_LD[0][1] = zeton2;	
	
	if(numerPola== "9" && TAB_LD[0][2] != ' ') runda--;
	if(numerPola== "9" && TAB_LD[0][2] == ' ' && runda %2 == 1) TAB_LD[0][2] = zeton1;	
	if(numerPola== "9" && TAB_LD[0][2] == ' ' && runda %2 == 0) TAB_LD[0][2] = zeton2;	
	
	if(numerPola!="1" and numerPola!="2" and numerPola!="3" and numerPola!="4" and numerPola!="5" and numerPola!="6" and numerPola!="7" and numerPola!="8" and numerPola!="9"){
		cout << "wybierz prawidlowa liczbe!(1-9): ";
		cwiartkaLD(zeton1, zeton2, TAB_LD, numerPola, runda);
	}
		
}

void cwiartkaPD(char zeton1, char zeton2, char TAB_PD[][3], string numerPola, int &runda)
{
	cin >> numerPola;
	if(numerPola== "1" && TAB_PD[2][0] != ' ') runda--;// dodanie rundy w przypadku proby blednego ruchu spowoduje ze gracz nie straci tury;
	if(numerPola== "1" && TAB_PD[2][0] == ' ' && runda %2 == 1) TAB_PD[2][0] = zeton1;
	if(numerPola== "1" && TAB_PD[2][0] == ' ' && runda %2 == 0) TAB_PD[2][0] = zeton2;
	
	if(numerPola== "2" && TAB_PD[2][1] == ' ') runda--;
	if(numerPola== "2" && TAB_PD[2][1] == ' ' && runda %2 == 1) TAB_PD[2][1] = zeton1;
	if(numerPola== "2" && TAB_PD[2][1] == ' ' && runda %2 == 0) TAB_PD[2][1] = zeton2;
	
	if(numerPola== "3" && TAB_PD[2][2] == ' ') runda--;
	if(numerPola== "3" && TAB_PD[2][2] == ' ' && runda %2 == 1) TAB_PD[2][2] = zeton1;
	if(numerPola== "3" && TAB_PD[2][2] == ' ' && runda %2 == 0) TAB_PD[2][2] = zeton2;
	
	if(numerPola== "4" && TAB_PD[1][0] == ' ') runda--;
	if(numerPola== "4" && TAB_PD[1][0] == ' ' && runda %2 == 1) TAB_PD[1][0] = zeton1;
	if(numerPola== "4" && TAB_PD[1][0] == ' ' && runda %2 == 0) TAB_PD[1][0] = zeton2;
	
	if(numerPola== "5" && TAB_PD[1][1] == ' ') runda--;
	if(numerPola== "5" && TAB_PD[1][1] == ' ' && runda %2 == 1) TAB_PD[1][1] = zeton1;
	if(numerPola== "5" && TAB_PD[1][1] == ' ' && runda %2 == 0) TAB_PD[1][1] = zeton2;
	
	if(numerPola== "6" && TAB_PD[1][2] == ' ') runda--;
	if(numerPola== "6" && TAB_PD[1][2] == ' ' && runda %2 == 1) TAB_PD[1][2] = zeton1;
	if(numerPola== "6" && TAB_PD[1][2] == ' ' && runda %2 == 0) TAB_PD[1][2] = zeton2;
	
	if(numerPola== "7" && TAB_PD[0][0] == ' ') runda--;
	if(numerPola== "7" && TAB_PD[0][0] == ' ' && runda %2 == 1) TAB_PD[0][0] = zeton1;
	if(numerPola== "7" && TAB_PD[0][0] == ' ' && runda %2 == 0) TAB_PD[0][0] = zeton2;
	
	if(numerPola== "8" && TAB_PD[0][1] == ' ') runda--;
	if(numerPola== "8" && TAB_PD[0][1] == ' ' && runda %2 == 1) TAB_PD[0][1] = zeton1;
	if(numerPola== "8" && TAB_PD[0][1] == ' ' && runda %2 == 0) TAB_PD[0][1] = zeton2;
	
	if(numerPola== "9" && TAB_PD[0][2] == ' ') runda--;
	if(numerPola== "9" && TAB_PD[0][2] == ' ' && runda %2 == 1) TAB_PD[0][2] = zeton1;	
	if(numerPola== "9" && TAB_PD[0][2] == ' ' && runda %2 == 0) TAB_PD[0][2] = zeton2;
	
	
	if(numerPola!="1" and numerPola!="2" and numerPola!="3" and numerPola!="4" and numerPola!="5" and numerPola!="6" and numerPola!="7" and numerPola!="8" and numerPola!="9"){
		cout << "wybierz prawidlowa liczbe!(1-9): ";
		cwiartkaPD(zeton1, zeton2, TAB_PD, numerPola, runda);
	}	
}

void Wygrana(bool& wygrana, char& zeton)
{
	cout << "Gratulacje " << zeton << " wygral " << endl;
 			wygrana = true;
}

bool SprawdzWygrana(char TAB_LG[3][3], char TAB_PG[3][3], char TAB_LD[3][3], char TAB_PD[3][3],  string gracz1, string gracz2, char zeton1, char zeton2, int runda, bool & wygrana)
{
	char zeton;
	if(runda %2 == 1) zeton = zeton1;
 	if(runda %2 == 0) zeton = zeton2;
 	
 	for(int i=0; i<3; i++)//sprawdzenie w poziomie dla gornej czesci planszy;
 	{
 		if(TAB_LG[i][0] == zeton and TAB_LG[i][1] == zeton and TAB_LG[i][2] == zeton and TAB_PG[i][0] == zeton and TAB_PG[i][1] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
		else if(TAB_LG[i][1] == zeton and TAB_LG[i][2] == zeton and TAB_PG[i][0] == zeton and TAB_PG[i][1] == zeton and TAB_PG[i][2] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
	}
			
	for(int i=0; i<3; i++)//sprawdzenie w poziomie dla dolnej czesci planszy;
 	{
 		if(TAB_LD[i][0] == zeton and TAB_LD[i][1] == zeton and TAB_LD[i][2] == zeton and TAB_PD[i][0] == zeton and TAB_PD[i][1] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
		else if(TAB_LD[i][1] == zeton and TAB_LD[i][2] == zeton and TAB_PD[i][0] == zeton and TAB_PD[i][1] == zeton and TAB_PD[i][2] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
	}
		//SPRAWDZANIE PIONOW;	
	for(int i=0; i<3; i++)//sprawdzenie w pionie dla lewej czesci planszy;
 	{
 		if(TAB_LG[0][i] == zeton and TAB_LG[1][i] == zeton and TAB_LG[2][i] == zeton and TAB_LD[0][i] == zeton and TAB_LD[1][i] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
		else if(TAB_LG[1][i] == zeton and TAB_LG[2][i] == zeton and TAB_LD[0][i] == zeton and TAB_LD[1][i] == zeton and TAB_LD[2][i] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
	}
		
	for(int i=0; i<3; i++)//sprawdzenie w pionie dla prawej czesci planszy;
 	{
 		if(TAB_PG[0][i] == zeton and TAB_PG[1][i] == zeton and TAB_PG[2][i] == zeton and TAB_PD[0][i] == zeton and TAB_PD[1][i] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
		else if(TAB_PG[1][i] == zeton and TAB_PG[2][i] == zeton and TAB_PD[0][i] == zeton and TAB_PD[1][i] == zeton and TAB_PD[2][i] == zeton) {
 			Wygrana(wygrana, zeton);
		 }
	} 
		//SPRAWDZANIE UKOSOW;	
	if(TAB_LG[0][0] == zeton and TAB_LG[1][1] == zeton and TAB_LG[2][2] == zeton and TAB_PD[0][0] == zeton and TAB_PD[1][1] == zeton ){
		Wygrana(wygrana, zeton);
	}
	else if(TAB_LG[1][1] == zeton and TAB_LG[2][2] == zeton and TAB_PD[0][0] == zeton and TAB_PD[1][1] == zeton and TAB_PD[2][2] == zeton) {	
		Wygrana(wygrana, zeton);
 	}
 	
 	if(TAB_LD[2][0] == zeton and TAB_LD[1][1] == zeton and TAB_LD[0][2] == zeton and TAB_PG[2][0] == zeton and TAB_PG[1][1] == zeton){
 		Wygrana(wygrana, zeton);	
	 }
	else if(TAB_LD[1][1] == zeton and TAB_LD[0][2] == zeton and TAB_PG[2][0] == zeton and TAB_PG[1][1] == zeton and TAB_PG[0][2] == zeton){
 		Wygrana(wygrana, zeton);	
	 }	
	 
	if(TAB_LD[1][0] == zeton and TAB_LD[0][1] == zeton and TAB_LG[2][2] == zeton and TAB_PG[1][0] == zeton and TAB_PG[0][1] == zeton){
		Wygrana(wygrana, zeton);
	}
	if(TAB_LD[2][1] == zeton and TAB_LD[1][2] == zeton and TAB_PD[0][0] == zeton and TAB_PG[2][1] == zeton and TAB_PG[1][2] == zeton){
		Wygrana(wygrana, zeton);
	}
	
	if(TAB_LG[1][0] == zeton and TAB_LG[2][1] == zeton and TAB_LD[0][2] == zeton and TAB_PD[1][0] == zeton and TAB_PD[2][1] == zeton){
		Wygrana(wygrana, zeton);
	}
	
	if(TAB_LG[0][1] == zeton and TAB_LG[1][2] == zeton and TAB_PG[2][0] == zeton and TAB_PD[0][1] == zeton and TAB_PD[1][2] == zeton){
		Wygrana(wygrana, zeton);
	}
}
	
/*void ZmienZetony
	{
	system("cls");
	cout << "Jakim zetonem chce grac " << gracz1 << "\n" << "(do wyboru: (1)kolko, (2)krzyzyk, (3)pik, (4)serce):";
	bool nieprawidlowyWybor=true;
	
	while(nieprawidlowyWybor)
	{	
		cin >> zeton1;
		switch(zeton1)
		{
			case '1': zeton1 = 'o';
				 nieprawidlowyWybor=false; break;
				 
			case '2': zeton1 = 'x';
				 nieprawidlowyWybor=false; break;
				 
			case '3': zeton1 = 6;
				 nieprawidlowyWybor= false; break;
				 
			case '4': zeton1 = 3;
				 nieprawidlowyWybor= false;break;
				 
			default: cout << "wybierz prawidlowa liczbe! \n"; break;
		}
	}
	system("cls");
		
	zeton2=zeton1;
	
	while(zeton2 == zeton1){
		cout << "Jakim zetonem chce grac " << gracz2 << "\n"<< "(do wyboru: (1)kolko, (2)krzyzyk, (3)pik, (4)serce):";
		
		nieprawidlowyWybor=true;
		while(nieprawidlowyWybor)
		{	
			cin >> zeton2;
			switch(zeton2)
			{
				case '1': zeton2 = 'o'; 
					nieprawidlowyWybor= false; break;
					
				case '2': zeton2 = 'x'; 
					nieprawidlowyWybor= false;	break;
					
				case '3': zeton2 = 6;
					nieprawidlowyWybor= false;	break;
					
				case '4': zeton2 = 3; 
					nieprawidlowyWybor= false;	break;
			
				default: cout << "Wybierz prawidlowa liczbe! \n"; break;
			}
			system("cls");	
			if(zeton2==zeton1)	cout << "Zetony nie moga byc takie same! \n \n";
		}
	}
}
	*/
	
int main()
{
	
	//menu
	start();

}

