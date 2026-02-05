#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "signal_math.hpp"

TEST_CASE("rms basic") {
    REQUIRE(sm::rms({}) == 0.0);
    REQUIRE(sm::rms({3.0, 4.0}) == Catch::Approx(3.5355339));
}

TEST_CASE("moving_average window=2") {
    auto out = sm::moving_average({2, 4, 6}, 2);
    REQUIRE(out.size() == 3);
    REQUIRE(out[0] == Catch::Approx(2.0));
    REQUIRE(out[1] == Catch::Approx(3.0));
    REQUIRE(out[2] == Catch::Approx(5.0));
	
}
