#include "utilitaire.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <file>\n";
		return 1;
	}

	std::string content;
	if (!util::readFileIntoString(argv[1], content)) {
		std::cerr << "Erreur: impossible d'ouvrir le fichier '" << argv[1] << "'\n";
		return 2;
	}

	std::cout << "Taille du fichier: " << content.size() << " octets\n";
	return 0;
}
