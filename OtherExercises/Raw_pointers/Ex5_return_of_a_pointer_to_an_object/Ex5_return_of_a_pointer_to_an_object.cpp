#include <iostream>
#include <string>
using namespace std;
struct Personne { string prenom, nom; };
void afficherPersonne(const Personne& p) { cout << p.prenom << " " << p.nom; }
Personne* obtenirPersonne()
{
	Personne personne = { "Jane", "Doe" };
	//TODO: Retourner un pointeur de Personne pour Jane Doe (au lieu de nullptr), 
	// pour que le programme fonctionne correctement.
	return new Personne(personne);
}
int main()
{
	Personne* p = obtenirPersonne();
	afficherPersonne(*p);
	delete p;
}
