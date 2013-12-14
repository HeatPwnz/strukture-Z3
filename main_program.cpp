#include<iostream>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include "red_array.h"
//#include "red_pointer.h"
using namespace std;

struct petorka{
       int ai, bi, ci, di, ei;
};
int n, n1, n2, ponavljanje=1;

petorka *prvi(red *Q){
     cout<<"Koliko pacijenata zelite generirati?? ";
     cin>>n;
     petorka *a=new petorka[n*3];
     int stanje[5]={0,0,0,0,0};
     int redoslijed=0;
     srand(time(0));
     rand();
     for(int i=0;i<n*3;i++){
     	a[i].ai=rand()%250+50;
     	a[i].bi=rand()%250+50;
     	a[i].ci=rand()%5+1;
     	a[i].di=rand()%4+1;
     	a[i].ei=rand()%5+1;
     }
     cout << endl <<"Uspjesno dodano " << n*3 << " pacijenata u red... " << endl;
     return a;   
}
void ispis_prioritet(int br){
     switch(br){
        case 1: cout << "Hitni Sluc."; break;
        case 2: cout << "Invalidi   "; break;
        case 3: cout << "Trudnice   "; break;
        case 4: cout << "Mlada djeca"; break;
        case 5: cout << "Ostali     "; break;
        }
}
void ispis_usluga(int br){
     switch(br){
        case 1: cout << "Pregled   "; break;
        case 2: cout << "Previjanje"; break;
        case 3: cout << "Recepti   "; break;
        case 4: cout << "Uputnice  "; break;
        }
}
void ispis_ordinacija(int br){
	switch(br){
		case 1: cout << "Obiteljska medicina"; break;
		case 2: cout << "Oftalomologija     "; break;
		case 3: cout << "Dermatovenerologija"; break;
		case 4: cout << "Ginekologija       "; break;
		case 5: cout << "Urologija          "; break;
	}
}
void preslozi(red *Q, int prioritet){
     pacijent pom;
     red *P=InitQ(P);
     for(int i=0;i<n*3;i++){
           pom=FrontQ(Q);
           DeQueueQ(Q);
           if(pom.ci==prioritet)
               EnQueueQ(pom, P);
           else
               EnQueueQ(pom, Q);                        
     }
     while(!IsEmptyQ(P)){
           pom=FrontQ(P);
           DeQueueQ(P);
           EnQueueQ(pom, Q);                    
     }     
}

void prvi(red *Q, petorka *a, bool kreirano){
     pacijent unos;
     cout << endl << "Unos podataka o pacijentima... " << endl;
     if(kreirano&&n>1) cout << endl <<"Pacijen je vec unesen..." << endl;
     if(kreirano&&n>1) return;

     srand(time(0));
     rand();
     for(int i=0;i<n*3;i++){
             unos.ai=a[i].ai;
             unos.bi=a[i].bi;
             unos.ci=a[i].ci;
             unos.di=a[i].di;
             unos.ei=a[i].ei;

             cout << "Unesite ime " << i+1 << ". pacijenta: ", cin >> unos.ime;
             cout << "Unesite prezime " << i+1 << ". pacijenta: ", cin >> unos.prezime;
             if((unos.ci==3&&unos.ei==4)||(unos.ci==3)||(unos.ei==4))
             	unos.spol='z';
             else if(unos.ei==5)
             	unos.spol='m';
             else{
             	int x;
             	x=rand()%2;
             	switch(x){
             		case 0: unos.spol='m';
             				break;
             		case 1: unos.spol='z';
             				break;
             	}
             }
             if(unos.ci==4){
             	unos.dan=(rand()%30)+1;
             	unos.mj=(rand()%12)+1;
             	unos.god=(rand()%6)+2007;
             }
             else{
             	unos.dan=(rand()%30)+1;
             	unos.mj=(rand()%12)+1;
             	unos.god=(rand()%67)+1940;
             }
             EnQueueQ(unos, Q);
     }
     for(int i=1;i<n*3;i++)
             preslozi(Q, i);
}
void ispis_oft(red *Q){
     pacijent ispis;
     red *P=InitQ(P);
     cout << endl << "\t\t\t\tPacijenti stariji vise od 25god i na redu za pregled kod oftalmologa " << endl;
     cout << "\t\t\t\t_____________________________________________________________________" << endl << endl;
     for(int i=0;i<n*3;i++){
            
            ispis=FrontQ(Q);
            DeQueueQ(Q);  
            if(ispis.di==1&&ispis.ei==2&&ispis.god<=1988){
            	ispis_prioritet(ispis.ci), cout << "\t\t";
				ispis_usluga(ispis.di), cout << "\t\t";
				ispis_ordinacija(ispis.ei), cout << "\t\t";
				cout << ispis.ime << "\t\t";
				cout << ispis.prezime << "\t\t";
				cout << ispis.spol << "\t\t";
				cout << ispis.dan << "." << ispis.mj << "." << ispis.god << "." << endl;
            }
            EnQueueQ(ispis, Q);          
     }
     cout << endl << endl;
}
void ispis(red *Q, int br){
     pacijent ispis;
     cout << endl << "\t\t\t\t\t~~~~~~~~~~~~~ ISPIS PODATAKA O PACIJENTIMA ~~~~~~~~~~~~~~~~~ " << endl << endl;
	 cout << "Prioritet\t\tUsluga\t\t\tOrdinacija\t\t\tIme\t\tPrezime\t\tSpol\t\tDatum rodjenja" << endl;
	 cout << "_________\t\t______\t\t\t__________\t\t\t___\t\t_______\t\t____\t\t______________" << endl;
     red *P=InitQ(P);
     if(IsEmptyQ(Q)) cout << endl << "Red je prazan... " << endl;
     for(int i=0;i<n;i++){
     while(!IsEmptyQ(Q)){          
            ispis=FrontQ(Q);
            DeQueueQ(Q);
            Sleep(ispis.ai);
			
			ispis_prioritet(ispis.ci), cout << "\t\t";
			ispis_usluga(ispis.di), cout << "\t\t";
			ispis_ordinacija(ispis.ei), cout << "\t\t";
			cout << ispis.ime << "\t\t";
			cout << ispis.prezime << "\t\t";
			cout << ispis.spol << "\t\t";
			cout << ispis.dan << "." << ispis.mj << "." << ispis.god << "." << endl;
            EnQueueQ(ispis, P);          
     }}
     while(!IsEmptyQ(P)){
            EnQueueQ(FrontQ(P),Q);
            DeQueueQ(P);
     }
     cout << endl << endl;
}

void drugi(red *Q){
     cout << endl << "\t\t~~~~~ Brisanje invalida starijih od 50god koji cekaju previjanje kod obit. ljecnika ~~~~~" << endl;    
     pacijent osoba;
     red *T=InitQ(T);
     n1=0;
     red *P=InitQ(P);
     while(!IsEmptyQ(Q)){
          osoba=FrontQ(Q);
          DeQueueQ(Q);
          n--;
          if(osoba.ci==2 && osoba.di==2 && osoba.ei==1 && osoba.god>=1963)             
              EnQueueQ(osoba, T), n1++;
          else EnQueueQ(osoba, P), n++;
     }
     while(!IsEmptyQ(P)){
            EnQueueQ(FrontQ(P),Q);
            DeQueueQ(P);
     }
     ispis(Q, n);          
}

int kontrola_postotak;
void rekurzija(red *Q, red *N){
     if(IsEmptyQ(Q)) return;
     
     pacijent pom=FrontQ(Q);
     DeQueueQ(Q), n--;
     rekurzija(Q, N);
     if(kontrola_postotak>=0)EnQueueQ(pom, N), n2++, kontrola_postotak--;
     else EnQueueQ(pom, Q), n++;         
}
void rekurzija_okreni(red *Q){
     if(IsEmptyQ(Q)) return;
     pacijent pom=FrontQ(Q);
     DeQueueQ(Q);
     rekurzija_okreni(Q);
     EnQueueQ(pom, Q);    
}
void treci(red *Q, red *N){  
     kontrola_postotak=int(n*0.3);
      
     n2=0;
     if(IsEmptyQ(N)){
         rekurzija(Q, N);
         rekurzija_okreni(Q);
     }
     cout<<"\n\t\t\t-----------------------Red brzih usluga-----------------------\n"; 
     ispis(N, n2);
     cout<<"\n\n\t\t\t----------------- STANJE U GLAVNOM REDU ---------------------\n";
     ispis(Q, n);
}
int main(){
	srand(time(0));
	rand();
    int izbor;
    bool kreirano=false;
    red *Q=InitQ(Q);
    red *N=InitQ(N);
    red *B=InitQ(B);
    do{
    	cout << endl << "1. Generiranje Ntorke, unos klijenata i ispis " << endl;
    	cout<<"2. Brisanje starih invalida kod obiteljske medicine " << endl;
    	cout<<"3. Red brzih usluga" << endl;
    	cout<<"9. Izlaz iz programa" << endl;    
    	cout<<"Vas izbor: ";
    	cin>>izbor;
    
    	switch(izbor){
    
         	case 1:{
              	system("cls");
              	petorka *pomocna=prvi(Q);
              	prvi(Q, pomocna, kreirano);
              	kreirano=true;
              	ispis(Q, n);
              	ispis_oft(Q);break;}
         	case 2:
              	system("cls");
              	drugi(Q); break;
         	case 3:
              	system("cls");
              	treci(Q,N);break;
    
    	}
    }while(izbor!=9);
    system("pause");   
    return 0;   
}
