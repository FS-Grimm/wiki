//
// Created by Felipe on 1/8/2025.
//

#ifndef DECK_H
#define DECK_H
#include "../Card/Card.h"

using namespace std;


 class Deck {

protected:

  string champ;

  string getChamp(int deckNumber);

  const char **getCards(int deckNumber);

  const char **getItems(int deckNumber);

public:
   void setChamp(const string & champ);

  virtual ~Deck() ;


  [[nodiscard]] virtual const string getChampFile() const;
  virtual size_t getSize() const;
  virtual void add(Card card);
  virtual Card getCard(size_t pos) const;
  string getChamp() const;

  string getPoCChamp() const;
};



#endif //DECK_H
