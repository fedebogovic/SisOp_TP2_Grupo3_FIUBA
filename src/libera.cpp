#include "sv_sem.h"
#include "sv_shm.h"
#include "Area.h"

int main(int argc, char * argv[]){
    sv_sem *salaSem[5];
    for (int i=0;i<5;i++){
        salaSem[i]=new sv_sem(string("Silla")+to_string(i),0); 
    }

    sv_sem mutex("Mutex",1);
    Area * sala;
    sv_shm aFilo("AreaSala");
    sala = static_cast <Area*>(aFilo.map(sizeof(Area)));
}