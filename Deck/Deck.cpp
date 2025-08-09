//
// Created by Felipe on 1/8/2025.
//
 #include "Deck.h"


void Deck::setChamp(const string &champ) {
	this->champ=champ;
}

string Deck::getChamp(int deckNumber) {
	switch (deckNumber) {
		case 1:
			return CHAMP1;
		case 2:
			return CHAMP2;
		default:
			cout<<"Wrong deck number "<<deckNumber<<endl;
		throw;
	}
}
const char **Deck::getCards(int deckNumber) {
	switch (deckNumber) {
		case 1:
			return cardsChamp1;
		case 2:
			return cardsChamp2;
		default:
			cout<<"Wrong deck number "<<deckNumber<<endl;
		throw;
	}
}


const char **Deck::getItems(int deckNumber) {
	const char** itemsChamp;
	switch (deckNumber) {
		case 1:
			itemsChamp= itemsChamp1;
			break;
		case 2:
			itemsChamp=  itemsChamp2;
			break;
		default:
			cout<<"Wrong deck number "<<deckNumber<<endl;
		throw;
	}
	if (*itemsChamp== NULL) {
		for (int i=0; i<MAXITEMS; i++) {
			itemsChamp[i]="";
		}
	}
	return itemsChamp;
}

Deck::~Deck() = default;

const string Deck::getChampFile() const {
	return champ;
}

size_t Deck::getSize() {
	return 0;
}

void Deck::add(Card card) {
}

Card Deck::getCard(size_t pos) {
	return Card();
}


string Deck::getChamp() {
	return champ;
}
string Deck::getPoCChamp() const {
	return "{{PoC|" + champ + "}}";
}



