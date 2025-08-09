//
// Created by Felipe on 9/8/2025.
//

#include "TopDeck.h"



TopDeck::TopDeck(int deckNumber) {
    champ= getChamp(deckNumber);
    const char **cardsChamp=  getCards(deckNumber);
    const char **itemsChamp= getItems(deckNumber);
    string item1Text, item2Text;
    Card card;
    setChamp(champ);
    int j=0;
    for (size_t i = 0; i < MAXCARDS; i++) {
        card=Card(cardsChamp[i],itemsChamp[i]);
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
    return "../champs/" +champ +  "T.txt";
}

size_t TopDeck::getSize() {
    return cards.size();
}


bool TopDeck::hasKey(size_t key) {
    return cards.count(key) == 1;
}
Card TopDeck::getCard(size_t level) {
    return cards.at(level);
}
