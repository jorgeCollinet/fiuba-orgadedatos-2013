
#include "merge.h"

using namespace std;

class Palabra {
	string nombre_archivo;
	string palabra;
	vector<const char*> datos;
	ifstream* fd;
public:
	Palabra(string nombre_archivo, ifstream* fd) {
		this->fd = fd;
		char palabra[200];
		*fd >> palabra;
		string dato;
		std::getline(*fd, dato);

		this->nombre_archivo = nombre_archivo;
		this->palabra = palabra;
		datos.push_back(dato.c_str());
		cout << "palabra:" << this->palabra << endl;
		cout << "nombre_archivo" << this->nombre_archivo << endl;
		cout << "datos" << dato[0] << endl;

	}
	/*Palabra(string nombre_archivo, char* palabra, const char* dato) {
		this->nombre_archivo = nombre_archivo;
		this->palabra = palabra;
		string aux(nombre_archivo);
		aux+=dato;
		datos.push_back(aux.c_str());
		cout << "palabra:" << this->palabra << endl;
		cout << "nombre_archivo" << this->nombre_archivo << endl;
		cout << "datos" << dato << endl;
		fd=NULL;
	}*/
	string get_pal() const {
		return palabra;
	}
	string get_arch() {
		return nombre_archivo;
	}
	vector<const char*> get_datos() {
		return datos;
	}
	ifstream* get_ifstream(){
		return this->fd;
	}
	void absorber_datos(Palabra& pal) {
		while(!pal.datos.empty()){
			this->datos.push_back(pal.datos.back());
			pal.datos.pop_back();
		}

	}
};

class cmp {
	bool al_reves;
public:
	cmp(bool al_reves) {
		this->al_reves = al_reves;
	}
	bool operator()(const Palabra& pal1, const Palabra& pal2) {
		if (al_reves) {
			return ((pal1.get_pal() >= pal2.get_pal()) > 0);
		}
		return ((pal1.get_pal() >= pal2.get_pal()) < 0);
	}
};
Merge::Merge(std::vector<std::string>& archivos_a_mergear) :
		arch_a_merg(archivos_a_mergear) {
}
bool Merge::merge_2_etapas(const char* nombre_final) {
	string dir(nombre_final);

	size_t cant_archivos = arch_a_merg.size();

	priority_queue<Palabra, vector<Palabra>, cmp> cola_pri(cmp(true));

	vector<ifstream*> archivos(cant_archivos);
	for (size_t i = 0; i < cant_archivos; ++i) {
		// abro y guardo el ifstream de cada archivo
		ifstream fd(arch_a_merg[i].c_str(), ifstream::binary);
		archivos.push_back(&fd);

		// creo una instancia de la clase palabra y le meto en el heap
		Palabra pal(arch_a_merg[i],&fd);
		cola_pri.push(pal);
	}

	while (!cola_pri.empty()) {

		Palabra palabra_sacada = cola_pri.top();
		cola_pri.pop();

		while (cola_pri.top().get_pal() == palabra_sacada.get_pal()) {
			Palabra temp2 = cola_pri.top();
			palabra_sacada.absorber_datos(temp2);
			cola_pri.pop();
			ifstream* archivo = temp2.get_ifstream();
			if(!archivo->eof()){
				Palabra nueva_pal (temp2.get_arch(),archivo);
				cola_pri.push(nueva_pal);
			}
		}

		ifstream* archivo = palabra_sacada.get_ifstream();
		if (!archivo->eof()) {
			Palabra nueva_pal(palabra_sacada.get_arch(), archivo);
			cola_pri.push(nueva_pal);
		}


	}
	return true;

}

