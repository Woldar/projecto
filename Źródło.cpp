#include "Loch.h"
#include "Bohater.h"
#include <time.h>

#include <string>
#include <string.h>
#include <iostream>

int main()
{
	srand((unsigned)time(NULL));
	Loch Loch;
	std::cout << "Budzisz sie w ciemnym pomieszczeniu, nie wiesz jak sie tu znalazles.. nic nie pamietasz..\n" << std::endl;
	std::cout << "Probujesz przypomniec sobie kim byles i jak sie nazywasz\n" << std::endl;
	Loch.stworzbohatera();
	Loch.generujLoch();
	system("cls");
	Loch.start();
	//Loch.walka();

	return (0);
}


/* 
Niestety wykluczylem pewne pierwotne pomysly z gry
Byly czasochlonne a nie wnosily nic wartosciowego do samego kodu
Bede je rozwijal we wlasnym zakresie w trakcie wakacji

np. stosowanie mikstrur, neutralni przeciwnicy, eventy
np. mniejsza ilosc klas, przedmiotow i przeciwnikow

operatory -> w wielu funkcjach
polimorfizm -> klasy ekwipunek, pancerz i bron
stringi -> przy nazwach przedmiotow, przeciwnikow
wyjatki -> przy wyborach gracza
*/