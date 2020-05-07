#include "catch.hpp"
#include "sperical.hpp"

namespace cosphy {

TEST_CASE("Sperical: constructor", "[cosphy, Sperical]") {
    SECTION("Default constructor") {
        Sperical origin;
        REQUIRE(origin[0] == 0.0);
        REQUIRE(origin[1] == 0.0);
        REQUIRE(origin[2] == 0.0);
    }

    SECTION("Copy constructor") {
        Sperical v(1, 2, 3);
        auto v1(v);
        REQUIRE(v1[0] == 1.0);
        REQUIRE(v1[1] == 2.0);
        REQUIRE(v1[2] == 3.0);
    }
}

TEST_CASE("Sperical: access operators", "[cosphy, Sperical]") {
    SECTION("Getters") {
        Sperical v(1, 2, 3);
        REQUIRE(v.r() == 1.0);
        REQUIRE(v.theta() == 2.0);
        REQUIRE(v.phi() == 3.0);
    }

    SECTION("Setters") {
        Sperical v;
        v.r(1);
        v.theta(2);
        v.phi(3);
        REQUIRE(v.r() == 1.0);
        REQUIRE(v.theta() == 2.0);
        REQUIRE(v.phi() == 3.0);
    }
}

}  // namespace cosphy
