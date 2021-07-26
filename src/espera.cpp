/*  salasofo   */
#include "sv_sem.h"
#include "sv_shm.h"
#include "Area.h"

 void imprimir_padrones() {
     cout << "---- TP 2 - Cabinas de Entretenimiento ----" << endl;
     cout << "    96722 - Bogovic,  Federico Ezequiel    " << endl;
     cout << "       98541 - Zambelli Tello, Brian       " << endl;
     cout << "        100752 - Parodi,  Joaquin          " << endl;
     cout << "-------------------------------------------" << endl;
     cout << " " << endl;
 }

int main(int argc, char * argv[]){
    if (argc != 2 || (strcmp(argv[1], "otaku") && strcmp(argv[1], "gotico"))) {
        cerr<<"Uso: "<<argv[0]<<" <otaku/gotico>"<<endl;
        exit(2);
    }
    imprimir_padrones();
    std::string tribu = std::string(argv[1]);
    int yoid=getpid();

    sv_sem *salaSem[5];
    for (int i=0;i<5;i++){
        salaSem[i]=new sv_sem(string("Silla")+to_string(i),0); 
    }

    sv_sem mutex("Mutex",1);
    Area * sala;
    sv_shm aSala("AreaSala");
    sala = static_cast <Area*>(aSala.map(sizeof(Area)));

    cout<< "Sos el "<<tribu<<" PID="<<yoid<<" y entraste en la sala de espera ...."<<endl;

    mutex.wait();
    int miSilla = sala->sentarse(tribu);

    cout<< "Esperando a mas personas.... "<<endl;
    

    if (sala->puedeArmarCabina()) {
        int * ingresantes = sala->armarCabina();
        for (int i = 0; i < 4; i++){
            salaSem[ingresantes[i]]->post();
        }        
    }
    mutex.post();
    
    
    salaSem[miSilla]->wait();
    cout<< "Ingresaste en la cabina "<<sala->getNumeroCabina()<<" del tipo "<<sala->getNombreCabina()<<", a jugar!"<<endl;


    
} 
