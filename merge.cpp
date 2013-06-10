#include "merge.h"

using namespace std;

class Palabra {
	string nombre_archivo;
	string palabra;
	vector<string> datos;
	ifstream* fd;
public:
	Palabra(string nombre_archivo, ifstream* fd) {
		if(!fd->is_open()){
			cout <<"archivo cerrado!!!!!"<<endl;
		}
		this->fd = fd;
		char palabra[200];
		(*fd) >> palabra;
		string temp_dato;
		std::getline(*fd, temp_dato);
		this->nombre_archivo = nombre_archivo;
		this->palabra = palabra;
		datos.push_back(temp_dato);

		//cout << "Palabra Constructor palabra:" << this->palabra << endl;
		//cout << "Palabra Constructor nombre_archivo" << this->nombre_archivo << endl;
		//cout << "Palabra Constructor datos" << datos[0] << endl;

	}
	const string& get_pal() const {
		return palabra;
	}
	const string& get_arch() const {
		return nombre_archivo;
	}
	vector<string>& get_datos() {
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

class Cmp {
public:
	bool operator()(const Palabra& pal1, const Palabra& pal2) {

		if ((pal1.get_pal() == pal2.get_pal())) {
			return (pal1.get_arch() <= pal2.get_arch());
		}
		return ((pal1.get_pal() >= pal2.get_pal()) > 0);
	}
};

void mostar_vector(vector<string>& vec) {
	for(size_t i=0;i<vec.size();++i) {
		cout << vec[i]<<":";
	}
}
bool Merge::merge_n_archivos(const char* nombre_final,std::vector<std::string>& arch_a_merg) {
	string dir(nombre_final);
	//ostream& arch_dest = cout;
	ofstream arch_dest_aux(nombre_final, ofstream::out);
	ostream& arch_dest = arch_dest_aux;
	size_t cant_archivos = arch_a_merg.size();

	priority_queue<Palabra, vector<Palabra>, Cmp> cola_pri;

	vector<ifstream*> archivos(cant_archivos);
	for (size_t i = 0; i < cant_archivos; ++i) {
		// abro y guardo el ifstream de cada archivo
		ifstream* fd = new ifstream(arch_a_merg[i].c_str(), ifstream::binary);
		if(!fd->is_open()){
			throw std::ios_base::failure("Merge: El archivo no se abre");
		}
		archivos.push_back(fd);

		// creo una instancia de la clase palabra y le meto en el heap
		Palabra pal(arch_a_merg[i],fd);
		cola_pri.push(pal);
	}

	while (!cola_pri.empty()) {
		//sleep(10);
		Palabra palabra_sacada = cola_pri.top();
		cola_pri.pop();

		while (cola_pri.top().get_pal() == palabra_sacada.get_pal()) {
			// debug cout<<"hubo palabras iguales"<<endl;
			Palabra temp2 = cola_pri.top();
			// debug cout << "antes de absorver" <<endl;
			// debug mostar_vector(palabra_sacada.get_datos());
			// debug cout << endl;
			palabra_sacada.absorber_datos(temp2);
			// debug cout << "despues de anbsober"<< endl;
			// debug mostar_vector(palabra_sacada.get_datos());
			// debug cout<< endl;
			cola_pri.pop();
			ifstream* archivo = temp2.get_ifstream();
			if(!archivo->eof()){
				Palabra nueva_pal (temp2.get_arch(),archivo);
				cola_pri.push(nueva_pal);
			}
		}
		// escribo en archivo a la palabra
		arch_dest<<"EN archivo: "<<palabra_sacada.get_pal();
		arch_dest<<"-"<<palabra_sacada.get_datos().size()<<"-";
		while(!palabra_sacada.get_datos().empty()){
			arch_dest<<palabra_sacada.get_datos().back();
			palabra_sacada.get_datos().pop_back();
			arch_dest<<":";
		}
		arch_dest.put('\n');

		// leo otra palabra del mismo de la palanra que estoy tratando
		ifstream* archivo = palabra_sacada.get_ifstream();
		if (!archivo->eof()) {
			Palabra nueva_pal(palabra_sacada.get_arch(), archivo);
			cola_pri.push(nueva_pal);
		}


	}
	arch_dest_aux.close();
	for(size_t i;i<archivos.size();++i){
		archivos[i]->close();
		delete archivos[i];
	}
	return true;

}

