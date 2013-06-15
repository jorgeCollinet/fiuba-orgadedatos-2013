#define test_indexer
#ifndef test_indexer

#include <iostream>
#include "indexer.h"
#include "traductor.h"
#include "front_codding.h"

using namespace std;

int main(){

	indexer idx;

	idx.indexar("merge.dat");

	// cout << "exito al indexar \n";

	Front_codding fc("index_fc.txt");
	fc.modo_lectura();

	Traductor trad(READ,"index_offsets.txt");
	int c_arch,frec;

	for(int i = 0;i<7;i++){
		// palabra
		cout << fc.leer_proxima_palabra() << " ";
		// cant de arch
		c_arch=trad.read_delta();
		cout << c_arch << " ";
		for(int j=0;j<c_arch;j++){
			// num de arch
			cout << trad.read_delta() << " ";
			// frec
			frec = trad.read_delta();
			cout << frec << " ";
			for(int k=0;k<frec;k++){
				// dist
				cout << trad.read_delta()<< " ";
			}
		}
		cout << endl;
	}

	return 0;
}
#endif
