//
// Created by Felipe on 9/8/2025.
//

#include "TopDeck.h"



TopDeck::TopDeck(int deckNumber) {
    setChamp( getChamp(deckNumber));
    const char **cardsChamp=  getCards(deckNumber);
    const char **itemsChamp= getItems(deckNumber);
    string item1Text, item2Text;
    Card card;
    int j=0;
    for (size_t i = 0; i < MAXCARDS; i++) {
        card=Card(cardsChamp[i],itemsChamp[i]);
        TopDeck::add(card);
    }
}

TopDeck::TopDeck(ChampCard* champ,const vector<Card> &cardsV) {
    this->champ=champ;
    for (size_t i = 0; i < MAXCARDS; i++) {
        Card card=cardsV[i];
        TopDeck::add(card);
    }
}


void TopDeck::add(Card card) {
    cards.emplace(card.getItemLevel(true),card);
    if (card.has2Items()){
        card.swapItems();
        cards.emplace(card.getItemLevel(true),card);
    }
}

TopDeck::~TopDeck() = default;

const string TopDeck::getChampFile() const {
    return "../champs/v"+ patchVersion +"/" +getChamp() +  "T.txt";
}

size_t TopDeck::getSize() const {
    return cards.size();
}


bool TopDeck::hasKey(size_t key) const {
    return cards.count(key) == 1;
}
Card TopDeck::getCard(size_t level) const {
    return cards.at(level);
}
