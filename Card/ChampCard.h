//
// Created by Felipe on 11/8/2025.
//

#ifndef CHAMPCARD_H
#define CHAMPCARD_H

#include "Card.h"

#include <utility>

class ChampCard {
    string name;
    bool isANewChamp;
public:
    ChampCard()=default;
    ChampCard(string name, bool isNew) : name(std::move(name)), isANewChamp(isNew) {}
    [[nodiscard]] string getName() const {
        return name;
    }

    [[nodiscard]] bool isNew() const{return isANewChamp;}

    bool hasName() {
        return name!= "";
    };

    static string getPoCChamp(const string &champ) {
        return "{{PoC|" + champ + "}}";
    }


    [[nodiscard]] string getPoCName() const{
        return getPoCChamp(name);
    }

    static string getLoRChamp(const string &champ){
        return "{{LoR|" + champ + "}}";
    }

    [[nodiscard]] string getLoRname() const {
        return getLoRChamp(name);
    }


};



#endif //CHAMPCARD_H
