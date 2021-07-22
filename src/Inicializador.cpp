//
// Created by brian on 18/7/21.
//

#include "Inicializador.h"
#include "Impresor.h"
#include <iostream>
using namespace std;

int main (){
    imprimir_padrones();
    sv_sem sem_soga("semBoot",0);
    cout<<"Semaforos inicializados"<<endl;
    return 0;
}