#ifndef Area_h
#define Area_h

enum persona {vacio, gotico, otaku};
enum tipoCabina {cabina_otaku, cabina_gotica, cabina_mixta};

class Area{	
	persona silla[5]={vacio, vacio, vacio, vacio, vacio};
	int numeroCabina=0;
	int otakus=0;
	int goticos=0;
    std::string tiposDeCabina[3]={"otaku", "gotica", "mixta"};

	persona addPersona(std::string tribu) {
		if (tribu == "otaku") {
			otakus++;
			return otaku;
		} else {
			goticos++;
			return gotico;
		}
	}

	int * armarCabinaGotica(){
		int* removidos = new int[4];
		for (int i = 0; (i < 4); i++){
			goticos--;
			removidos[i]=sacarPersona(gotico);
		}
		return removidos;
	}

	int * armarCabinaOtaku(){
		int* removidos = new int[4];
		for (int i = 0; (i < 4); i++){
			otakus--;
			removidos[i]=sacarPersona(otaku);
		}
		return removidos;
	}

	int * armarCabinaMixta(){
		int* removidos = new int[4];
		for (int i = 0; (i < 2); i++){
			otakus--;
			removidos[i]=sacarPersona(otaku);
		}
		for (int i = 2; (i < 4); i++){
			goticos--;
			removidos[i]=sacarPersona(gotico);
		}
		return removidos;
	}

	int * armarCabina(tipoCabina tipoCabina) {
		int* integrantes;
		if (tipoCabina == cabina_mixta) {
			cout<<"Armando cabina mixta"<<endl;
			integrantes = armarCabinaMixta();
		} else if ( tipoCabina == cabina_otaku) {
			cout<<"Armando cabina otaku"<<endl;
			integrantes = armarCabinaOtaku();
		} else {
			cout<<"Armando cabina gotica"<<endl;
			integrantes = armarCabinaGotica();
		}
		numeroCabina++;	
		return integrantes;
	}

	tipoCabina getTipoCabina() {
		if (otakus==4) {
			return cabina_otaku;
		}
		if (goticos==4) {
			return cabina_gotica;
		} else {
			return cabina_mixta;
		}
	}

	int sacarPersona(persona p) {
		for (int i = 0; i < 5; i++) {
			if (silla[i]==p){
				silla[i]=vacio;
				cout<<"saque al "<<p<<" en la silla "<<i<<endl;
				return i;
			}
		}
	}


public:
	Area(){};

	int getNumeroCabina(){
		return numeroCabina;
	}

	std::string getNombreCabina(){
		return tiposDeCabina[getTipoCabina()];
	}

	int sentarse(std::string tribu){
		persona p = this->addPersona(tribu);
		for (int i = 0; i < 5; i++) {
			cout<<"iterando en sentarse: "<<i<<" con valor: "<<silla[i]<<endl;
			if (silla[i]==vacio){
				silla[i]=p;
				return i;
			}
		}
		return 0;
	}

	int * armarCabina() {
		return armarCabina(getTipoCabina());
	}

	bool puedeArmarCabina(){
		return ((otakus==4) | (goticos==4) | (otakus>=2 && goticos>=2));
	}
};
#endif