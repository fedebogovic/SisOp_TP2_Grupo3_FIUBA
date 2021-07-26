/*  salasofo   */
#include "sv_sem.h"
#include "sv_shm.h"
#include "Area.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <otaku/gotico>" << endl;
        exit(2);
    }

    std::string tribu = std::string(argv[1]);
    int yoid = getpid();
    cout << "soy el " << tribu << " pid=" << yoid << endl;

    sv_sem *salaSem[5];
    for (int i = 0; i < 5; i++) {
        salaSem[i] = new sv_sem(string("Silla") + to_string(i), 0);
    }

    sv_sem mutex("Mutex", 1);
    Area *sala;
    sv_shm aFilo("AreaSala");
    sala = static_cast <Area *>(aFilo.map(sizeof(Area)));

    cout << "Sos el " << tribu << " PID=" << yoid << " y entraste en la sala de espera .... (un string para sentarte)"
         << endl;
    string rta;
    cin >> rta;

    mutex.wait();
    int miSilla = sala->sentarse(tribu);

    cout << "Tomaste asiento en la silla " << miSilla << ". Esperando.... " << endl;


    if (sala->puedeArmarCabina()) {
        sala->armarCabina();
        cout << "Ingresaste en la cabina " << sala->getNumeroCabina() << " del tipo " << sala->getNombreCabina()
             << ", a jugar!" << endl;
        exit(0);
    }
    mutex.post();


    salaSem[miSilla]->wait();
    cout << "Ingresaste en la cabina " << sala->getNumeroCabina() << " del tipo " << sala->getNombreCabina()
         << ", a jugar!" << endl;


}
