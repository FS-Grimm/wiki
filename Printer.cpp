//
// Created by Felipe on 10/8/2025.
//

#include "Printer.h"


void Printer::printPatch(const string &champ, const vector<Card> &cards) {
    fprintf(patchFile, "* ");
    fprintf (patchFile, Deck::getLoRChamp(champ).c_str());
    fprintf (patchFile, "\n");
    for (auto card:cards) {
        fprintf(patchFile, "* ");
        fprintf (patchFile,card.getLoRCard().c_str());
        fprintf (patchFile, "\n");
    }
    fprintf (patchFile, "\n");
}



Printer::Printer(TopTableManager tManager, BottomTableManager bManager, JsonParser jParser, string patchVersion) {
    this->tManager = tManager;
    this->bManager = bManager;
    this->jParser = jParser;
    this->patchVersion = patchVersion;
}

void Printer::parseVersionAndSetDirectory() {

    jParser.parse();
    string vFile="../champs/v" + patchVersion + "/" + patchVersion + ".txt";
    FILE* f=fopen(vFile.c_str(),"r");
    if (!f) {
        std::filesystem::create_directories("../champs/v" + patchVersion);
    }
    fclose(f);
}

void Printer::printTables() {
    vector champs = { &champ1, &champ2, &champ3, &champ4 };
    vector  cardsGlobal ={ &cardsGlobal1,& cardsGlobal2,& cardsGlobal3, &cardsGlobal4};
    size_t i=0;

    string vFile="../champs/v" + patchVersion + "/"+ patchVersion+ ".txt";
     patchFile=fopen(vFile.c_str(),"w");



    while (!champs[i]->empty() && i<champs.size()) {
        auto bDeck=BottomDeck(*champs[i],*cardsGlobal[i]);
        auto tDeck=TopDeck(*champs[i],*cardsGlobal[i]);
        bManager.makeTable(bDeck);
        tManager.makeTable(tDeck);
        printPatch(*champs[i],*cardsGlobal[i]);
        i++;
    }

    fclose(patchFile);

}

