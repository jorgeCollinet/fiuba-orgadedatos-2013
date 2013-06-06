#include "traductor.h"

using namespace std;

Traductor::Traductor(const int modo,const char* arch_destino){

	this->modo= modo;

	if(modo == READ){
		reader = new LectorBit(arch_destino);
	}
	if(modo == WRITE){
		writer = new Escritor_bit(arch_destino);
	}
	if((modo !=1)&&(modo !=2)){
		throw std::ios_base::failure("Modo invalido");
	}
}


Traductor::~Traductor(){
	if(modo == READ){
		delete reader;
	}
	if(modo == WRITE){
		writer->cerrar_escritor();
		delete writer;
	}
}


int Traductor::read_gamma(){

	if(modo == WRITE){
		throw std::ios_base::failure("se abrio en modo escritura -> no se puede leer");
	}

	int unary = 0;
	int binary = 0;

	// leo la parte unaria-1, corto en el primer 0
	while (reader->leer_bit() == 1){
		unary++;
		//cout << "1";
		if(reader->eof()) return -1;
	}
	//cout << "0";

	//leo el resto
	for(int i=unary;i>0;i--){
		// decodifico la parte binaria
		if(reader->leer_bit() == 1){
			binary = binary+(int)pow((float)2, (float)(i-1));
			//cout << "1";
		} else {
			//cout << "0";
		}
		if(reader->eof()) return -1;
	}
	//cout << endl;
	return (int) (binary + pow((double)2, (double) unary));
}


bool Traductor::write_gamma(int num){

	if(modo == READ){
		throw std::ios_base::failure("Se abrio en modo lectura -> no se puede escribir");
	}
	int unary;
	int binary;
	int aux,aux2;

	// calculo los componentes
	aux = floor(log2(num));
	unary = 1 + aux;
	binary = num - (int)pow((float)2,(float)aux);

	// escribo la parte unaria
	for(int i=1;i<unary;i++){
		writer->escribir_bit_desde_arriba(1);
		//cout << "1";
	};
	writer->escribir_bit_desde_arriba(0);
	//cout << "0";
	// escribo la parte binaria
	for(int i=aux;i>0;i--){
		aux2 = (int)pow ((float)2, (float)(i-1));
		if(aux2 <= binary){
			writer->escribir_bit_desde_arriba(1);
			//cout << "1";
			binary = binary - aux2;
		}else{
			writer->escribir_bit_desde_arriba(0);
			//cout << "0";
		}
	}
	//cout << endl;
	return true;
}


int Traductor::read_delta(){

	if(modo == WRITE){
		throw std::ios_base::failure("se abrio en modo escritura -> no se puede leer");

	}

	int gamma = 0;
	int binary = 0;

	// decodifico la parte gamma
	gamma = (read_gamma() - 1);

	for(int i=gamma;i>0;i--){
		// decodifico la parte binaria
		if(reader->leer_bit()){
			binary = binary + (int)pow((float)2, (float)(i-1));
		}
		if(reader->eof()) return -1;
	}
	return((int)pow((float)2,(float)gamma)+binary);
}


bool Traductor::write_delta(int num){

	if(modo == READ){
		throw std::ios_base::failure("Se abrio en modo lectura -> no se puede escribir");

	}

	int gamma;
	int binary;
	int aux,aux2;

	// calculo los componentes
	aux = floor(log2(num));
	gamma = 1 + aux;
	binary = num - (int)pow((float)2,(float)aux);

	// escribo la parte gamma
	write_gamma(gamma);

	// escribo la parte binaria
	for(int i=aux;i>0;i--){
		aux2 = (int)pow ((float)2, (float)(i-1));
		if(aux2 <= binary){
			writer->escribir_bit_desde_arriba(1);
			//cout << "1";
			binary = binary - aux2;
		}else{
			writer->escribir_bit_desde_arriba(0);
			//cout << "0";
		}
	}
	//cout << endl;
	return true;
}


char Traductor::read_char(){

	if(modo == WRITE){
		throw std::ios_base::failure("se abrio en modo escritura -> no se puede leer");

	}

	char letra;
	int bin = 0;

	//leo el resto
	for(int i=7;i>=0;i--){
		// decodifico la parte binaria
		if(reader->eof()) return '~';
		if(reader->leer_bit() == 1){
			bin=bin+(int)pow((float)2, (float)i);
		}
	}

	letra =  static_cast<char>(bin);
	return letra;
}


bool Traductor::write_char(char letra){

	if(modo == READ){
		throw std::ios_base::failure("Se abrio en modo lectura -> no se puede escribir");

	}
	int bin = static_cast<int>(letra);
	int aux;

	// escribo la parte binaria
	for(int i=7;i>=0;i--){
		aux = (int)pow((float)2, (float)(i));
		if(aux <= bin){
			writer->escribir_bit_desde_arriba(1);
			bin = bin - aux;
		}else{
			writer->escribir_bit_desde_arriba(0);
		}
	}
	return true;
}


bool Traductor::write_string(std::string unaPalabra) {
	for (unsigned int i = 0; i < unaPalabra.length(); i++) {
		if(!this->write_char(unaPalabra[i]))
			return false;
	}
	return true;
}


const int Traductor::mode(){
	return modo;
}
