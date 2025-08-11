//
// Created by Felipe on 1/8/2025.
//
 #include "Deck.h"

string Deck::patchVersion;

void Deck::setChamp( ChampCard *champ) {
	this->champ=champ;
}

void Deck::setChamp(const string &champ) {
	this->champ=new ChampCard(champ,false);
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

string Deck::getPatchDirectory() {
	return "../champs/v"+ patchVersion;
}

const string Deck::getChampFile() const {
	return champ->getLoRname();
}

size_t Deck::getSize() const {
	return 0;
}

auto Deck::add(Card card) -> void {
}

Card Deck::getCard(size_t pos) const {
	return {};
}


string Deck::getChamp() const {
	return champ->getName();
}


string Deck::getPoCChampName() const {
	return champ->getPoCName();
}


string Deck::getLoRChampName() const {
	return champ->getLoRname();
}


