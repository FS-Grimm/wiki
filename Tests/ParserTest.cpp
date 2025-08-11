//
// Created by Felipe on 10/8/2025.
//

#include <assert.h>

#include <catch2/catch_test_macros.hpp>

#include "../Parser/jsonParser.h"

using namespace std;
TEST_CASE("getVersionFile throws if file does not exist", "[JsonParser]") {
    JsonParser parser("this_version_does_not_exist");

    REQUIRE_THROWS_AS(parser.getVersionFile(), std::runtime_error);
}
TEST_CASE("Unexistant Version File Throws Error", "[JsonParser]")
    {
        JsonParser parser;
        REQUIRE_THROWS(parser.getVersionFile_impl("-1"));
    }
TEST_CASE("Existant Version File Doesn't throw Error", "[JsonParser]")
{
    JsonParser parser;
    REQUIRE_NOTHROW(parser.getVersionFile_impl("../Parser/6.8.json"));
}

TEST_CASE("checkInvalidName replaces invalid names correctly and informs it") {
    JsonParser parser("dummy");

    std::stringstream cerrBuffer;
    auto ogCerrBuf = std::cerr.rdbuf(cerrBuffer.rdbuf());

    std::string name = POROSNAXS;
    JsonParser::checkInvalidName(&name);

    std::string oldName = POROSNAXS;
    std::cerr.rdbuf(ogCerrBuf);
    string errMsg=cerrBuffer.str();
    REQUIRE(errMsg==("The name "+oldName+" is invalid, please add it's type to get a valid name\n"));
    REQUIRE(name == POROSNAXSV);
}
TEST_CASE("checkInvalidName does not change valid names") {
    JsonParser parser("dummy");

    std::stringstream cerrBuffer;
    auto ogCerrBuf = std::cerr.rdbuf(cerrBuffer.rdbuf());

    std::string name = "I like trains";
    JsonParser::checkInvalidName(&name);

    std::string oldName = "I like trains";
    std::cerr.rdbuf(ogCerrBuf);
    string errMsg=cerrBuffer.str();
    REQUIRE(errMsg!=("The name "+oldName+" is invalid, please add it's type to get a valid name\n"));
    REQUIRE(name == "I like trains");
}

TEST_CASE("JsonParser parses valid JSON", "[JsonParser]") {
    JsonParser parser;
    // parser.parseCards()
    string result = R"({"name": "Teemo"})";
    /*vector<Card>* cardsP;
    REQUIRE(result.contains("name"));
    REQUIRE(result["name"] == "Teemo");
    REQUIRE(result["role"] == "Top");
*/}

    TEST_CASE("JsonParser throws on invalid JSON", "[JsonParser]") {
        JsonParser parser;
        std::string invalidJson = R"({"name": "Teemo", "role": Top})";
    }

