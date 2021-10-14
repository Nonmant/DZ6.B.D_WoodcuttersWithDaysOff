#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test example, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<"2 4 3 3 25";
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() == "7\n");
}

TEST_CASE("file 015", ""){
    std::ifstream input( "../015", std::ofstream::in);
    std::stringstream output;
    parseFile(input,output);
    input.close();
    REQUIRE(output.str() == "333333333333333333\n");
}

TEST_CASE("test 1", ""){
    std::stringstream input, output;
    input<<"1 2 1 3 10";
    parseFile(input,output);
    REQUIRE(output.str() == "8\n");
}

TEST_CASE("test 2", ""){
    std::stringstream input, output;
    input<<"1 2 1 3 11";
    parseFile(input,output);
    REQUIRE(output.str() == "9\n");
}

TEST_CASE("test 3", ""){
    std::stringstream input, output;
    input<<"19 3 14 6 113";
    parseFile(input,output);
    REQUIRE(output.str() == "4\n");
}

TEST_CASE("day before both rest", ""){
    std::stringstream input, output;
    input<<"1 2 1 3 7";
    parseFile(input,output);
    REQUIRE(output.str() == "5\n");
}

TEST_CASE("day after both rest", ""){
    std::stringstream input, output;
    input<<"1 2 1 3 9";
    parseFile(input,output);
    REQUIRE(output.str() == "7\n");
}

TEST_CASE("maximum rest", ""){
    std::stringstream input, output;
    input<<"1 2 1 2 6";
    parseFile(input,output);
    REQUIRE(output.str() == "5\n");
}
