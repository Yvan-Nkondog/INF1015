#include <iostream>
#include <cstddef>
#include <string>
#include <cassert>
#include "cppitertools/range.hpp"
#include "Jeu.hpp"
#include "ListeJeux.hpp"
#include "Developpeur.hpp"
#include "ListeDeveloppeurs.hpp"


ListeDeveloppeurs::ListeDeveloppeurs() : capacite(0), nElements(0), elements(nullptr) {}

ListeDeveloppeurs::~ListeDeveloppeurs()
{
	delete[] elements;
}
	//TODO: On veut pouvoir ajouter et enlever un Developpeur* de la liste, 
	// avec réallocation dynamique tel que faite pour ListeJeux.
void ListeDeveloppeurs::afficher()
{
	const std::string& ligneSeparation = 
		"===============================================";
	for (size_t i = 0; i < nElements; i++) {
		elements[i]->afficherTitresJeuxDeveloppes();
	}
	std::cout << ligneSeparation << std::endl;
}

void ListeDeveloppeurs::changerTaille(size_t nouvelleCapacite)
{
	assert(nouvelleCapacite >= nElements);
	Developpeur** nouveauxElements = new Developpeur* [nouvelleCapacite];
	for (size_t i : iter::range(nElements)) {
		nouveauxElements[i] = elements[i];
	}
	delete[] elements;
	elements = nouveauxElements;
	capacite = nouvelleCapacite;
}

void ListeDeveloppeurs::ajouterDeveloppeur(Developpeur& developpeur)
{
	if (nElements = capacite) {
		changerTaille(std::max(2 * capacite, size_t(1)));
	}
}

void ListeDeveloppeurs::retirerDeveloppeur(Developpeur& developpeur)
{
	for (size_t i : iter::range(nElements)) {
		if (elements[i]->getNom() == developpeur.getNom()) {
			elements[i] = elements[nElements - 1];
			nElements--;
		}
	}
}
