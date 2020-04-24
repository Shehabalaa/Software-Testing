/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_NormalizeVec2(hmm_vec2 A);
- hmm_vec3 HMM_NormalizeVec3(hmm_vec3 A);
- hmm_vec4 HMM_NormalizeVec4(hmm_vec4 A);
*/
#define BOOST_TEST_MAIN
#pragma once
#include <boost/test/unit_test.hpp>
#include "test_helpers.hpp"

template <class vecT = float>
float norm2f(const vector<vecT>& vec) {
    return sqrtf(accumulate(begin(vec), end(vec), 0.0, [](auto a, auto b) { return a + b * b; }));
}

BOOST_AUTO_TEST_SUITE(vec_normalizations_test_suite)

BOOST_AUTO_TEST_CASE(test_HMM_NormalizeVec2_given_intvec, TOLERANCE) {
    //Arrange
    auto vec = HMM_Vec2i(5, 3);
    //Act
    auto res = HMM_NormalizeVec2(vec);
    //Assert
    float expectedRes[2];
    float norm = norm2f<int>(vector<int>(vec.Elements, vec.Elements + 2));
    transform(vec.Elements, vec.Elements + 2, expectedRes, [&](auto a) { return a / norm; });

    BOOST_TEST(res.Elements == expectedRes);                                  // test values
    BOOST_TEST(norm2f(vector<float>(res.Elements, res.Elements + 2)) == 1.f);  // consistency check
}

BOOST_AUTO_TEST_CASE(test_HMM_NormalizeVec2_given_flaotvec, TOLERANCE) {
    //Arrange
    auto vec = HMM_Vec2(5.5, 0.1);
    //Act
    auto res = HMM_NormalizeVec2(vec);
    //Assert
    float expectedRes[2];
    float norm = norm2f(vector<float>(vec.Elements, vec.Elements + 2));
    transform(vec.Elements, vec.Elements + 2, expectedRes, [&](auto a) { return a / norm; });

    BOOST_TEST(res.Elements == expectedRes);
    BOOST_TEST(norm2f(vector<float>(res.Elements, res.Elements + 2)) == 1.f);  // consistency check
}

BOOST_AUTO_TEST_CASE(test_HMM_NormalizeVec3_given_intvec, TOLERANCE) {
    //Arrange
    auto vec = HMM_Vec3i(1, 3, 15);
    //Act
    auto res = HMM_NormalizeVec3(vec);
    //Assert
    float expectedRes[3];
    float norm = norm2f<int>(vector<int>(vec.Elements, vec.Elements + 3));
    transform(vec.Elements, vec.Elements + 3, expectedRes, [&](auto a) { return a / norm; });

    BOOST_TEST(res.Elements == expectedRes);                                  // test values
    BOOST_TEST(norm2f(vector<float>(res.Elements, res.Elements + 3)) == 1.f);  // consistency check
}

BOOST_AUTO_TEST_CASE(test_HMM_NormalizeVec3_given_flaotvec, TOLERANCE) {
    //Arrange
    auto vec = HMM_Vec3(5.5, 0.1, -8.5);
    //Act
    auto res = HMM_NormalizeVec3(vec);
    //Assert
    float expectedRes[3];
    float norm = norm2f(vector<float>(vec.Elements, vec.Elements + 3));
    transform(vec.Elements, vec.Elements + 3, expectedRes, [&](auto a) { return a / norm; });

    BOOST_TEST(res.Elements == expectedRes);
    BOOST_TEST(norm2f(vector<float>(res.Elements, res.Elements + 3)) == 1.f);  // consistency check
}

BOOST_AUTO_TEST_CASE(test_HMM_NormalizeVec4_given_intvec, TOLERANCE) {
    //Arrange
    auto vec = HMM_Vec4i(5, 1, 15, 6);
    //Act
    auto res = HMM_NormalizeVec4(vec);
    //Assert
    float expectedRes[4];
    float norm = norm2f<int>(vector<int>(vec.Elements, vec.Elements + 4));
    transform(vec.Elements, vec.Elements + 4, expectedRes, [&](auto a) { return a / norm; });

    BOOST_TEST(res.Elements == expectedRes);                                  // test values
    BOOST_TEST(norm2f(vector<float>(res.Elements, res.Elements + 4)) == 1.f);  // consistency check
}

BOOST_AUTO_TEST_CASE(test_HMM_NormalizeVec4_given_flaotvec, TOLERANCE) {
    //Arrange
    auto vec = HMM_Vec4(5.5, 0.1, -8.5, 4.9);
    //Act
    auto res = HMM_NormalizeVec4(vec);
    //Assert
    float expectedRes[4];
    float norm = norm2f(vector<float>(vec.Elements, vec.Elements + 4));
    transform(vec.Elements, vec.Elements + 4, expectedRes, [&](auto a) { return a / norm; });

    BOOST_TEST(res.Elements == expectedRes);
    BOOST_TEST(norm2f(vector<float>(res.Elements, res.Elements + 4)) == 1.f);  // consistency check
}

BOOST_AUTO_TEST_SUITE_END()
