#include "cartesian.hpp"
#include "catch.hpp"

namespace cosphy {

TEST_CASE("Cartesian constructor", "[cosphy Cartesian]") {
    Cartesian origin;
    REQUIRE(origin[0] == 0.0);
    REQUIRE(origin[1] == 0.0);
    REQUIRE(origin[2] == 0.0);
}

}  // namespace cosphy
