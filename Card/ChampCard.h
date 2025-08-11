//
// Created by Felipe on 11/8/2025.
//

#ifndef CHAMPCARD_H
#define CHAMPCARD_H

#include "Card.h"

#include <utility>

const string NEWTOLOR="newLoR";
const string CONSTELLATION="const";
const string NEWCHAMP="newChamp";


class ChampCard {
    string name;
    string paidRelic;
    string type;
public:
    ChampCard()=default;
    ChampCard(string name, string type, string relic) : name(std::move(name)), type(std::move(type)) , paidRelic(relic){}
    [[nodiscard]] string getName() const {
        return name;
    }
    [[nodiscard]] string getPoCRelic() const {
        return "{{PoC|relic|"+ paidRelic + "}}";
    }

    [[nodiscard]] bool isNewToLoR() const{return type==NEWTOLOR;}
    [[nodiscard]] bool isNewToPoC() const{return type!=CONSTELLATION;}

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
