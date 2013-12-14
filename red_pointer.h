#include<iostream>
using namespace std;
struct pacijent{
       int ai, bi, ci, di, ei;
       char ime[30], prezime[30], spol;
       int dan, mj, god;    
};
struct qu {
       pacijent element;
       qu *sljedeci;
};
struct que {
       qu *front, *rear;       
};
typedef struct que red;

pacijent FrontQ(red *Q){
        if ( Q->front != Q->rear) 
             return( Q->front->sljedeci->element);
        else { 
             cout << "Red je prazan\n";
             }                      
};
void EnQueueQ(pacijent x,red *Q){
     qu *novi = new qu;
     novi->element = x;
     novi->sljedeci = NULL;
     Q->rear->sljedeci = novi;
     Q->rear = novi;
};

bool IsEmptyQ(red *Q){
     if(Q->front == Q->rear) return true;
     else return false;
     }
void DeQueueQ(red *Q){
     if(IsEmptyQ(Q)){
              cout << "Red je prazan!\n";
              return;
              }
     qu *pom = Q->front;
     Q->front = (Q->front)->sljedeci;
     delete pom;
}
red *InitQ(red *Q){
    Q=new red;
    qu *novi=new qu;
    novi->sljedeci=NULL;
    Q->front=novi;
    Q->rear=novi;
    return Q;   
}
