/*
 * merge2.h
 *
 *  Created on: 10/06/2013
 *      Author: jorge
 */

#ifndef MERGE2_H_
#define MERGE2_H_
#include<vector>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
using namespace std;
#define PRIMERA_PASADA 0
#define SEGUNDA_PASADA 1

class Palabra {
	size_t nombre_arch;
	std::string datos;
	std::string pal;
	size_t frec;
public:
	Palabra (std::string& pal, size_t nombre_arch, std::string& datos) {
		this->pal = pal;
		this->nombre_arch = nombre_arch;
		this->datos = datos;
		frec = 1;
		// debug cout<<"nueva pal: "<<this->pal<<" "<<this->nombre_arch<<" "<<this->datos<<endl;
	}
	const string& get_pal () const{
		return pal;
	}
	size_t get_frec() const {
		return frec;
	}
	void set_frec(size_t frec){
		this->frec=frec;
	}
	const string& get_dato() const {
		return datos;
	}
	void absorver_pal(Palabra& pal){
		this->datos += pal.datos;
		frec++;
	}
};
class Cmp {
public:
	bool operator()(const Palabra& pal1, const Palabra& pal2) {

		if ((pal1.get_pal() <= pal2.get_pal())) {
		}
		return ((pal1.get_pal() >= pal2.get_pal()) > 0);
	}
};

class Merge {
public:
	void merge_2_etapas(std::vector<std::string>& archivos, std::string& nombre_final){
		size_t raiz = sqrt(archivos.size());
		std::vector<std::string> archivos_2da_etapa;
		int i=0;
		while(!archivos.empty()){
			vector<std::string> sub_vector;
			for(size_t j = 0; j<raiz;++j){
				sub_vector.push_back(archivos.back());
				archivos.pop_back();
				if(archivos.empty()){
					break;
				}
			}
			string nombre_temp = nombre_final;
			string numero;
			std::stringstream aux;
			aux<<i;
			++i;
			aux>>numero;
			nombre_temp+=numero;
			cout<<nombre_temp<<endl;
			merge_n_archivos(sub_vector,nombre_temp,PRIMERA_PASADA);
			archivos_2da_etapa.push_back(nombre_temp);
		}
		merge_n_archivos(archivos_2da_etapa,nombre_final, SEGUNDA_PASADA);
	}
	void merge_n_archivos(std::vector<std::string>& archivos, std::string& nombre_final,size_t pasada) {
		priority_queue <Palabra, vector<Palabra>, Cmp> cola_pri;
		for(size_t i =0;i<archivos.size();++i) {
			ifstream in (archivos[i].c_str());
			if(!in.is_open()) {
				throw ios_base::failure("archivo no existe");
			}
			string termino;
			string dato;
			size_t frec_aux;
			size_t nro_archivo;
			int frec;;
			while( in>>termino && !in.eof()){

				in>>nro_archivo;
				if(pasada == SEGUNDA_PASADA){
					in>>frec_aux;
					stringstream aux;
					aux<<frec_aux;
					aux>>frec;
					cout<<"frec "<<frec;
				}
				in.get();
				getline(in,dato);
				Palabra pal (termino,nro_archivo,dato);

				cout<<"termino: "<<termino<<endl;
				cout<<"nro archivo: "<<nro_archivo<<endl;
				cout<<"dato: "<<dato<<endl;

				if(pasada==SEGUNDA_PASADA){
					pal.set_frec(frec);
				}
				cola_pri.push(pal);
			}
		}
		ofstream out (nombre_final.c_str());
		if(!out.is_open()){
			throw ios_base::failure("archivo no se abrio");
		}
		while(!cola_pri.empty()) {
			Palabra pal1 = cola_pri.top();
			cola_pri.pop();
			while(!cola_pri.empty() && pal1.get_pal() == cola_pri.top().get_pal()){
				// debug cout<<"hubo empate"<<endl;
				Palabra pal2 = cola_pri.top();
				pal1.absorver_pal(pal2);
				cola_pri.pop();
			}
			// debug cout<<pal1.get_pal()<<" "<<pal1.get_frec()<<" "<<pal1.get_dato()<<endl;
			out<<pal1.get_pal();
			out<<" ";
			out<<pal1.get_frec();
			out<<" ";
			out<<pal1.get_dato();
			out<<endl;
		}
		out.close();
	}
};



#endif /* MERGE2_H_ */
