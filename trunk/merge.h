#ifndef MERGE_H_
#define MERGE_H_
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <iostream>
#include <fstream>
class Merge {
	std::vector<std::string>& arch_a_merg;
public:
	Merge(std::vector<std::string>& archivos_a_mergear);

	bool merge_2_etapas(const char* nombre_final);
};

#endif /* MERGE_H_ */
