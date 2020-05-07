#include "cartesian.hpp"
#include "catch.hpp"

namespace cosphy {

TEST_CASE("Cartesian: constructor", "[cosphy Cartesian]") {
    SECTION("Default constructor") {
        Cartesian origin;
        REQUIRE(origin[0] == 0.0);
        REQUIRE(origin[1] == 0.0);
        REQUIRE(origin[2] == 0.0);
    }

    SECTION("Unit vectors") {
        REQUIRE(Cartesian::Uo[0] == 0.0);
        REQUIRE(Cartesian::Uo[1] == 0.0);
        REQUIRE(Cartesian::Uo[2] == 0.0);

        REQUIRE(Cartesian::Ux[0] == 1.0);
        REQUIRE(Cartesian::Ux[1] == 0.0);
        REQUIRE(Cartesian::Ux[2] == 0.0);

        REQUIRE(Cartesian::Uy[0] == 0.0);
        REQUIRE(Cartesian::Uy[1] == 1.0);
        REQUIRE(Cartesian::Uy[2] == 0.0);

        REQUIRE(Cartesian::Uz[0] == 0.0);
        REQUIRE(Cartesian::Uz[1] == 0.0);
        REQUIRE(Cartesian::Uz[2] == 1.0);
    }

    SECTION("Copy constructor") {
        Cartesian v(1, 2, 3);
        REQUIRE(v[0] == 1.0);
        REQUIRE(v[1] == 2.0);
        REQUIRE(v[2] == 3.0);

        Cartesian v2(v);
        REQUIRE(v2[0] == 1.0);
        REQUIRE(v2[1] == 2.0);
        REQUIRE(v2[2] == 3.0);
    }
}

TEST_CASE("Cartesian: access operators", "[cosphy, Cartesian]") {
    Cartesian v(1, 2, 3);

    SECTION("Getters") {
        REQUIRE(v.x() == 1.0);
        REQUIRE(v.y() == 2.0);
        REQUIRE(v.z() == 3.0);
    }

    SECTION("Setters") {
        v.x(0.0);
        v.y(0.0);
        v.z(0.0);

        REQUIRE(v.x() == 0.0);
        REQUIRE(v.y() == 0.0);
        REQUIRE(v.z() == 0.0);
    }
}

TEST_CASE("Cartesian: operator overloading", "[cosphy, Cartesian]") {
    SECTION("Assignment operator") {
        Cartesian v2(1, 2, 3);
        auto v1 = v2;
        REQUIRE(v1[0] == 1.0);
        REQUIRE(v1[1] == 2.0);
        REQUIRE(v1[2] == 3.0);
    }

    SECTION("logical operator") {
        Cartesian v1;
        Cartesian v2(1, 2, 3);
        REQUIRE(v1 != v2);
        v1 = v2;
        REQUIRE(v1 == v2);
    }
}

}  // namespace cosphy
