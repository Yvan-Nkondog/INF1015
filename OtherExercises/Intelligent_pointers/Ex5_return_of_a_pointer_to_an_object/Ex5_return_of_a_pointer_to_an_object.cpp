#include <iostream>
#include <string>
#include <memory>
using namespace std;
struct Personne { string prenom, nom; };
void afficherPersonne(const Personne& p) { cout << p.prenom << " " << p.nom; }
std::unique_ptr<Personne> obtenirPersonne()
{
	Personne personne = { "Jane", "Doe" };
	//TODO: Retourner un pointeur de Personne pour Jane Doe (au lieu de nullptr), 
	// pour que le programme fonctionne correctement.
	return std::make_unique<Personne>(personne);
}
int main()
{
	std::unique_ptr<Personne> p = obtenirPersonne();
	afficherPersonne(*p);
}
