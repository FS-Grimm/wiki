//
// Created by Felipe on 9/8/2025.
//

#include "BottomDeck.h"

void BottomDeck::makeDeck(const string &champ, const char **cardsChamp, const char **itemsChamp) {
    string item1Text, item2Text;
    Card card;
    setChamp(champ);
    for (int i = 0; i < MAXCARDS; i++) {
        card=Card(cardsChamp[i],itemsChamp[i]);
        BottomDeck::add(card);
    }
}

BottomDeck::BottomDeck(int deckNumber) {
    makeDeck(getChamp(deckNumber),getCards(deckNumber),getItems(deckNumber));
    sortAlphabetically();
    sortByCost();
}


BottomDeck::BottomDeck() {

}

BottomDeck::BottomDeck( ChampCard* champ,const vector<Card> &cardsV) {
    this->champ=champ;
    cards=cardsV;
    sortAlphabetically();
    sortByCost();

}

const string BottomDeck::getChampFile() const {
        return "../champs/v"+ patchVersion+ "/"+ getChamp() +  "B.txt";
}


size_t BottomDeck::getSize() const {
    return cards.size();
}

Card BottomDeck::getCard(size_t pos) const {
    return cards[pos];
}

void BottomDeck::sortByCost() {
    stable_sort(cards.begin(),cards.end(),Card::cmpByCost);
}
void BottomDeck::sortAlphabetically() {
    stable_sort(cards.begin(),cards.end(),Card::cmpAlphabetically);
}

void BottomDeck::add(Card card) {
    cards.push_back(card);
}

BottomDeck::~BottomDeck() = default;
