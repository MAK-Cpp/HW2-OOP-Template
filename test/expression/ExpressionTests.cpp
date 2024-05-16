#include <catch2/catch_test_macros.hpp>
#include <map>

#include "Add.h"
#include "Const.h"
#include "Divide.h"
#include "Exponential.h"
#include "Multiply.h"
#include "Negate.h"
#include "Subtract.h"
#include "Variable.h"

TEST_CASE("Expressions with exponential numbers", "[Expressions]") {
    SECTION("CONDITION EXAMPLE") {
        const Add expr_1(Multiply(Const(2), Variable("x")), Const(1));
        const Add expr_2 = Const(2) * Variable("x") + Const(1);
        REQUIRE(expr_1.str() == expr_2.str());
        REQUIRE(expr_1.eval({{"x", Exponential(100)}, {"y", Exponential(42)}}) == Exponential(201));
        REQUIRE(expr_2.eval({{"x", Exponential(100)}, {"y", Exponential(42)}}) == Exponential(201));
    }
    SECTION("OWN TESTS") {
        std::map<std::string, Exponential> values_1{
            {"x", Exponential(11)}, {"y", Exponential(22)}, {"z", Exponential(33)}};
        Variable x("x");
        Variable y("y");
        Variable z("z");
        REQUIRE(Const(5).eval(values_1) == Exponential(5));
        REQUIRE(x.eval(values_1) == values_1["x"]);
        REQUIRE(y.eval(values_1) == values_1["y"]);
        REQUIRE(z.eval(values_1) == values_1["z"]);
        REQUIRE((x + y + z).eval(values_1) == 66);
        REQUIRE((-(x + y + z)).eval(values_1) == -66);
        REQUIRE((x * x + Const(2) * x + Const(1)).eval(values_1) == ((x + Const(1)) * (x + Const(1))).eval(values_1));
        REQUIRE((x * x / x * y / y * z / z).eval(values_1) == x.eval(values_1));
        REQUIRE((y / x).eval(values_1) == ((z + x) / y).eval(values_1));
        REQUIRE((Const(1) / x).eval(values_1) == (Const(1) / y * Const(2)).eval(values_1));
        REQUIRE((x * x).eval(values_1) == (z * z / Const(9)).eval(values_1));
        REQUIRE(((x / y / z) / (y / z / x) / (z / x / y)).eval(values_1) == (x * x * x / (y * z)).eval(values_1));
        REQUIRE((z + z * z).eval(values_1) == ((z + Const(1)) * z).eval(values_1));
        REQUIRE((((y - Const(824)) / (z * z)) - ((Const(275) / (Const(-496) - Const(445))) * (z - z))).eval(values_1) ==
                (Exponential(-802) / Exponential(1089)));
    }
}