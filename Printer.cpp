//
// Created by Felipe on 10/8/2025.
//

#include "Printer.h"


void Printer::openPatchFile() {
    string vFile="../champs/v" + patchVersion + "/"+ patchVersion+ ".txt";
    if (patchFile)
        return;
    patchFile=fopen(vFile.c_str(),"w");
}
void Printer::printNewCards(size_t i) {
    ChampCard *champ=champsGlobal[i];
    vector cards=*cardsGlobal[i];
    fprintf(patchFile, "* ");
    fprintf (patchFile, champ->getLoRname().c_str());
    fprintf (patchFile, "\n");
    for (auto card:cards) {
        if (!card.isNew())
            continue;
        fprintf(patchFile, "* ");
        fprintf (patchFile,card.getLoRCard().c_str());
        fprintf (patchFile, "\n");
    }
    fprintf (patchFile, "\n");
}
void Printer::printNewChamp() {
}

void Printer::printConsts() {
    size_t i=0;
    while (champsGlobal[i]->hasName() && i<champsGlobal.size()) {
        if (!champsGlobal[i]->isNewToPoC()) {
            ChampCard *champ=champsGlobal[i];
            fprintf(patchFile, "* ");
            fprintf (patchFile, champ->getPoCName().c_str());
            fprintf (patchFile, "\n");
            for (int j=0; j<MAXCONST-3; j++) {
                fprintf(patchFile, "** {{PoC|power|}}\n");
            }
        }
    }
}

void Printer::printChamps() {
    size_t i=0;
    size_t newConsts=0;

    if (newChamps>0) {
        fprintf(patchFile, "=== New PoC Exclusive Cards ===\n");
    }
    while (champsGlobal[i]->hasName() && i<champsGlobal.size()) {
        if (champsGlobal[i]->isNewToLoR()) {
            printNewCards(i);
        }
        if (champsGlobal[i]->isNewToPoC()) {
            newConsts++;
        }
        i++;
    }
    if (newConsts>1) {
        fprintf(patchFile, "=== New Champions ===\n");
    } else if (newConsts==1) {
        fprintf(patchFile, "=== New Champion ===\n");
    }
    i=0;
    while (champsGlobal[i]->hasName() && i<champsGlobal.size()) {
        if (champsGlobal[i]->isNewToPoC()) {
            ChampCard *champ=champsGlobal[i];
            fprintf(patchFile, "* ");
            fprintf (patchFile, champ->getPoCName().c_str());
            fprintf (patchFile, "\n");
            for (int j=0; j<MAXCONST; j++) {
                fprintf(patchFile, "** {{PoC|power|}}\n");
            }
        }
        i++;
    }
    if (newConsts-i>0) {
        if (newConsts-i>1) {
            fprintf(patchFile, "=== New Constellations ===\n");
        }else {
            fprintf(patchFile, "=== New Constellation ===\n");
        }
        printConsts();
    }

}

void Printer::printRelic() {
    size_t i=0;
    fprintf(patchFile, "=== New Relics ===\n* Bundle-Exclusive\n");
    while (champsGlobal[i]->hasName() && i<champsGlobal.size()) {
        fprintf(patchFile, "** ");
        fprintf(patchFile, champsGlobal[i]->getPoCRelic().c_str());
        fprintf(patchFile, "\n");
        i++;
    }
}


Printer::Printer(TopTableManager tManager, BottomTableManager bManager, JsonParser jParser, string patchVersion): patchFile(
    nullptr) {
    this->tManager = tManager;
    this->bManager = bManager;
    this->jParser = jParser;
    this->patchVersion = patchVersion;
    newChamps=0;
}

void Printer::parseVersionAndSetDirectory() {
    jParser.parse();
    string vFile="../champs/v" + patchVersion + "/" + patchVersion + ".txt";
    if (!std::filesystem::exists(vFile)) {
        std::filesystem::create_directories("../champs/v" + patchVersion);
    }
}


void Printer::printShop() {
    size_t i=0;
    fprintf(patchFile, "\n\n == Shop ==\n=== Bundles ===\n*New Champion Bundles");
    while (champsGlobal[i]->hasName() && i<champsGlobal.size()) {
        fprintf(patchFile, "** ");
        fprintf(patchFile, champsGlobal[i]->getPoCName().c_str());
        fprintf(patchFile, " with ");
        fprintf(patchFile, champsGlobal[i]->getPoCRelic().c_str());
        fprintf(patchFile, "\n");
        i++;
    }
}


void Printer::printPatch() {
    openPatchFile();
    printChamps();
    printRelic();
    printShop();
    fclose(patchFile);
}

void Printer::printTables() {
    champsGlobal = { &champ1, &champ2, &champ3, &champ4 };
    cardsGlobal ={ &cardsGlobal1,& cardsGlobal2,& cardsGlobal3, &cardsGlobal4};
    size_t i=0;

    while (champsGlobal[i]->hasName() && i<champsGlobal.size()) {
        auto bDeck=BottomDeck(champsGlobal[i],*cardsGlobal[i]);
        auto tDeck=TopDeck(champsGlobal[i],*cardsGlobal[i]);
        bManager.makeTable(bDeck);
        tManager.makeTable(tDeck);
        if (champsGlobal[i]->isNewToLoR()) {
            newChamps++;
        }
        i++;
    }
    printPatch();


}

