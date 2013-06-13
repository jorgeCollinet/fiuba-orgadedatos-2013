
#define prueba_termino2
#ifndef prueba_termino2

#include "termino.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// test para una consulta de multiples terminos, aca simulo una consulta con las palabras "pepe malo"
// se cargarán 2 terminos
int main(){

	string palabra = "pepe";
	vector<pair <size_t,vector<size_t> > > docs_y_offts;
	pair <size_t,vector<size_t> > doc;
	doc.first = 2;
	doc.second.push_back(4);
	doc.second.push_back(68);
	doc.second.push_back(878987);

	docs_y_offts.push_back(doc);

	pair<size_t, vector<size_t> > doc2;
	doc2.first = 870;
	doc2.second.push_back(6666);
	doc2.second.push_back(6699);
	doc2.second.push_back(8779);
	doc2.second.push_back(9999);

	docs_y_offts.push_back(doc2);

	Termino ter(palabra, docs_y_offts);

	// genero un segundo termino
	string seg_palabra = "malo";
	vector<pair <size_t,vector<size_t> > > docs_y_offts_segundo;
	pair <size_t,vector<size_t> > doc_segundo;
	doc_segundo.first = 2;
	doc_segundo.second.push_back(40);
	doc_segundo.second.push_back(69);
	doc_segundo.second.push_back(80);
	pair <size_t,vector<size_t> > doc_2_segundo;
	doc_2_segundo.first = 870;
	doc_2_segundo.second.push_back(10000);

	docs_y_offts_segundo.push_back(doc_segundo);
	docs_y_offts_segundo.push_back(doc_2_segundo);

	Termino segundo_termino(seg_palabra ,docs_y_offts_segundo);


	// creo un tercer termino
	string tercer_palabra = "malososos";
	vector<pair <size_t,vector<size_t> > > docs_y_offts_tercero;
	pair <size_t,vector<size_t> > doc_tercero;

	doc_tercero.first = 870;
	doc_tercero.second.push_back(1);
	doc_tercero.second.push_back(10);
	doc_tercero.second.push_back(100);
	doc_tercero.second.push_back(10001);

	docs_y_offts_tercero.push_back(doc_tercero);

	Termino tercer_termino (tercer_palabra,docs_y_offts_tercero);


	//###################################################3
	vector<Termino> terminos;
	terminos.push_back(ter);
	terminos.push_back(segundo_termino);
	terminos.push_back(tercer_termino);

	ResolvedorDeConsultas rescons;
	cout << "solucion:" << endl;
	vector<size_t> sol_docs = rescons.resolver_consulta(terminos, 871);

	if (sol_docs.size() == 0) {
		cout << "no hay solucion" << endl;
	} else {
		cout << "solucion es: ";
		for (size_t i = 0; i < sol_docs.size(); i++) {
			cout << sol_docs[i] << " ";
		}
		cout << endl;
	}

	cout << "Fin test :)" << endl;


}
#endif
