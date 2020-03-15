//<<<<<<< HEAD
// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int demande();
int PGDC(int a, int b);
int simplifie(int c, int d);
void affiche(int e, int f, int g, int h);
int main()
{
	demande();
}
// Fonction qui demande a l'utilisateur de saisir le nombre de fractions a traiter
//aussi les numerateurs, denominateurs de chaque fraction
//appel les autres fonctions pour calculer le PGDC, les simplifier et les afficher (numerateurs, denominateurs)
int demande() {
	int nombre, numerateur, denominateur;
	std::cout << "Entrer le nombre de fractions a Simplifier ?" << std::endl;
	std::cin >> nombre;
	int* ptr = new int[nombre * 2];
	if (ptr == NULL) return -1;
	for (int i = 0; i < (nombre * 2); i += 2) {
		std::cout << "Entrer la valeur du numerateur de la fraction:" << (double)1 / 2 * i + 1 << std::endl;
		std::cin >> numerateur;
		ptr[i] = numerateur;
		std::cout << "Entrer la valeur du  denominateur de la fraction:" << (double)1 / 2 * i + 1 << std::endl;
		std::cin >> denominateur;
		ptr[i + 1] = denominateur;
	}
	for (int j = 0; j < (nombre * 2); j += 2) {
		PGDC(ptr[j], ptr[j + 1]);
		simplifie(ptr[j], PGDC(ptr[j], ptr[j + 1]));
		simplifie(ptr[j + 1], PGDC(ptr[j], ptr[j + 1]));
		affiche(ptr[j], ptr[j + 1], simplifie(ptr[j], PGDC(ptr[j], ptr[j + 1])), simplifie(ptr[j + 1], PGDC(ptr[j], ptr[j + 1])));
	}
	delete[] ptr;

}

// fonction qui recoit comme arguments de la fonction demande() les numerateurs, denominateurs de chaque fraction
//et les affiches selon un format
void affiche(int e, int f, int g, int h) {
	std::cout << e << "/" << f << ">>>" << g << "/" << h << std::endl;

}
//=======



int PGDC(int a, int b) {
	
	if (a == 0)
		return b;
	else if ((a % 2 == 0) && (b % 2 == 0))
		return 2 * PGDC(a / 2, b / 2);
	else if ((a % 2 != 0) && (b % 2 == 0))
		return PGDC(a, b / 2);
	else if ((a % 2 == 0) && (b % 2 != 0))
		return PGDC(a / 2, b);
	else {
		if ((a % 2 != 0) && (b % 2 != 0) && (a > b))
		return PGDC((a - b) / 2, b);
	else if ((a % 2 != 0) && (b % 2 != 0) && (a < b))
		return PGDC((b - a) / 2, a);
	}
}
int simplifie(int c, int d) {

	return (c / d);
}

//>>>>>>> origin/dev
