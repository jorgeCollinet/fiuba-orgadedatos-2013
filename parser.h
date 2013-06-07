
#ifndef PARSERTEX_H_
#define PARSERTEX_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include "ManejadorArchivos.h"
#include <list>
using namespace std;

struct termino{

	std::string term;
	int posi;
};
class Parseador{

private:
	list<termino> milista;
	std::string nombrearchivo;


public:
	Parseador(std::string& archivoaparsear);
	~Parseador();

	bool parser();



};

#endif /* PARSERTEX_H_ */
