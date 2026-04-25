#define CATCH_CONFIG_MAIN // This tells Catch to provide a main()
#include "catch2/catch.hpp"
#include "min_merge_cost.hpp"
#include "sort_sqn.hpp"

// Prob 1: min_merge_cost
TEST_CASE("min_merge_cost correctly calculates minimum cost", "[min_merge_cost]") {
    SECTION("Example case from assignment") {
        std::vector<int> files = {10, 20, 30};
        REQUIRE(min_merge_cost(files) == 90);
    }

    SECTION ("Larger randomized inputs")  
    {
        std::vector<int> files = {4, 3, 2, 6};
        REQUIRE(min_merge_cost(files) == 29 );
    }

    SECTION("Edge Cases: Empty and single file vectors") {
        std::vector<int> empty_files= {} ; 
        REQUIRE(min_merge_cost(empty_files)  == 0);

        std::vector<int> single_file = {100 };
        REQUIRE(min_merge_cost(single_file) == 0);
    }
}
// problen 2: top_sqrtN_sorted
TEST_CASE("top_sqrtN_sorted returns top ceil(sqrt(N)) elements", "[top_sqrtN_sorted]") {
    SECTION("Example case from assignment") {
        std::vector<int> v = {3, -1, 7,-5, 2, 9, -2 , 8, 0};
        std::vector<int> expected = {9,  8, 7};
        REQUIRE(top_sqrtN_sorted(v) == expected);
    }

    SECTION("Case with duplicates") {

         std::vector<int> v  = {5, 5, 5, 1, 2, 9, 9, 9, 0 };
        
        std::vector<int> expected = {9, 9, 9};
        REQUIRE(top_sqrtN_sorted(v) == expected);
    }

    SECTION("Case with non-perfect square N") 
    {
        std::vector<int> v = {10, 20, 30, 40, 50}; 
       std::vector<int> expected =  {50, 40, 30} ;
       REQUIRE(top_sqrtN_sorted(v) == expected);
     }

    SECTION("Edge Cases: Empty vector") {
          std::vector<int> empty_v = {};
         std::vector<int> expected = { };
         REQUIRE(top_sqrtN_sorted(empty_v) == expected);
}
}