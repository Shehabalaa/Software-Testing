/*
this file should cover the following functions in hmm.h
- hmm_vec2 HMM_DivideVec2(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec2 HMM_DivideVec2f(hmm_vec2 Left, float Right);
- hmm_vec3 HMM_DivideVec3(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec3 HMM_DivideVec3f(hmm_vec3 Left, float Right);
- hmm_vec4 HMM_DivideVec4(hmm_vec4 Left, hmm_vec4 Right);
- hmm_vec4 HMM_DivideVec4f(hmm_vec4 Left, float Right);
- hmm_mat4 HMM_DivideMat4f(hmm_mat4 Matrix, float Scalar);
take care of operator overloading also for these functions:
- hmm_vec2 operator/(hmm_vec2 Left, hmm_vec2 Right);
- hmm_vec3 operator/(hmm_vec3 Left, hmm_vec3 Right);
- hmm_vec4 operator/(hmm_vec4 Left, hmm_vec4 Right);
- hmm_vec2 operator/(hmm_vec2 Left, float Right);
- hmm_vec3 operator/(hmm_vec3 Left, float Right);
- hmm_vec4 operator/(hmm_vec4 Left, float Right);
- hmm_mat4 operator/(hmm_mat4 Left, float Right);
- hmm_vec2 &operator/=(hmm_vec2 &Left, hmm_vec2 Right);
- hmm_vec3 &operator/=(hmm_vec3 &Left, hmm_vec3 Right);
- hmm_vec4 &operator/=(hmm_vec4 &Left, hmm_vec4 Right);
- hmm_vec2 &operator/=(hmm_vec2 &Left, float Right);
- hmm_vec3 &operator/=(hmm_vec3 &Left, float Right);
- hmm_vec4 &operator/=(hmm_vec4 &Left, float Right);
- hmm_mat4 &operator/=(hmm_mat4 &Left, float Right);
*/
#pragma once
#include <boost/test/unit_test.hpp>
#include "test_helpers.hpp"


BOOST_AUTO_TEST_SUITE(division_test_suite)

BOOST_AUTO_TEST_SUITE(division_vec2_by_int)

BOOST_AUTO_TEST_CASE(test_HMM_DivideVec2_int_BothVecsZeros,TOLERANCE) {
    //Arrange
    auto zeros = HMM_Vec2i(0, 0);
    //Act
    auto res = HMM_DivideVec2(zeros, zeros);
    //Assert
    BOOST_TEST(isnan(res.Elements[0]));
    BOOST_TEST(isnan(res.Elements[1]));
}

BOOST_AUTO_TEST_CASE(test_HMM_DivideVec2_int_V1_zeros,TOLERANCE) {
    //Arrange
    auto zeros = HMM_Vec2i(0, 0);
    auto right = HMM_Vec2i(5, -10);
    //Act
    auto res = HMM_DivideVec2(zeros, right);
    //Assert
    float expectedRes[2] = {0, 0};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_CASE(test_HMM_DivideVec2_int_postives,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2i(1, 5);
    auto right = HMM_Vec2i(3, 4);
    //Act
    auto res = HMM_DivideVec2(left, right);
    //Assert
    float expectedRes[2] = {left.Elements[0] / right.Elements[0], left.Elements[1] / right.Elements[1]};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_CASE(test_HMM_DivideVec2_int_pos_neg,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2i(1, 5);
    auto right = HMM_Vec2i(-3, -4);
    //Act
    auto res = HMM_DivideVec2(left, right);
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] / right.Elements[0], left.Elements[1] / right.Elements[1]}));
}

BOOST_AUTO_TEST_CASE(test_HMM_DivideVec2_float_pos_neg,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2(10., 1.);
    auto right = HMM_Vec2(-2, -5.);
    //Act
    auto res = HMM_DivideVec2(left, right);
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] / right.Elements[0], left.Elements[1] / right.Elements[1]}));
}

BOOST_AUTO_TEST_SUITE_END()

//--------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(division_vec2_by_float)

BOOST_AUTO_TEST_CASE(test_HMM_DivideVec2f_vec_x_posfloat,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    float right = 10.;
    //Act
    auto res = HMM_DivideVec2f(left, right);
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] / right, left.Elements[1] / right}));
}

BOOST_AUTO_TEST_SUITE_END()
//--------------------------------------------------------------
BOOST_AUTO_TEST_SUITE(division_vec2_using_operators)

BOOST_AUTO_TEST_CASE(test_division_vec2_by_vec2_using_division_operator,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2(10., 1.);
    auto right = HMM_Vec2(-2, -5.);
    //Act
    auto res = left / right;
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] / right.Elements[0], left.Elements[1] / right.Elements[1]}));
}

BOOST_AUTO_TEST_CASE(test_division_vec2_by_float_using_division_operator,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    float right = 10.;
    //Act
    auto res = left / right;
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] / right, left.Elements[1] / right}));
}

BOOST_AUTO_TEST_CASE(test_division_vec2_by_vec2_using_division_equal_operator,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    auto right = HMM_Vec2(-2, -5.);
    //Act
    auto res = left;
    res /= right;
    //Assert
    BOOST_TEST(vector<float>(res.Elements, res.Elements + 2) == vector<float>({left.Elements[0] / right.Elements[0], left.Elements[1] / right.Elements[1]}));
}

BOOST_AUTO_TEST_CASE(test_division_vec2_by_float_using_division_equal_operator,TOLERANCE) {
    //Arrange
    auto left = HMM_Vec2(.5, .2);
    float right = 10.;
    //Act
    auto res = left;
    res /= right;
    //Assert
    float expectedRes[2] = {left.Elements[0] / right, left.Elements[1] / right};
    BOOST_TEST(res.Elements == expectedRes);
}

BOOST_AUTO_TEST_SUITE_END()

//-----------------------
BOOST_AUTO_TEST_SUITE(division_mat4_by_floatscalar)

BOOST_AUTO_TEST_CASE(test_HMM_DivideMat4f,TOLERANCE) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    float right = .5;
    //Act
    hmm_mat4 res = HMM_DivideMat4f(left, right);

    //Assert
    float expMat[4][4] = {{arr[0][0] / right, arr[0][1] / right, arr[0][2] / right, arr[0][3] / right},
                          {arr[1][0] / right, arr[1][1] / right, arr[1][2] / right, arr[1][3] / right},
                          {arr[2][0] / right, arr[2][1] / right, arr[2][2] / right, arr[2][3] / right},
                          {arr[3][0] / right, arr[3][1] / right, arr[3][2] / right, arr[3][3] / right}};

    BOOST_TEST(res.Elements == expMat);
}

BOOST_AUTO_TEST_SUITE_END()

//-----------------------
BOOST_AUTO_TEST_SUITE(division_mat4_using_operators)

BOOST_AUTO_TEST_CASE(test_HMM_DivideMat4f,TOLERANCE) {
    //Arrange
    auto left = hmm_mat4();
    float arr[4][4] = {{1, 2, 3, 4},
                       {5, -6, 7, 8},
                       {9, 10, 11, 12},
                       {0, 15, 0, 0}};
    copy(&arr[0][0], &arr[0][0] + 4 * 4, &left.Elements[0][0]);

    float right = .5;
    //Act
    hmm_mat4 res = HMM_DivideMat4f(left, right);

    //Assert
    float expMat[4][4] = {{arr[0][0] / right, arr[0][1] / right, arr[0][2] / right, arr[0][3] / right},
                          {arr[1][0] / right, arr[1][1] / right, arr[1][2] / right, arr[1][3] / right},
                          {arr[2][0] / right, arr[2][1] / right, arr[2][2] / right, arr[2][3] / right},
                          {arr[3][0] / right, arr[3][1] / right, arr[3][2] / right, arr[3][3] / right}};

    BOOST_TEST(res.Elements == expMat);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()