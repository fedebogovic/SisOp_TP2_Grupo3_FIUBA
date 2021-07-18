//
// Created by brian on 18/7/21.
//

#include "sv_sem.h"
#include "sv_shm.h"
#include "Impresor.h"

int main() {
    imprimir_padrones();
    sv_sem sem_boot("semBoot", 0);
    cout << "Semaforos inicializados" << endl;
    return 0;
}