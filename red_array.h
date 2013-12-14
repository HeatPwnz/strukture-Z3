#include<iostream>
using namespace std;
struct pacijent{
       int ai, bi, ci, di, ei;
       char ime[30], prezime[30], spol;
       int dan, mj, god;    
};
struct qu {
       pacijent element[10000];
       int front,rear;
};
typedef struct qu red;

int AddOne(int n) {
    return((n+1)%10000);
}
bool IsEmptyQ(red *Q){
     if(AddOne(Q->rear)==Q->front) return true;
     else return false;
     
     }
pacijent FrontQ(red *Q){
        if(!IsEmptyQ(Q))
             return Q->element[Q->front];
         else cout<<"Red je prazan\n";
                     
}
void EnQueueQ(pacijent X, red *Q){
     if(AddOne(AddOne(Q->rear))!=Q->front){
          Q->rear=AddOne(Q->rear);                               
          Q->element[Q->rear]=X;     
     }
     else {
           cout<<"Red je pun\n";
           return;
     }
}
void DeQueueQ(red *Q){
     if(!IsEmptyQ(Q))
         Q->front=AddOne(Q->front);
     else {
           cout<<"Red je prazan\n";
           return;
     }          
}

red *InitQ(red *Q){
    Q=new red;
    Q->front=0;
    Q->rear=9999;
    return Q;   
}
