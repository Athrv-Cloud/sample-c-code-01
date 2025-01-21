#include "CppUTest/TestHarness.h"
#include "my_math_function.h"
#include "CppUTest/CommandLineTestRunner.h" 
TEST_GROUP(MyMathFunctions) {
};

TEST(MyMathFunctions, AddPositiveNumbers) {
    CHECK_EQUAL(5, add(2, 3));
    CHECK_EQUAL(10, add(5, 5));
    CHECK_EQUAL(100, add(50,50));
}

TEST(MyMathFunctions, AddNegativeNumbers) {
    CHECK_EQUAL(-5, add(-2, -3));
    CHECK_EQUAL(0, add(-5, 5));
    CHECK_EQUAL(-100, add(-50, -50));

}

TEST(MyMathFunctions, AddPositiveAndNegativeNumbers) {
    CHECK_EQUAL(2, add(5, -3));
    CHECK_EQUAL(-2, add(3, -5));
    CHECK_EQUAL(0, add(100,-100));
}

TEST(MyMathFunctions, AddZero) {
    CHECK_EQUAL(5, add(5, 0));
    CHECK_EQUAL(0, add(0, 0));
    CHECK_EQUAL(-5, add(-5, 0));
}


TEST(MyMathFunctions, SubtractPositiveNumbers) {
    CHECK_EQUAL(1, subtract(3, 2));
    CHECK_EQUAL(0, subtract(5, 5));
    CHECK_EQUAL(50, subtract(100,50));
}

TEST(MyMathFunctions, SubtractNegativeNumbers) {
    CHECK_EQUAL(-1, subtract(-2, -1));
    CHECK_EQUAL(0, subtract(-5, -5));
    CHECK_EQUAL(50, subtract(-50, -100));
}

TEST(MyMathFunctions, SubtractPositiveAndNegativeNumbers) {
    CHECK_EQUAL(8, subtract(5, -3));
    CHECK_EQUAL(-8, subtract(-5, 3));
    CHECK_EQUAL(200, subtract(100, -100));
}

TEST(MyMathFunctions, SubtractZero) {
    CHECK_EQUAL(5, subtract(5, 0));
    CHECK_EQUAL(0, subtract(0, 0));
    CHECK_EQUAL(-5, subtract(-5, 0));
}


TEST(MyMathFunctions, MultiplyPositiveNumbers) {
    CHECK_EQUAL(6, multiply(2, 3));
    CHECK_EQUAL(25, multiply(5, 5));
    CHECK_EQUAL(10000, multiply(100,100));
}

TEST(MyMathFunctions, MultiplyNegativeNumbers) {
    CHECK_EQUAL(6, multiply(-2, -3));
    CHECK_EQUAL(25, multiply(-5, -5));
    CHECK_EQUAL(10000, multiply(-100, -100));
}

TEST(MyMathFunctions, MultiplyPositiveAndNegativeNumbers) {
    CHECK_EQUAL(-15, multiply(5, -3));
    CHECK_EQUAL(-15, multiply(-5, 3));
    CHECK_EQUAL(-10000, multiply(100, -100));
}

TEST(MyMathFunctions, MultiplyZero) {
    CHECK_EQUAL(0, multiply(5, 0));
    CHECK_EQUAL(0, multiply(0, 0));
    CHECK_EQUAL(0, multiply(-5, 0));
}
int main(int argc, char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv); // Run all tests defined above
    }
