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
    [[nodiscard]] const string getChampFile() const override;
    size_t getSize() override;
    Card getCard(size_t pos) override;
    void sortByCost();
    void sortAlphabetically();
    void add(Card card) override;
    ~BottomDeck() override;

};



#endif //BOTTOMMAKER_H
