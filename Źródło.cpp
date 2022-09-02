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
