#ifndef TRADUCTOR_H_
#define TRADUCTOR_H_


class traductor{

	// lee el siguiente gamma. -1 para error.
	int read_gamma(LectorBit* reader);

	// escribe 1 int en gamma en el destino.
	void write_gamma(int num,Escritor_bit* writer);

	// lee el siguiente delta. -1 para error.
	int read_delta(LectorBit* reader);

	// escribe 1 int en gamma en el destino.
	void write_delta(int num,Escritor_bit* writer);

};
#endif
