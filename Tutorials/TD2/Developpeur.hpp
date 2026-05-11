#pragma once
#include <string>
#include <utility>
#include "ListeJeux.hpp"

class Developpeur
{
public:
	//TODO: En faire une classe qui suit les principes OO.
	Developpeur();
	Developpeur(std::string nom);
	//TODO: La destruction d'un Developpeur doit s'assurer que 
	// la désallocation de ListeJeux est faite.
	~Developpeur();
	//TODO: Les méthodes à faire...
	std::string getNom();

	size_t getNombreJeuxDeveloppes(const ListeJeux& listeJeux);

	void mettreAjourJeuxDeveloppes(const ListeJeux& listeJeux);

	void afficherTitresJeuxDeveloppes();

private:
	std::pair<std::string, ListeJeux> paireNomJeux_;
};
