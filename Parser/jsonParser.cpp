//
// Created by Felipe on 9/8/2025.
//

#include "jsonParser.h"
using namespace std;
string champ1;
string champ2;
string champ3;
string champ4;

vector<Card> cardsGlobal1;
vector<Card> cardsGlobal2;
vector<Card> cardsGlobal3;
vector<Card> cardsGlobal4;

ifstream jsonParser::getVersionFile() {
    string filePath = "../Parser/"  patchVersion  ".json";
    ifstream file(filePath);
    if (!file) {
        throw runtime_error("Could not open " + filePath);
    }
    return move(file);
}

bool jsonParser::hasInvalidName(const string &itemName) {
 return   find(invalidItemNames.begin(), invalidItemNames.end(), itemName) != invalidItemNames.end();
}

void jsonParser::setValidName( string * itemName) {
    cerr<<"The name "<<*itemName<<" is invalid, please add it's type to get a valid name"<<endl;
    if (*itemName==POROSNAXS) {
        *itemName = POROSNAXSV;
    } else if (*itemName==WANDERERBLESSING) {
        *itemName=WANDERERBLESSINGV;
    } else if (*itemName==ELIXIROFSKILLS) {
        *itemName=ELIXIROFSKILLSV;
    } else  if (*itemName==STOPWATCH){
        *itemName=STOPWATCHV;
    } else { //if (*itemName==MANAPOTION)
        *itemName=MANAPOTIONV;
    }
}

void jsonParser::parseCards(nlohmann::json j, vector<Card>* cardsP) {
    size_t i=0;
    string s="1";
    string cardname;
    string item1Name;
    int item1Level;
    string item2Name;
    int item2Level;
    int cost=10;
    nlohmann::json cardJ;
    size_t size=cardsP->size();
    while (j.contains(s) && i<MAXCARDSS) {
        item1Name="";
        item1Level=0;
        item2Name="";
        item2Level=0;
        cardJ=j[s];
        cardname=cardJ.at("name").get<string>();
        cost = cardJ.at("cost").get<int>();
        if (cardJ.contains("item1")) {
            item1Name=cardJ.at("item1").get<string>();
            if (hasInvalidName(item1Name)){
                setValidName(&item1Name);
            }
            item1Level=cardJ.at("item1Level").get<int>();
        }
        if (cardJ.contains("item2")) {
            item2Name=cardJ.at("item2").get<string>();
            if (hasInvalidName(item2Name)){
                setValidName(&item2Name);
            }

            item2Level=cardJ.at("item2Level").get<int>();
        }
        cardsP->emplace_back(cardname,cost,item1Name,item1Level,item2Name,item2Level);
        i++;
        s=to_string(i+1);
    }
}

void jsonParser::parseDefinedVersion(){
    ifstream f=getVersionFile();
    nlohmann::json json;
    f >> json;
    vector cards_p = {  &cardsGlobal1,&cardsGlobal2,&cardsGlobal3, &cardsGlobal4};
    vector champs = { &champ1, &champ2, &champ3, &champ4 };
    size_t i=0;
    string s="1";
    nlohmann::json champJ;
    while (json.contains(s) && i < champs.size()) {
        champJ=json[s];
        *champs[i]=champJ.at("name").get<string>();
        parseCards(champJ,cards_p[i]);
        i++;
        s=to_string(i+1);
    }
}

