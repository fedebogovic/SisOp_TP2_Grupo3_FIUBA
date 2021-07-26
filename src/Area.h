#ifndef Area_h
#define Area_h

enum persona {vacio=0, gotico=1, otaku=2};
enum tipoCabina {cabina_otaku=0, cabina_gotica=1, cabina_mixta=2};

class Area{	
	persona silla[5]={vacio, vacio, vacio, vacio, vacio};
	int numeroCabina=0;
	int otakus=0;
	int goticos=0;
	tipoCabina tipoDeCabina = cabina_mixta;

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
		tipoDeCabina = tipoCabina;
		if (tipoCabina == cabina_mixta) {
			integrantes = armarCabinaMixta();
		} else if ( tipoCabina == cabina_otaku) {
			integrantes = armarCabinaOtaku();
		} else {
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
            if (silla[i] == p) {
                silla[i] = vacio;
                return i;
            }
        }
        return -1;
    }

public:
	Area(){};

	int getNumeroCabina(){
		return numeroCabina;
	}

	std::string getNombreCabina(){
		if (tipoDeCabina == cabina_otaku) {
			return "otaku";
		} else if (tipoDeCabina == cabina_gotica) {
			return "gotica";
		} else {
			return "mixta";
		}
	}

	int sentarse(std::string tribu){
		persona p = this->addPersona(tribu);
		for (int i = 0; i < 5; i++) {
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