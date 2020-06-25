#include "Loch.h"
#include "Bohater.h"
#include <string>
#include <string.h>
#include <iostream>

Loch::Loch() 
{

}
Loch::~Loch()
{

}

void Loch::start()
{
	//poziomLochu = 0;
		do
		{
			Poziom[poziomLochu].wybierzKierunek();
			walka();
			poziomLochu++;
		} while (BohaterK[0].zdrowie > 0 && poziomLochu < 10);
}
void Loch :: generujLoch()
{
	for (int i=0;i<9;i++)
	{
		Poziom[i] = Poziom_Lochu(i, 0);
	}
	Poziom[9] = Poziom_Lochu(9);

}
void Loch::stworzbohatera()
{
	
	BohaterK[0] = Bohater("Brak nazwy", 100,10,0,100,"brak","brak");
	BohaterK[0].wprowadzNazwe();
	system("cls");

}
void Loch::menuGracza()
{
	std::cout << "\n" << std::endl;
	std::cout << "Jaki ruch chcesz wykonac?\n" << std::endl;
	if (BohaterK[0].mana >= 25)
	{
		std::cout << "1.Atakuj" << std::endl;
		std::cout << "\nUmiejetnosci klasowe:\n" << std::endl;
		switch (BohaterK[0].klasaBohatera[0].numer)
		{
		case(1):
			std::cout << "2.Gruba Skora (Dodaj '1' punkt pancerza ,a nastepnie zaatakuj)\tKoszt: 25 many\n" << std::endl;
			std::cout << "3.Blok (Zredukuj o 10 punktow nastepne otrzymane obrazenia oraz zaatakuj)\tKoszt: 25 many\n" << std::endl;
			break;
		case(2):
			std::cout << "2.Leczenie (Dodaj 10 punktow zdrowia ,a nastepnie zaatakuj)\tKoszt: 25 many\n" << std::endl;
			std::cout << "3.Poswiecenie (Zwieksz swoja obrazenia o 25% do konca walki i zaatakuj)\tKoszt: 25 many\n" << std::endl;
			break;
		case(3):
			std::cout << "2.Cios krytyczny (Zadaj podwojne obrazenia)\tKoszt: 25 many \n" << std::endl;
			std::cout << "3.Oslepienie (Zredukuj obrazenia przeciwnika o 25% i zaatakuj)\tKoszt: 25 many \n" << std::endl;
			break;
		}
		wyjatek();
		switch (wybor)
		{
		case (1):
			//BohaterK[0].atak();
			Walczacy[0].zdrowie = Walczacy[0].zdrowie - BohaterK[0].obrazenia;
			//std::endl << Poziom[poziomLochu].Walczacy[1].getZdrowie;
			break;
		case (2):
			if (BohaterK[0].klasaBohatera[0].nazwaKlasy == "Rycerz")
			{
				BohaterK[0].pancerz = BohaterK[0].pancerz + 1;
				BohaterK[0].mana = BohaterK[0].mana - 25;
			}
			if (BohaterK[0].klasaBohatera[0].nazwaKlasy == "Kaplan")
			{
				BohaterK[0].zdrowie = BohaterK[0].zdrowie + 10;
				BohaterK[0].mana = BohaterK[0].mana - 25;
			}
			if (BohaterK[0].klasaBohatera[0].nazwaKlasy == "Lotr")
			{
				Walczacy[0].zdrowie = Walczacy[0].zdrowie - BohaterK[0].obrazenia;
				BohaterK[0].mana = BohaterK[0].mana - 25;
			}

			Walczacy[0].zdrowie = Walczacy[0].zdrowie - BohaterK[0].obrazenia;
			break;

		case (3):
				if (BohaterK[0].klasaBohatera[0].nazwaKlasy == "Rycerz")
					{
						BohaterK[0].statusTury = "Blok";
						BohaterK[0].mana = BohaterK[0].mana - 25;
					}
				if (BohaterK[0].klasaBohatera[0].nazwaKlasy == "Kaplan")
					{
					BohaterK[0].statusWalki = "Poswiecenie";
					BohaterK[0].mana = BohaterK[0].mana - 25;
					BohaterK[0].obrazenia = BohaterK[0].obrazenia * 1.25;
					}
				if (BohaterK[0].klasaBohatera[0].nazwaKlasy == "Lotr")
					{
					Walczacy[0].obrazenia = Walczacy[0].obrazenia - (0.25 * Walczacy[0].obrazenia);
					BohaterK[0].mana = BohaterK[0].mana - 25;
					}
		
					Walczacy[0].zdrowie = Walczacy[0].zdrowie -BohaterK[0].obrazenia;
			
					break;
	}
	}

	else
	{
		std::cout << "1.Atakuj" << std::endl;
		wyjatek();
		switch (wybor)
		{
		case 1:
			//BohaterK[0].atak();

			Walczacy[0].zdrowie = Walczacy[0].zdrowie - BohaterK[0].obrazenia;
			//std::endl << Poziom[poziomLochu].Walczacy[1].getZdrowie;
			break;
		}
	}
}
void Loch::menuPrzeciwnika()
{
	
	if (BohaterK[0].statusTury == "Blok")
	{
		int atak = Walczacy[0].obrazenia - BohaterK[0].pancerz-10;
		if (atak < 0)
		{
			atak = 0;
		}
		BohaterK[0].zdrowie = BohaterK[0].zdrowie - atak;
	}
	else
	{
		int atak = Walczacy[0].obrazenia - BohaterK[0].pancerz;
		if (atak < 0)
		{
			atak = 0;
		}
		BohaterK[0].zdrowie = BohaterK[0].zdrowie - atak;
	}
	

	
}
void Loch::walka()
{
	if (poziomLochu < 9)
	{
		switch (Poziom[poziomLochu].los)
		{
		case (0):

			switch (Poziom[poziomLochu].kierunek)
			{
			case (1):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
				break;
			case (2):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[1];
				break;
			case (3):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[2];
				break;
			}
			break;
		case (1):

			switch (Poziom[poziomLochu].kierunek)
			{
			case (1):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
				break;
			case (2):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[2];
				break;
			case (3):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[1];
				break;
			}
			break;
		case (2):

			switch (Poziom[poziomLochu].kierunek)
			{
			case (1):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[2];
				break;
			case (2):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[1];
				break;
			case (3):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
				break;
			}
			break;
		case (3):

			switch (Poziom[poziomLochu].kierunek)
			{
			case (1):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[2];
				break;
			case (2):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
				break;
			case (3):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[1];
				break;
			}
			break;
		case (4):

			switch (Poziom[poziomLochu].kierunek)
			{
			case (1):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[1];
				break;
			case (2):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
				break;
			case (3):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[2];
				break;
			}
			break;
		case (5):

			switch (Poziom[poziomLochu].kierunek)
			{
			case (1):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[1];
				break;
			case (2):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[2];
				break;
			case (3):
				Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
				break;
			}
			break;
		}
	}
	else
	{
		Walczacy[0] = Poziom[poziomLochu].Przeciwnicy[0];
	}
	system("cls");
	std::cout << "\n"<<Walczacy[0].nazwa<<" zwlowieszczo na Ciebie spoglada, gotuj sie do walki..\n" << std::endl;
	do
	{
		std::cout << "Statystyki przeciwnika: " << std::endl;
		std::cout << "Zdrowie: " << Walczacy[0].zdrowie << std::endl;
	
	
		std::cout << "Obrazenia: " << Walczacy[0].obrazenia << "\n" << std::endl;
		std::cout << "\nTwoje " << BohaterK[0].zdrowie << " punkty zdrowia" << std::endl;
		std::cout << "Twoje obrazenia:" << BohaterK[0].obrazenia << std::endl;
		std::cout << "Twoj pancerz:" << BohaterK[0].pancerz << std::endl;
		std::cout << "Twoja mana:" << BohaterK[0].mana << "\n" << std::endl;
		menuGracza();
		if (Walczacy[0].zdrowie > 0)
		{
			menuPrzeciwnika();
		}
		system("cls");
		if (Walczacy[0].zdrowie <= 0)
		{
			std::cout << "\nPrzeciwnik umiera od Twoich ciosow\n" << std::endl;
		}
		BohaterK[0].statusTury = "brak";

	} while (Walczacy[0].zdrowie > 0 && BohaterK[0].zdrowie > 0);

	if (BohaterK[0].statusWalki == "Poswiecenie")
	{
		BohaterK[0].statusWalki = "brak";
		BohaterK[0].ustawObrazenia();
		for (int i=0; i < BohaterK[0].iloscBroni; i++)
		{
			BohaterK[0].obrazenia = BohaterK[0].obrazenia + BohaterK[0].bronieBohatera[i].obrazenia;
		}
	}

	if (BohaterK[0].zdrowie > 0)
	{
	
		BohaterK[0].mana = BohaterK[0].mana + 50;
		grabujPrzeciwnika(BohaterK[0].iloscPancerzow, BohaterK[0].iloscBroni);
		//ubierzEkwipunek();
	}
	if (BohaterK[0].zdrowie <= 0)
	{
		std::cout << "Wykrwawiasz sie na smierc" << std::endl;
	}

}
void Loch::grabujPrzeciwnika(int iloscP,int iloscB)
{
	if (poziomLochu < 9)
	{
		if (Walczacy[0].ZwlokiB[0].nazwa != "Brak")
		{
			BohaterK[0].bronieBohatera[iloscB] = Walczacy[0].ZwlokiB[0];
			BohaterK[0].obrazenia = BohaterK[0].obrazenia + BohaterK[0].bronieBohatera[BohaterK[0].iloscBroni].obrazenia;
			BohaterK[0].iloscBroni = BohaterK[0].iloscBroni + 1;
			std::cout << "Przy zabitym potworze znajdujesz " << BohaterK[0].bronieBohatera[iloscB].nazwa;
			std::cout << "\t+" << BohaterK[0].bronieBohatera[iloscB].obrazenia << " obrazen\n" << std::endl;

		}
		if (Walczacy[0].ZwlokiP[0].nazwa != "Brak")
		{
			BohaterK[0].pancerzBohatera[iloscP] = Walczacy[0].ZwlokiP[0];
			BohaterK[0].pancerz = BohaterK[0].pancerz + BohaterK[0].pancerzBohatera[BohaterK[0].iloscPancerzow].pancerz;
			BohaterK[0].iloscPancerzow = BohaterK[0].iloscPancerzow + 1;
			std::cout << "Przy zabitym potworze znajdujesz " << BohaterK[0].pancerzBohatera[iloscP].nazwa;
			std::cout << "\t+" << BohaterK[0].pancerzBohatera[iloscP].pancerz << " pancerzu\n" << std::endl;

		}
		std::cout << "\n" << std::endl;
		std::cout << "Kontynujesz swoja przygode i znajdujesz skalniak przypominajacy schody, ktorym wchodzisz na wyzszy poziom" << std::endl;
	}
	else
	{
		std::cout << "Wycienczony spogladasz ponad nieruchome zwloki i widzisz swiatelko w tunelu" << std::endl;
		std::cout << "Moze to juz koniec tego koszmaru.." << std::endl;
		std::cout << "\n" << std::endl;
	}
}
void Loch::wyjatek()
{
	do
	{


		try
		{
			std::cin >> wybor;
			if (wybor >= 1 && wybor <= 3)
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
			//system("cls");
			std::cout << "Nie wybrano prawidlowego ruchu.." << std::endl;
			std::cout << "\n" << std::endl;
		}
	} while (wybor < 1 || wybor > 3);
}
void Loch::zwolnijPamiec()
{


}