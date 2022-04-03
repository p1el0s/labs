#include "graph.h"

int main() {
	Graph a;
	std::ifstream F("file.txt");
	a.filee(F);
	a.vivod();
	a.ready();
	std::cout << std::endl;
	a.show();
	return 0;
}

