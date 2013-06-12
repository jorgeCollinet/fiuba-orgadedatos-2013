/*
 * test_termino.cpp
 *
 *  Created on: 12/06/2013
 *      Author: jorge
 */
#define prueba_termino
#ifndef prueba_termino
#include "termino.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){


	string termino = "pepe";
	vector<pair <size_t,vector<size_t> > > docs_y_offts;
	pair <size_t,vector<size_t> > doc;
	// numero de documento
	doc.first = 2;
	// offsets en bytes y bits del termino en ese documento (documento 2) (primero el de bytes segundo el de bits)
	// en este ejemplo hago que el temino estaba en
	//offset 4
	doc.second.push_back(4);

	//offset 68
	doc.second.push_back(68);

	// offset 878987
	doc.second.push_back(878987);


	// agrego al doc al vector de documentos que contiene el termino
	docs_y_offts.push_back(doc);


	pair <size_t,vector<size_t> > doc2;
	doc2.first = 87;

	doc2.second.push_back(6666);

	doc2.second.push_back(6699);

	doc2.second.push_back(8779);

	doc2.second.push_back(9999);

	docs_y_offts.push_back(doc2);

	// y asi para cada documento

	// creo termino
	Termino ter(termino, docs_y_offts);
	// muestro estado interno
	cout<<ter;

	cout<<endl;
	cout<<"compruebo si los docs están en este termino"<<endl;
	cout<<"tiene que decir false (0): "<<ter.tiene_doc(56565655)<<endl;
	cout<<"tiene que decir false (0): "<<ter.tiene_doc(111111)<<endl;
	cout<<"tiene que decir true (1): "<<ter.tiene_doc(87)<<endl;
	cout<<"tiene que decir true (1): "<<ter.tiene_doc(2)<<endl;


}







#endif



