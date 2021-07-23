/*  salasofo   */
#include "sv_sem.h"
#include "sv_shm.h"
#include "Area.h"



int main(int argc, char * argv[]){
    if (argc != 2 || (strcmp(argv[1], "otaku") && strcmp(argv[1], "gotico"))) {
        cerr<<"Uso: "<<argv[0]<<" <otaku/gotico>"<<endl;
        exit(2);
    }
    
    std::string tribu = std::string(argv[1]);
    int yoid=getpid();

    sv_sem *salaSem[5];
    for (int i=0;i<5;i++){
        salaSem[i]=new sv_sem(string("Silla")+to_string(i),0); 
    }

    sv_sem mutex("Mutex",1);
    Area * sala;
    sv_shm aFilo("AreaSala");
    sala = static_cast <Area*>(aFilo.map(sizeof(Area)));

    cout<< "Sos el "<<tribu<<" PID="<<yoid<<" y entraste en la sala de espera .... (un string para sentarte)"<<endl;
    //string rta;
    //cin>>rta;

    mutex.wait();
    int miSilla = sala->sentarse(tribu);

    cout<< "Ingresaste a la sala de espera. Esperando a mas personas.... "<<endl;
    

    if (sala->puedeArmarCabina()) {
        int * ingresantes = sala->armarCabina();
        for (int i = 0; i < 4; i++){
            //cout<< "Avisando a Silla "<<i<<" que ingrese.... "<<endl;
            salaSem[ingresantes[i]]->post();
        }        
        //cout<< "Ingresaste en la cabina "<<sala->getNumeroCabina()<<", a jugar!"<<endl;
        //exit(0);
    }
    mutex.post();
    
    
    salaSem[miSilla]->wait();
    cout<< "Ingresaste en la cabina "<<sala->getNumeroCabina()<<", a jugar!"<<endl;


    
} 
