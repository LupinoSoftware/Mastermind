// AUTHOR:Giuliano Lupi
//DATE:03/01/2022
//TITLE:MASTERMIND 
/*ALGORITHM:Fiduciosa simulazione del gioco Mastermind con varie difficoltà. Riuscirai a battere la macchina?*/
#include <cstdlib>
#include <iostream>
#include <time.h>
 #include <winbgim.h>
 #include <windows.h>
 
using namespace std;

void rounded(int x, int y, int b, int h, int raggio){
	line(x+raggio,y,b+x,y);
	line(x+raggio,h+y+raggio,b+x,h+y+raggio);

	line(x,y+raggio,x,h+y);
	line(b+x+raggio,y+raggio,b+x+raggio,h+y);
	
	arc(x+raggio,y+raggio,90,180,raggio);
	arc(x+b,y+raggio,0,90,raggio);
	arc(x+raggio,y+h,180,270,raggio);
	arc(x+b,y+h,270,0,raggio);
}

int main()
{		
	//VARIABILI CODE
	srand((unsigned)time(NULL));
    int sol[6], ris[6];
    int i, k;
    int num, r, bianchi, neri;
    int c = 0;
    int m = 0;
    int missioni=num=rand()%79+38;
    bool vittoria, ripetuti, facile = false;

    //OUTPUT MENU'
    cout << "********************BENVENUTO IN MASTERMIND********************\n\n";
    cout<<"Benvenuto in Mastermind caro giocatore!\n\n";
    cout << "SCEGLI LA DIFFICOLTA'\n\n1] IMPIEGATO POSTALE\n2] HACKER RUSSO\n\n";
    cout<<" La modalita' IMPIEGATO POSTALE permette di giocare in modo\n tranquillo e rilassante aiutando il giocatore a capire le\n biglie posizionate in modo errato.\n\n";
    cout<<" La modalita' HACKER RUSSO permette di mettere il giocatore\n nei panni di Yuri Dimitrovick, agente segreto russo\n impegnato in oltre " <<missioni<< " missioni internazionali.\n La difficolta' aumenta e nessuno potra' aiutarlo.\n\n Scegli con attenzione, questo \x8a un punto di non ritorno.\n\n";
    do { cin >> m; if (m == 1) { facile = true; } if(m<1 || m>2){cout<<"Digita 1 o 2 per confermare la tua scelta\n";} } while (m < 1 || m>2);
    if (m==2){cout<<"\n///////////////////////////////////////////////////////////////\n\n"<<"Visto che hai selezionato questa difficolta', non potevamo certo lasciarti a piedi!\n Ecco a te delle brevi istruzioni:\n _Se visualizzi nel terminale "" * "" vorra' dire che la biglia \x8a stata inserita nel posto giusto.\n _Se visualizzi nel terminale "" o "" vorra' dire che la biglia \x8a giusta, ma nel posto sbagliato.\n _Se non visualizzi nulla nel terminale vuol dire che nessuna biglia inserita \x8a corretta.\n FAI ATTENZIONE\n Non sempre i simboli compaiono in ordine!\n";	}
    cout<<"\n///////////////////////////////////////////////////////////////\n\n";
    cout << "CON QUANTI COLORI VUOI GIOCARE?\nUtilizzane al massimo 6\n\n";
    do { cin >> c; if (c > 6) { cout << "Utilizza al massimo 6 colori\n\n"; } if (c < 4) { cout << "Utiizza piu' di 3 colori\n"; } } while (c < 4 || c>6);
    cout<<"\n///////////////////////////////////////////////////////////////\n\n";
    cout << "VUOI GIOCARE CON COLORI RIPETUTI?\n\n1] SI\n2] NO\n\n";
    do{cin >> r; if(r<1 || r>2){cout<<"Digita 1 o 2 per confermare la tua scelta\n";}}while (r<1 || r>2);
    cout<<"\n///////////////////////////////////////////////////////////////\n\n";
    if (r == 1) { ripetuti = true; }
    else { ripetuti = false; }
	cout<<"Ricordati che per giocare dovrai TENERE QUESTA FINESTRA APERTA";
    //GENERA LA SOLUZIONE
    for (i = 0; i < c; i++) { sol[i] = -1; }
    for (i = 0; i <= c - 1; i++) {
        do {
            num = rand() % 9 + 1;
            vittoria = false;
            for (k = 0; k < i; k++)
                if (num == sol[k]) vittoria = true;
        } while (vittoria == true);
        sol[i] = num;
        //MOSTRA SOLUZIONE
		//cout<<sol[i];
    }
	initwindow(900,800);
	int altezza=getmaxy();
	int larghezza=getmaxx();
	
	
	//COLORI
	int brown_scuro=COLOR(91,58,41);
	int ball=COLOR(255,0,0);
	int sfondo=COLOR (189,15,200);
	int rosso=COLOR(255,0,0);
	int arancio=COLOR(255,128,0);
	int giallo=COLOR(255,255,0);
	int verde=COLOR(0,255,0);
	int azzurro_chiaro=COLOR(0,255,255);
	int azzurro=COLOR(0,128,255);
	int blu=COLOR(0,0,255);
	int viola=COLOR(127,0,255);
	int rosa=COLOR(255,0,255);
	int brown=COLOR(189,115,52);
	int stelle=COLOR(255,255,255);
	int temporaneo=COLOR(254,0,0);
	int bianco=COLOR(255,255,254);
	int spazio=COLOR(0,0,0);
	int nero=COLOR(0,0,1);
	
	//PREGIOCO
	setcolor(bianco);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
	outtextxy(getmaxx()/2-400,getmaxy()/3, "MASTERMIND");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(getmaxx()/2-225,getmaxy()/2,"L O A D I N G");
	
	//STELLE
		setlinestyle(0,0,2);
		setcolor(stelle);
		for (int i=0; i<1000;i++){
			int stellax=rand()%getmaxx();
				int stellay=rand()%getmaxy();
				int raggio=2;
				setcolor(temporaneo);
				circle(stellax,stellay,raggio);
				setfillstyle(1,stelle);
				floodfill(stellax,stellay,temporaneo);
				setcolor(stelle);
				circle(stellax,stellay,raggio);
		}
	delay(2000);	
	//HANDMADE OSCURA IMMAGINE
	setcolor(nero);
	rectangle(0,0,900,800);
	setfillstyle(1,spazio);
	floodfill(1,1,nero);
	
	//SUONI START (AM)
	Beep (440,120); Beep (554,120); Beep (659,120); Beep (880,200); 
	floodfill(1,1,rosso);
	
	//STELLE 2
		setlinestyle(0,0,2);
		setcolor(stelle);
		for (int i=0; i<1000;i++){
			int stellax=rand()%getmaxx();
				int stellay=rand()%getmaxy();
				int raggio=2;
				setcolor(temporaneo);
				circle(stellax,stellay,raggio);
				setfillstyle(1,stelle);
				floodfill(stellax,stellay,temporaneo);
				setcolor(stelle);
				circle(stellax,stellay,raggio);
		}
	
	//OUTPUT LEGENDA
	int spazio_x=getmaxx()/2+40;
	int spazio_y=getmaxy()/7;
	int spazio_c_i_x=spazio_x+325;
	int spazio_c_f_x=spazio_x+350;
	int spazio_rx=spazio_c_i_x;
	int spazio_ry=spazio_y;
	setcolor(bianco);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(getmaxx()/2+40,getmaxy()/14, "MASTERMIND");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2+140,getmaxy()/9, "LEGENDA");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	for (int j=1; j<=9; j++){
		switch (j){
			case 1:{outtextxy(spazio_x,spazio_y,"1 = ROSSO");setfillstyle (1,rosso);break;}	
			case 2:{outtextxy(spazio_x,spazio_y+50,"2 = ARANCIO"); setfillstyle (1,arancio); break;}
			case 3:{outtextxy(spazio_x,spazio_y+100,"3 = GIALLO"); setfillstyle (1,giallo); break;}
			case 4:{outtextxy(spazio_x,spazio_y+150,"4 = VERDE"); setfillstyle (1,verde); break;}
			case 5:{outtextxy(spazio_x,spazio_y+200,"5 = AZZURRINO"); setfillstyle (1,azzurro_chiaro); break;}
			case 6:{outtextxy(spazio_x,spazio_y+250,"6 = AZZURRO"); setfillstyle (1,azzurro); break;}
			case 7:{outtextxy(spazio_x,spazio_y+300,"7 = BLU"); setfillstyle (1,blu); break;}
			case 8:{outtextxy(spazio_x,spazio_y+350,"8 = VIOLA"); setfillstyle (1,viola); break;}
			case 9:{outtextxy(spazio_x,spazio_y+400,"9 = ROSA"); setfillstyle (1,rosa); break;}
		}
		rectangle(spazio_c_i_x,spazio_ry,spazio_c_f_x,spazio_ry+25);
		floodfill (spazio_c_i_x+10,spazio_ry+10, bianco);
		spazio_ry=spazio_ry+50;
	}
	//VARI OUTPUT IN BASE ALLE DIFFICOLTA'
	if (facile==false){
		settextstyle(DEFAULT_FONT,HORIZ_DIR,30);
		outtextxy(getmaxx()-400,getmaxy()-200,"*");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(getmaxx()-320,getmaxy()-180," Biglia posizionata");
		outtextxy(getmaxx()-320,getmaxy()-160," Correttamente");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
		outtextxy(getmaxx()-400,getmaxy()-100,"0");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		outtextxy(getmaxx()-320,getmaxy()-80," Biglia posizionata");
		outtextxy(getmaxx()-320,getmaxy()-60," in modo errato");
	}
	else{
		settextstyle(DEFAULT_FONT,HORIZ_DIR,8);
		outtextxy(getmaxx()-400,getmaxy()-200,"MASTER");
		outtextxy(getmaxx()-400,getmaxy()-100,"MIND");
	}
	
	
	//SFONDO TABELLONE
	setcolor(rosso);
	rectangle(60,60,350,750);
	setfillstyle(1,spazio);
	floodfill(61,61,rosso);
	
	//DISEGNA IL TABELLONE
	setcolor(brown_scuro);
	setlinestyle(0,0,3);
	int raggio=50;
	int h=700;
	int b=300;
	int x=40;
	int y=10;
	rounded(x,y,b,h,raggio);
	
	//CERCHI
	int raggioC=b/c/4;
	int raggiolc=b/c/8;
	int tentativi=10;
	int colonna;
	int riga;
	int xcl=340;
	for ( colonna=1;colonna<=c;colonna++){
		for( riga=0;riga<tentativi;riga++){
			circle(x+((b-50)/(c)*colonna),y+h-h/(tentativi)*riga,raggioC);
		}
	}
	for(riga=0;riga<tentativi;riga++){
		for (int cl=0; cl<c; cl++){
			circle(xcl,y+h-h/(tentativi)*riga,raggiolc);
		}
	}
	
	//DETTAGLI LEGNO
	setfillstyle(1,brown);
	floodfill(x+raggio,y+3,brown_scuro);

	//GESTIONE TURNI
    vittoria=false;
    for (riga=0; riga<10 && vittoria==false; riga++){
    	cout<<"\n\n///////////////////////////////////////////////////////////////\n";
       	cout << "\n" << riga+1 << "o TURNO\n";
       	cout << "inserisci " << c << " colori:\n";
       	for (colonna = 1; colonna <= c; colonna++){
		    do {
                //CONDIZIONI RIPETUTI
                do {
                    cin >> num;
                    cout << "\n";
                } while (num < 0 || num > 9);
                //CONDIZIONI NON RIPETUTI
                if (ripetuti == false) {
                    vittoria = false;
                    for (i = 0; i < colonna-1; i++){
                        if (ris[i] == num) {
                            vittoria = true;
                            cout << "\nIl colore inserito \x8a gia' presente\nInserisci un altro colore:\n";
                            //SUONI ERROR
							Beep(440,100);
                            Beep(330,100);
                            Sleep(500);
                        }
                    }
                }
            } while (vittoria == true);
            //COLORO I CERCHI 
            ris[colonna-1] = num;
            switch (num){
				case 1:{setfillstyle(1,rosso);break;}
				case 2:{setfillstyle(1,arancio);break;}
				case 3:{setfillstyle(1,giallo);break;}
				case 4:{setfillstyle(1,verde);break;}
				case 5:{setfillstyle(1,azzurro_chiaro);break;}
				case 6:{setfillstyle(1,azzurro);break;}
				case 7:{setfillstyle(1,blu);break;}
				case 8:{setfillstyle(1,viola);break;}
				case 9:{setfillstyle(1,rosa);break;}
			}
			floodfill(x+((b-50)/(c)*colonna),y+h-h/(10)*riga,brown);	
			//SUONI INSERIMENTO
			Beep(440,100);
			Beep(880,100);
			Sleep(500);
        }
        vittoria = false;
        bool giusto = true;
        bianchi = 0;
        neri = 0;
        for (i = 0; i < c; i++) {
            for (k = 0; k < c; k++) {
                if (sol[i] == ris[k]) {
                    if (i == k) {
                        bianchi = bianchi + 1;
                        if (facile == true) {
                            cout << "\nIl " << i + 1 << "o colore \x8a CORRETTO";
                        }
                    }
                    else {
                        neri = neri + 1;
                        if (facile == true || facile==true && ripetuti==true) {
                            cout << "\nIl " << k+1 << "o colore \x8a nella posizione sbagliata";
                        }
                    }
                }
            } 
        }   
        cout << endl;
        if (facile==false){
        	 //OUTPUT BIANCHI E NERI
        for (int b = 0; b < bianchi; b++){ cout << "*"; }
        for (int n = 0; n < neri; n++){ cout << "o"; }
		}
        //OUTPUT RISULTATI
        if (bianchi == c) { 
			vittoria = true; cout << "\n\n********COMPLIMENTI HAI VINTO********"; 
			//HANDMADE OSCURA IMMAGINE
			setcolor(nero);
			rectangle(0,0,900,800);
			setfillstyle(1,spazio);
			floodfill(10,10,nero);
			//OUTPUT VINTO
			setcolor(verde);
			setlinestyle(0,0,2);
			for (int i=0; i<1000;i++){
				int stellax=rand()%getmaxx();
					int stellay=rand()%getmaxy();
					int raggio=2;
					setcolor(temporaneo);
					circle(stellax,stellay,raggio);
					setfillstyle(1,verde);
					floodfill(stellax,stellay,temporaneo);
					setcolor(verde);
					circle(stellax,stellay,raggio);
			}
			setcolor(verde);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
			outtextxy(getmaxx()/2-400,getmaxy()/3, "HAI VINTO");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
			outtextxy(getmaxx()/2-225,getmaxy()/2,"COMPLIMENTI");
			//SUONI VITTORIA (AM)
			Beep (440,100); Beep (554,100); Beep (659,100); Beep (880,200); 
			delay(5000);
		}
        else {
            if (facile == false) { cout << "\nRitenta sarai piu' fortunato\n";}
        }
	}
    
    cout << "\nLA SOLUZIONE ERA: ";
    for (i = 0; i < c; i++){cout << sol[i]<< " ";}
    	if (vittoria==false){
    		//HANDMADE OSCURA IMMAGINE
			setcolor(nero);
			rectangle(0,0,900,800);
			setfillstyle(1,spazio);
			floodfill(10,10,nero);
			//OUTPUT SCONFITTA
			setcolor(rosso);
			setlinestyle(0,0,2);
			for (int i=0; i<1000;i++){
				int stellax=rand()%getmaxx();
					int stellay=rand()%getmaxy();
					int raggio=2;
					setcolor(temporaneo);
					circle(stellax,stellay,raggio);
					setfillstyle(1,rosso);
					floodfill(stellax,stellay,temporaneo);
					setcolor(rosso);
					circle(stellax,stellay,raggio);
			}
			setcolor(rosso);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
			outtextxy(getmaxx()/2-400,getmaxy()/3, "HAI PERSO");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
			outtextxy(getmaxx()/2-225,getmaxy()/2,"UN PECCATO");
			//SUONI SCONFITTA (Am)
			Beep (440,100); Beep (330,100); Beep (262,100); Beep (220,200);
			delay(5000);
		}

    return 0;
}

/*CHECK LIST
*/
