#pragma once
#include "Bohater.h"
#include "Poziom_Lochu.h"
#include <string>
#include <string.h>
#include <iostream>

class Loch 
{
public:
	Loch();
	~Loch();
	Bohater BohaterK[1];
	Przeciwnik Walczacy[1];
	Poziom_Lochu Poziom[10];
	int wybor;
	int poziomLochu=0;
	void start();
	void stworzbohatera();
	void generujLoch();
	void menuGracza();
	void menuPrzeciwnika();
	void walka();
	void grabujPrzeciwnika(int iloscP, int iloscB);
	void wyjatek();
	void zwolnijPamiec();

};
