#include <iostream>

int PGDC(int a, int b);
int simplifie(int c, int d);

int main(){
	int numerateur, denominateur, pgdc1, numerateurSimplifie, denominateurSimplifie;
	std::cout << "Entrer le numerateur ?" << std::endl;
	std::cin >> numerateur;
	std::cout << "Entrer le denominateur ?" << std::endl;
	std::cin >> denominateur;
	std::cout << "le PGDC est ";
	pgdc1= PGDC(numerateur, denominateur);
	std::cout << pgdc1<< std::endl;
	numerateurSimplifie =simplifie(numerateur, pgdc1);
	denominateurSimplifie=simplifie(denominateur, pgdc1);
	std::cout << "numerateur apres simplification: " << numerateurSimplifie<< std::endl;
	std::cout << "denominateurr apres simplification: " << denominateurSimplifie << std::endl;
}

// fonction qui demande à l'utilisateur de saisir le nombre de fraction à`traiter 


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

