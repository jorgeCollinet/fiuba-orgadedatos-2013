/*
 * termino.h
 *
 *  Created on: 12/06/2013
 *      Author: jorge
 */

#ifndef TERMINO_H_
#define TERMINO_H_
#include <string>
#include <vector>
#include <ostream>
class Termino {
	std::string termino;
	//					    nro_doc   offsets en el doc
	std::vector<std::pair <size_t ,std::vector<size_t> > > vector_docs;

public:
	Termino(std::string& termino, std::vector<std::pair <size_t ,std::vector<size_t> > > docs_y_offts);

	std::string& get_termino();

	bool tiene_doc(size_t nro_doc);

	friend std::ostream& operator<<(std::ostream& os, Termino& mod);
	// comprueba que dado otro termino, en un determinado documento, y que el
	// propio elemento se encuentra en el offset dado, este anteceda al termino recibido
	bool antecede ( Termino& termino, size_t nro_doc, size_t offset);

	size_t get_max_offset(size_t nro_doc);

	size_t get_next_offset(size_t nro_doc, size_t lugar_ant_offst);
};

std::ostream& operator<<(std::ostream& os, Termino& mod);

class ResolvedorDeConsultas {
	bool todos_tienen_el_documento(std::vector<Termino>& terminos,size_t nro_doc) {
		for(size_t i=0;i<terminos.size();++i){
			if(terminos[i].tiene_doc(nro_doc) == false){
				return false;
			}
		}
		return true;
	}

	void recursive_comprobar_precedencia(bool& exito,std::vector<Termino>& terminos, size_t nro_termino, size_t nro_doc, std::vector<size_t> estado) {
		if(exito == true){
			return;
		}
		if(nro_termino == terminos.size()-1 && terminos[nro_termino].antecede(terminos[nro_termino+1], nro_doc, estado[nro_termino])) {
			exito = true;
			return;

		}

		for(size_t i=estado[nro_termino]; i<= terminos[nro_termino].get_max_offset(nro_doc);++i) {
			std::vector<size_t> estado_aux = estado;
			estado_aux[nro_termino] = terminos[nro_termino].get_next_offset(nro_doc, estado[nro_termino]);
			recursive_comprobar_precedencia(exito, terminos, nro_termino,nro_doc,estado);
		}


	}

	bool comprobar_precedencia(std::vector<Termino>& terminos,size_t nro_doc) {
		if(terminos.size() ==0){
			throw std::ios_base::failure("ResolvedorDeConsultas.comprobar_precedencia: He loco me mandaste un vector<Termino> vacio !!! ");
		}
		std::vector<size_t> estado (terminos.size(),0);
		size_t nro_termino =0;
		bool exito = false;
		recursive_comprobar_precedencia(exito,terminos, nro_termino, nro_doc, estado);
		return exito;
	}
public:
	// los terminos tienen que estar odenados en el vector en el mismo orden que estan en la consulta
	std::vector<size_t> resolver_consulta(std::vector<Termino>& terminos, size_t cant_total_docs){
		std::vector<size_t> solucion;
		for(size_t i=0;i<cant_total_docs;++i) {
			if(todos_tienen_el_documento(terminos,i)) {
				if(comprobar_precedencia(terminos,i)) {
					solucion.push_back(i);
				}
			}
		}
		return solucion;
	}
};


#endif /* TERMINO_H_ */
