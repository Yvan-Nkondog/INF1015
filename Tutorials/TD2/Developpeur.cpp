#include <iostream>
#include <string>
#include <utility>
#include "cppitertools/range.hpp"
#include "Jeu.hpp"
#include "ListeJeux.hpp"
#include "Developpeur.hpp"


//TODO: En faire une classe qui suit les principes OO.
Developpeur::Developpeur() : Developpeur("Non Défini") {}

Developpeur::Developpeur(std::string nom)
{
	paireNomJeux_.first = nom;
	paireNomJeux_.second.nElements = 0;
	paireNomJeux_.second.capacite = 0;
	paireNomJeux_.second.elements = nullptr;
}

//TODO: La destruction d'un Developpeur doit s'assurer que la désallocation de ListeJeux est faite.
Developpeur::~Developpeur()
{
	delete[] paireNomJeux_.second.elements;
}

//TODO: Les méthodes à faire...
std::string Developpeur::getNom() 
{
	return paireNomJeux_.first;
}

size_t Developpeur::getNombreJeuxDeveloppes(const ListeJeux& listeJeux)
{
	size_t nombreJeuxDeveloppes = 0;
	for (size_t i : iter::range(listeJeux.nElements)) {
		if (listeJeux.elements[i]->developpeur == paireNomJeux_.first) {
			nombreJeuxDeveloppes++;
		}
	}
	return nombreJeuxDeveloppes;
}

void Developpeur::mettreAjourJeuxDeveloppes(const ListeJeux& listeJeux)
{
	paireNomJeux_.second.nElements = 0;
	paireNomJeux_.second.capacite = getNombreJeuxDeveloppes(listeJeux);
	paireNomJeux_.second.elements = new Jeu * [paireNomJeux_.second.capacite];
	for (size_t i : iter::range(paireNomJeux_.second.capacite)) {
		if (listeJeux.elements[i]->developpeur == paireNomJeux_.first) {
			paireNomJeux_.second.elements[i] = listeJeux.elements[i];
			paireNomJeux_.second.nElements++;
		}
	}
}

void Developpeur::afficherTitresJeuxDeveloppes()
{
	std::cout << "Titres des jeux développés : " << std::endl;
	for (size_t i : iter::range(paireNomJeux_.second.nElements)) {
		std::cout << '\t' << paireNomJeux_.second.elements[i]->titre << std::endl;
	}
}
