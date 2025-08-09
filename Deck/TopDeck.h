//
// Created by Felipe on 9/8/2025.
//

#ifndef TOPMAKER_H
#define TOPMAKER_H

#include "Deck.h"

class TopDeck:public Deck{
    std::map<int,Card> cards;

public:
    explicit TopDeck(int deckNumber);

    [[nodiscard]] const string getChampFile() const override;
    size_t getSize() override;

    bool hasKey(size_t key);

    Card getCard(size_t level) override;

    void add(Card card) override;
    ~TopDeck() override;
};



#endif //TOPMAKER_H
