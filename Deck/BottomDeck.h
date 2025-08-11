//
// Created by Felipe on 9/8/2025.
//

#ifndef BOTTOMMAKER_H
#define BOTTOMMAKER_H
#include "Deck.h"
#include <vector>


class BottomDeck:public Deck{
    vector<Card> cards;
protected:

    void makeDeck(const string &champ, const char **cardsChamp, const char **itemsChamp);

public:
    explicit BottomDeck(int deckNumber);

    BottomDeck(const ChampCard & champ, const vector<Card> & cards);

    BottomDeck();

    BottomDeck(ChampCard *champ, const vector<Card> &cardsV);

    [[nodiscard]] const string getChampFile() const override;
    size_t getSize() const override;
    Card getCard(size_t pos) const override;
    void sortByCost();
    void sortAlphabetically();
    void add(Card card) override;
    ~BottomDeck() override;

};



#endif //BOTTOMMAKER_H
