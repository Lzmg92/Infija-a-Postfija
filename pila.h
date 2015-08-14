#ifndef PILA
#define PILA

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <QApplication>

using namespace std;

struct NodoPila{
    NodoPila* siguiente;
    char val;
    int prec;

    NodoPila(char val, int prec){
        this->val = val;
        this->prec = prec;
        siguiente  = NULL;
    }
};



typedef struct Pila{
    NodoPila* inicio;
    int size;

    Pila(){
        inicio = NULL;
        size = 0;
    }

    //----------------------------------------------------------- pila vacia?

    bool vacia(){
        if (inicio==NULL){return 1;}else{return 0;}
    }

  // ------------------------------------------------------------- add

    void add(NodoPila* nod){
            if(vacia()){
                inicio = nod;
                size++;
            }  else {
                nod->siguiente = inicio;
                inicio = nod;
                size++;
            }
    }

//--------------------------------------------------------------- get
    void get(){
        if(!vacia()){

            NodoPila* temp;
            temp = inicio;
            inicio = inicio->siguiente;
            size--;

        }  else {
            cout << "La pila esta vacia" << endl;
        }
    }

 //----------------------------------------------------------- peek
        NodoPila* peek(){
            cout << "\n" << endl;
            if(!vacia()){

                return inicio;
            }  else {
                cout << "La pila esta vacia" << endl;
              //  return -1;
            }
        }


//----------------------------------------------------------- string valores
    QString valores(){
        QString a;
        NodoPila* temp;
        temp = inicio;

        while(temp){
            if(temp == inicio){
            a.append(",");
            if(temp->val == '(' || temp->val == ')'){ temp=temp->siguiente;}
            a.append(temp->val);
            a.append(",");
            temp = temp->siguiente;}
            else {
                if(temp->val == '(' || temp->val == ')'){ temp=temp->siguiente;}
                a.append(temp->val);
                a.append(",");
                temp = temp->siguiente;}
        }

        return a;
    }

//---------------------------------------------------------- clear
    void clear(){
        inicio = NULL;
    }
//-------------------------------------------------------- recorrer
          void recorrer(){
            NodoPila* temp;
            temp = inicio;

            while(temp){
                cout << "el valor es: " << temp->val << endl;
                temp = temp->siguiente;
            }  cout << "se termino" << endl;
        }
}Pila;











#endif // PILA

