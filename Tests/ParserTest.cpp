//
// Created by Felipe on 10/8/2025.
//

#include <assert.h>

#include <catch2/catch_test_macros.hpp>

#include "../Parser/jsonParser.h"

using namespace std;
TEST_CASE("Unexistant Version File Throws Error")
    {
        jsonParser parser;
        REQUIRE_THROWS(parser.getVersionFile_impl("-1"));
    }
TEST_CASE("Existant Version File Doesn't throw Error")
{
    jsonParser parser;
    REQUIRE_NOTHROW(parser.getVersionFile_impl("../Parser/6.8.json"));
}
TEST_CASE("jsonParser parses valid JSON", "[jsonParser]") {
    jsonParser parser;
    nlohmann::json result = R"({"name": "Teemo"})";
    vector<Card>* cardsP;


    REQUIRE(result.contains("name"));
    REQUIRE(result["name"] == "Teemo");
    REQUIRE(result["role"] == "Top");
}

TEST_CASE("jsonParser throws on invalid JSON", "[jsonParser]") {
    jsonParser parser;
    std::string invalidJson = R"({"name": "Teemo", "role": Top})";

}
