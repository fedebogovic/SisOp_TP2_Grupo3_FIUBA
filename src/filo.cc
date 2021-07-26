/*  filosofo   */
#include "includes.h"
#include "Area.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " numero del filosofo" << endl;
        exit(2);
    }
    int yo = atoi(argv[1]);
    int yoid = getpid();
    cout << "soy el filosofo " << yo << " pid=" << yoid << endl;
    // cout <<"Izquierda "<<izq(yo)<<", derecha="<<der(yo)<<endl;
    sv_sem *filoSem[5];
    for (int i = 0; i < 5; i++) {
        filoSem[i] = new sv_sem(string("Filo") + to_string(i), 0);
    }

    sv_sem mutex("Mutex", 1);
    Area *filo;
    sv_shm aFilo("AreaFilo");
    filo = static_cast <Area *>(aFilo.map(sizeof(Area)));

    cout << "Filosofo " << yo << " pensando .... (un string para comer)" << endl;
    string rta;
    cin >> rta;

    mutex.wait();
    filo->setEst(yo, ham);
    cout << "Filosofo " << yo << " hambriento .... " << endl;

    if ((filo->getEst(der(yo)) == com) or
        (filo->getEst(izq(yo)) == com)) {
        mutex.post();
        filoSem[yo]->wait();
        mutex.wait();
    }

    filo->setEst(yo, com);
    mutex.post();

    cout << "Filosofo " << yo << "comiendo .... (un string para salir)" << endl;
    cin >> rta;

    mutex.wait();
    filo->setEst(yo, pen);
    if ((filo->getEst(der(yo)) == ham) and
        (filo->getEst(der(der((yo)))) != com)) {
        filoSem[der(yo)]->post();
    }
    if ((filo->getEst(izq(yo)) == ham) and
        (filo->getEst(izq(izq((yo)))) != com)) {
        filoSem[izq(yo)]->post();
    }
    mutex.post();
} 