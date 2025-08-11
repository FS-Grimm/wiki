//
// Created by Felipe on 10/8/2025.
//

#include <assert.h>

#include <catch2/catch_test_macros.hpp>

#include "../Parser/jsonParser.h"

using namespace std;
TEST_CASE("Unexistant Version File Throws Error")
    {
        JsonParser parser;
        REQUIRE_THROWS(parser.getVersionFile_impl("-1"));
    }
TEST_CASE("Existant Version File Doesn't throw Error")
{
    JsonParser parser;
    REQUIRE_NOTHROW(parser.getVersionFile_impl("../Parser/6.8.json"));
}
TEST_CASE("JsonParser parses valid JSON", "[JsonParser]") {
    JsonParser parser;
    nlohmann::json result = R"({"name": "Teemo"})";
    vector<Card>* cardsP;


    REQUIRE(result.contains("name"));
    REQUIRE(result["name"] == "Teemo");
    REQUIRE(result["role"] == "Top");
}

TEST_CASE("JsonParser throws on invalid JSON", "[JsonParser]") {
    JsonParser parser;
    std::string invalidJson = R"({"name": "Teemo", "role": Top})";

}
