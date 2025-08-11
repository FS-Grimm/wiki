//
// Created by Felipe on 3/8/2025.
//

#include "Card.h"





int Card::getLevelFromText(const string &itemLevelText) {
    auto dic = levelMap.find(itemLevelText);
    if (dic != levelMap.end()) {
        return dic->second;
    }
    return -1;
}


void Card::setItem2Text(string & item2Text) {
    size_t posLevelText= item2Text.find(STARTLEVELTEXT);
    item2= item2Text.substr(0,posLevelText);
    item2Level= getLevelFromText(item2Text.substr(posLevelText));
}

void Card::setItemText(string & itemText) {
    if (itemText.empty()) {
        item1 = "";
        item1Level = UEN;
        return;
    }

    size_t posLevelText= itemText.find(STARTLEVELTEXT);
    this->item1 = itemText.substr(0, posLevelText);
    size_t posItem2=itemText.length();
    if (itemText[posLevelText+SIZELEVELTEXT]==*UTILITYSEPARATOR) {
        posItem2=SIZELEVELTEXT;
    }
    string itemLevelText = itemText.substr(posLevelText, posItem2);
    item1Level= getLevelFromText(itemLevelText);
    string item2Text;
    if (posItem2 == SIZELEVELTEXT){
        item2Text = itemText.substr(SIZELEVELTEXT + posLevelText +1, itemText.length());
        this->setItem2Text(item2Text);
    }
}


void Card::setCost(const string &substr) {
    if (substr==C0) {
        cost= 0;
    }else if (substr==C1) {
        cost= 1;
    }else if (substr==C2) {
        cost= 2;
    }else if (substr==C3) {
        cost= 3;
    }else if (substr==C4) {
        cost= 4;
    }else if (substr==C5) {
        cost= 5;
    }else if (substr==C6) {
        cost= 6;
    }else if (substr==C7) {
        cost= 7;
    }else if (substr==C8) {
        cost= 8;
    }else if (substr==C9) {
        cost= 9;
    }else if (substr==C10) {
        cost= 10;
    }else{
            std::cerr<<"Text is not related to a known Card cost";
            throw substr;
    }
}



Card::Card(const string &cardName, string itemText) {
    size_t pos_cost= cardName.find( *UTILITYSEPARATOR);
    name = cardName.substr(0, pos_cost);
    setCost(cardName.substr(pos_cost));
    setItemText(itemText);
}

Card::Card() =default;

Card::Card(const string &name,int cost, const std::string &item1, int item1Level, const std::string &item2,
    int item2Level, bool isNew) {
    this->name=name;
    this->cost=cost;
    if (item1Level>UEN && item1!="NAME" && item1!="") {
        this->item1=item1;
        this->item1Level=item1Level;
        if (item2Level>UEN && item2!="NAME" && item2!="") {
            this->item2=item2;
            this->item2Level=item2Level;
        }
    }
    this->cardIsNew=isNew;
}

void Card::swapItems() {
    swap(item1Level,item2Level);
    swap(item1,item2);
}

bool Card::isNew() const {
    return cardIsNew;
}

bool Card::has2Items() const {
    return item2Level > 0;
}


int Card::getItemLevel(bool first) const {
    return first ? item1Level : item2Level;
}
string Card::getItemName(bool first) const {
    return first ? item1 : item2;
}

string Card::getLoRCard() const {

    return "{{LoR|" + name + "}}";
}

string Card::getPoCItem(bool first) const {
    string itemName = getItemName(first);
    if (itemName.empty()) {
        return "";
    }
    return "{{PoC|item|"+ itemName + "}}";
}
string Card::getTopTextFromlevel() const {
   return getTopTextFromlevel(item1Level);
}

void Card::print() {
    cout<<name<< " ";
    cout<<cost<< "\n";
    cout<<item1<< " ";
    cout<<item1Level<<"\n";
    cout<<item2<< " ";
    cout<<item2Level<<"\n";

}

string Card::getTopTextFromlevel(int itemLevel) {
    switch (itemLevel) {
        case U2N:
            return TLEVELTEXT2;
        case U3N:
            return TLEVELTEXT3;
        case U4N:
            return TLEVELTEXT4;
        case U6N:
            return TLEVELTEXT6;
        case U9N:
            return TLEVELTEXT9;
        case U12N:
            return TLEVELTEXT12;
        case U15N:
            return TLEVELTEXT15;
        case U18N:
            return TLEVELTEXT18;
        case U21N:
            return TLEVELTEXT21;
        case U24N:
            return TLEVELTEXT24;
        case U27N:
            return TLEVELTEXT27;
        case UEN:
            return TLEVELTEXTE;
        default:
            std::cerr<<"Text is not related to a known Item level";
        throw itemLevel;
    }
}

string Card::getBottomTextFromlevel(bool first) const {
    string bottomText;
    switch ( first? item1Level:item2Level) {
        case U2N:
            bottomText = BLEVELTEXT2;
        break;
        case U3N:
            bottomText = BLEVELTEXT3;
        break;
        case U6N:
            bottomText = BLEVELTEXT6;
        break;
        case U9N:
            bottomText = BLEVELTEXT9;
        break;
        case U12N:
            bottomText = BLEVELTEXT12;
        break;
        case U15N:
            bottomText = BLEVELTEXT15;
        break;
        case U18N:
            bottomText = BLEVELTEXT18;
        break;
        case U21N:
            bottomText = BLEVELTEXT21;
        break;
        case U24N:
            bottomText = BLEVELTEXT24;
        break;
        case U27N:
            bottomText = BLEVELTEXT27;
        break;
        default:
            bottomText = "";
    }
    bottomText+="\n";
    return bottomText;
}



bool Card::cmpByCost(const Card &c1,const Card &c2) {
    return c1.cost <  c2.cost;
}

bool Card::cmpAlphabetically(const Card &c1,const Card &c2){
    return c1.name < c2.name;
}
bool Card::cmpByLevel(const Card &c1,const Card &c2){
    return c1.item1Level < c2.item1Level;
}



