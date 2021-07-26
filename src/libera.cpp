#include "sv_sem.h"
#include "sv_shm.h"
#include "Area.h"

void imprimir_padrones() {
    cout << 98541 << " Zambelli Tello, Brian" << endl;
    cout << 100752 << " Parodi,Joaquin" << endl;
    cout << 96722 << " Bogovic,Federico Ezequiel" << endl;
}

int main(int argc, char *argv[]) {
    imprimir_padrones();
    sv_sem *salaSem[5];

    for (int i = 0; i < 5; i++) {
        salaSem[i] = new sv_sem(string("Silla") + to_string(i), 0);
    }

    sv_sem mutex("Mutex", 1);
    Area * sala;
    sv_shm aFilo("AreaSala");
    sala = static_cast <Area*>(aFilo.map(sizeof(Area)));
}