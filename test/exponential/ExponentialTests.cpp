#include <catch2/catch_test_macros.hpp>

#include "Exponential.h"

TEST_CASE("Exponent numbers are equal to double", "[Exponential]") {
    REQUIRE(Exponential() == 0);
    REQUIRE(Exponential().str() == "0");
    REQUIRE(Exponential(12345) == 12345);
    REQUIRE(Exponential(12345).str() == "12345");
    REQUIRE(Exponential(5, -3) == 0.005);
    REQUIRE(Exponential(5, -3).str() == "5e-3");
    REQUIRE(Exponential(0, 10) == 0);
    REQUIRE(Exponential(0, 10).str() == "0");
    REQUIRE(Exponential(-100, 0) == -100);
    REQUIRE(Exponential(-100, 0).str() == "-1e2");
    REQUIRE(Exponential(-10200, -2) == -102);
    REQUIRE(Exponential(-10200, -2).str() == "-102");
}

TEST_CASE("Operations with exponent numbers", "[Exponential]") {
    Exponential a(12345, -3), b(-100, 2), c(123450, -4), d(15);
    SECTION("EQUALITY") {
        REQUIRE(a != b);
        REQUIRE(a == c);
        REQUIRE(b != c);
    }
    SECTION("UNARY MINUS") {
        REQUIRE(-a == -12.345);
        REQUIRE(-a != 12.345);
        REQUIRE(a == -(-a));
        REQUIRE((-a).str() == "-12345e-3");
        REQUIRE(-b == 10000);
        REQUIRE((-b).str() == "1e4");
    }
    SECTION("ADD") {
        REQUIRE(a + c == 24.69);
        a += c;
        REQUIRE(a == 24.69);
        REQUIRE(a == a + Exponential());
        REQUIRE(a + (-a) == 0);
        REQUIRE(-(a + (-a)) == 0);
        REQUIRE(a + d == c + c + d);
    }
    SECTION("SUBTRACT") {
        REQUIRE(a - c == 0);
        REQUIRE(c - a == 0);
        REQUIRE(a + b - b == a);
        REQUIRE(-a - (-a) == 0);
        REQUIRE((a + b + c) - (c + b + a) == 0);
        a -= c;
        REQUIRE(a == Exponential());
        REQUIRE(b + a == b - a);
    }
    SECTION("MULTIPLY") {
        REQUIRE(c * c == a * a);
        REQUIRE(d * d == 225);
        REQUIRE(b * (a - c) == c - a);
        REQUIRE(Exponential(1, 20) * Exponential(1, -20) == 1);
        REQUIRE(c * a == a * c);
    }
    SECTION("DIVIDE") {
        REQUIRE(a / c == c / a);
        CHECK_THROWS_AS(a / (a - c), std::invalid_argument);
        REQUIRE((a - c) / a == a - c);
        REQUIRE(a / 1 == a);
    }
}