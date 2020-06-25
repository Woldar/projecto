#include "Bohater.h"

#include <string>
#include <string.h>
#include <iostream>


/*Bohater::Bohater(std::string const& _nazwa, std::string const& _klasa, int _zdrowie, int _mana, std::string const& _status, int _obrazenia, int _pancerz, std::string const& _umiejetnosci)
	:nazwa(_nazwa), klasa(_klasa), status(_status), umiejetnosci(_umiejetnosci)
{
	//setNazwa(_nazwa[20]);
	//ustawZdrowie();
	//nazwa = _nazwa;
}*/
Bohater::Bohater(std::string _nazwa, int _zdrowie,int _obrazenia,int _pancerz,int _mana,std::string _statusWalki,std::string _statusTury)
	:nazwa(_nazwa), zdrowie(_zdrowie),obrazenia(_obrazenia),mana(_mana),statusWalki(_statusWalki),statusTury(_statusTury)
{

	statusWalki = "brak";
	statusTury = "brak";
	
	std::cout << "Wybierz klase postaci:     (1)Rycerz     (2)Kaplan     (3)Lotr" << std::endl;
	
	wyjatek();
		
	
	ustawZdrowie();
	ustawObrazenia();
}

Bohater::Bohater()
{

}
Bohater::~Bohater()
{

}

void Bohater::ustawZdrowie()
{
	switch (klasaBohatera[0].numer)
	{
	case (1):
		zdrowie = 120;
		pancerz = 5;
		mana = 80;
		break;
	case (2):
		zdrowie = 100;
		pancerz = 3;
		mana = 120;
	
		break;
	case (3):
		zdrowie = 80;
		mana = 100;
		pancerz = 1;
		break;
	}
}
void Bohater::ustawObrazenia()
{
	switch (klasaBohatera[0].numer)
	{
	case (1):
		obrazenia = 10;
		break;
	case (2):
		obrazenia = 9;
		break;
	case (3):
		obrazenia = 11;
		break;
	}
}

void Bohater::wprowadzNazwe()
{
	std::cout << "\a" << std::endl;
	std::cout << "Wprowadz nazwe gracza:\a" << std::endl;
	std::cin >> nazwa;
	std::cout << "\a" << std::endl;

}
void Bohater::wyjatek()
{
	int numer;
	do
	{
		

		try
		{
			std::cin >> numer;
			if (numer >= 1 && numer <= 3)
			{

			}
			else
			{
				throw std::runtime_error("");
			}

		}
		catch (const std::runtime_error & e)
		{
			std::cin.clear();
			std::cin.ignore();
			system("cls");
			std::cout << "Nie wybrano klasy.." << std::endl;
			std::cout << "\n" << std::endl;
			std::cout << "Wybierz poprawna klase postaci:     (1)Rycerz     (2)Kaplan     (3)Lotr " << std::endl;
			//std::cin >> kierunek;
		}
	} while (numer < 1 || numer > 3);
	klasaBohatera[0] = Klasy(numer);
}