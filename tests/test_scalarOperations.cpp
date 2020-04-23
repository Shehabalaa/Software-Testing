/*
this file should cover the following functions in hmm.h
- float HMM_SinF(float Angle)
- float HMM_TanF(float Angle)
- float HMM_CosF(float Angle)
- float HMM_ExpF(float Float)
- float HMM_LogF(float Float)
- float HMM_ToRadians(float Degrees)
- float HMM_SquareRootF(float Float)
- float HMM_RSquareRootF(float Float)
- float HMM_Power(float Base, int Exponent)
- float HMM_PowerF(float Base, float Exponent)
- float HMM_Lerp(float A, float Time, float B)
- float HMM_Clamp(float Min, float Value, float Max)
*/
#define BOOST_TEST_MAIN 
#pragma once
#include <boost/test/unit_test.hpp>
#include "test_helpers.hpp"

BOOST_AUTO_TEST_SUITE(HMM_Scalar)

BOOST_AUTO_TEST_CASE(SIN, TOLERANCE) {
    BOOST_TEST(HMM_SINF(0) == sinf(0));
    BOOST_TEST(HMM_SINF(10) == sinf(10));
    BOOST_TEST(HMM_SINF(-10) == sinf(-10));
    BOOST_TEST(HMM_SINF(100) == sinf(100));
    BOOST_TEST(HMM_SINF(+0.005) == sinf(+0.005));
}

BOOST_AUTO_TEST_CASE(COS,TOLERANCE) {
    BOOST_TEST(HMM_COSF(0) == cosf(0));
    BOOST_TEST(HMM_COSF(10) == cosf(10));
    BOOST_TEST(HMM_COSF(-10) == cosf(-10));
    BOOST_TEST(HMM_COSF(100) == cosf(100));
    BOOST_TEST(HMM_COSF(+0.005) == cosf(+0.005));
}

BOOST_AUTO_TEST_CASE(TAN,TOLERANCE) {
    BOOST_TEST(HMM_TANF(0) == tanf(0));
    BOOST_TEST(HMM_TANF(10) == tanf(10));
    BOOST_TEST(HMM_TANF(-10) == tanf(-10));
    BOOST_TEST(HMM_TANF(90) == tanf(90));
    BOOST_TEST(HMM_TANF(HMM_PI32) == tanf(HMM_PI32));
    BOOST_TEST(HMM_TANF(+0.005) == tanf(+0.005));
}

BOOST_AUTO_TEST_CASE(EXP,TOLERANCE) {
    BOOST_TEST(HMM_EXPF(0) == expf(0));
    BOOST_TEST(HMM_EXPF(10) == expf(10));
    BOOST_TEST(HMM_EXPF(-10) == expf(-10));
    BOOST_TEST(HMM_EXPF(90) == expf(90));
    BOOST_TEST(HMM_EXPF(+0.005) == expf(+0.005));
}

BOOST_AUTO_TEST_CASE(LOGF,TOLERANCE) {
    BOOST_TEST(HMM_LOGF(0) == logf(0));
    BOOST_TEST(HMM_LOGF(1) == logf(1));
    BOOST_TEST(HMM_LOGF(10) == logf(10));
    // BOOST_TEST(HMM_LOGF(-10) == logf(-10)); // -nan can't asserted with -nan
    BOOST_TEST(HMM_LOGF(90) == logf(90));
    BOOST_TEST(HMM_LOGF(+0.005) == logf(+0.005));
}

BOOST_AUTO_TEST_CASE(ToRadians,TOLERANCE) {
    BOOST_TEST(HMM_ToRadians(0) == 0);
    BOOST_TEST(HMM_ToRadians(90) == HMM_PI32 / 2);
    BOOST_TEST(HMM_ToRadians(45) == HMM_PI32 / 4);
    BOOST_TEST(HMM_ToRadians(405) == 9 * HMM_PI32 / 4);
    BOOST_TEST(HMM_ToRadians(-30) == -1 * HMM_PI32 / 6);
    BOOST_TEST(HMM_ToRadians(-90) == -1 * HMM_PI32 / 2);
}

BOOST_AUTO_TEST_CASE(SQUAREROOT,TOLERANCE) {
    BOOST_TEST(HMM_SquareRootF(0) == 0);

    BOOST_TEST(HMM_SquareRootF(90) == sqrt(90));

    BOOST_TEST(HMM_SquareRootF(45) == sqrt(45));

    BOOST_TEST(HMM_SquareRootF(405) == sqrt(405));
}

BOOST_AUTO_TEST_CASE(Power,TOLERANCE) {
    BOOST_TEST(HMM_PowerF(0, 10) == 0);

    BOOST_TEST(HMM_PowerF(5, 2) == 25.0);

    BOOST_TEST(HMM_PowerF(2, -3) == (1.0 / 8));
}

BOOST_AUTO_TEST_CASE(LERP,TOLERANCE) {
    BOOST_TEST(HMM_Lerp(10, 0.5, 20) == 15.0);

    BOOST_TEST(HMM_Lerp(-20, 0.5, 20) == 0.0);

    BOOST_TEST(HMM_Lerp(-10, 0.5, -20) == -15.0);

    BOOST_TEST(HMM_Lerp(0, 0, 0) == 0);
}

BOOST_AUTO_TEST_CASE(Clammp,TOLERANCE) {
    BOOST_TEST(HMM_Clamp(-10, 5, 20) == 5);

    BOOST_TEST(HMM_Clamp(-10, 25, 20) == 20);

    BOOST_TEST(HMM_Clamp(-10, -11, 20) == -10);

    BOOST_TEST(HMM_Clamp(0.0005, 0.0006, 0.0007) == 0.0006);
}

BOOST_AUTO_TEST_SUITE_END()
