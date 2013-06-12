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
	vector<size_t> docs;
	vector<size_t> offB;
	vector<size_t> offb;
	for(size_t i=0; i<10;++i) {
		docs.push_back(i);
		offB.push_back(i+i*2);
		offb.push_back(i%9);
	}
	Termino ter(termino, docs, offB, offb);
	cout<<ter;



}







#endif



