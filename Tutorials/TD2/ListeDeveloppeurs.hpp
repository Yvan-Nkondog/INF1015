#pragma once
#include <cstddef>
#include "Developpeur.hpp"

class ListeDeveloppeurs
{
//TODO: En faire une classe qui suit les principes OO.
public:
	ListeDeveloppeurs();
	~ListeDeveloppeurs();
	//TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, 
	// avec réallocation dynamique tel que faite pour ListeJeux.
	void afficher();
	void changerTaille(size_t nouvelleCapacite);
	void ajouterDeveloppeur(Developpeur& developpeur);
	void retirerDeveloppeur(Developpeur& developpeur);
	
private:
	std::size_t nElements, capacite;
	Developpeur** elements;
};
