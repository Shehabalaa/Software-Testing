#define BOOST_TEST_MAIN 
#pragma once
#include <boost/test/unit_test.hpp>
#include "test_helpers.hpp"

BOOST_AUTO_TEST_SUITE(TEST_PREDICATES)

BOOST_AUTO_TEST_CASE(TC_PREDICATE_1) {
    // PREDICATE // LINE 513
    auto res = HMM_Power(2, -1);
    BOOST_TEST(res == 0.5f);
    auto res2 = HMM_Power(2, 1);
    BOOST_TEST(res2 == 2);
}

BOOST_AUTO_TEST_CASE(TC_PREDICATE_2) {
    // PREDICATE // LINE 514
    auto res = HMM_Power(2, -1);
    BOOST_TEST(res == 0.5f);
    auto res2 = HMM_Power(2, 1);
    BOOST_TEST(res2 == 2);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_3) {
    // PREDICATE // LINE 515
    auto res = HMM_Power(2, 0);
    BOOST_TEST(res == 1);
    auto res2 = HMM_Power(2, -1);
    BOOST_TEST(res2 == 0.5);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_4) {
    // PREDICATE // LINE 516
    auto res = HMM_Power(2, 0);
    BOOST_TEST(res == 1);
    auto res2 = HMM_Power(2, -1);
    BOOST_TEST(res2 == 0.5);
}

BOOST_AUTO_TEST_CASE(TC_PREDICATE_5) {
    // PREDICATE // LINE 549
    auto res = HMM_Clamp(20, 10, 25);
    BOOST_TEST(res == 20);

    auto res3 = HMM_Clamp(20, 30, 25);
    BOOST_TEST(res3 == 25);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_6) {
    // PREDICATE // LINE 553
    auto res = HMM_Clamp(20, 30, 25);
    BOOST_TEST(res == 25);

    auto res3 = HMM_Clamp(20, 22, 25);
    BOOST_TEST(res3 == 22);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_7) {
    // PREDICATE // LINE 553
    auto res = HMM_Clamp(20, 30, 25);
    BOOST_TEST(res == 25);

    auto res3 = HMM_Clamp(20, 22, 25);
    BOOST_TEST(res3 == 22);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_8) {
    // PREDICATE // LINE 62
    auto res = HMM_MIN(30, 20);
    BOOST_TEST(res == 20);

    auto res3 = HMM_MIN(30, 40);
    BOOST_TEST(res3 == 30);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_9) {
    // PREDICATE // LINE 63
    auto res = HMM_MAX(30, 20);
    BOOST_TEST(res == 30);

    auto res3 = HMM_MAX(30, 40);
    BOOST_TEST(res3 == 40);
}

BOOST_AUTO_TEST_CASE(TC_PREDICATE_10) {
    // PREDICATE // LINE 64
    auto res = HMN_ABS(-20);
    BOOST_TEST(res == 20);

    auto res3 = HMN_ABS(20);
    BOOST_TEST(res3 == 20);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_11) {
    // PREDICATE // LINE 64
    auto res = HMM_MOD(3, 7);
    BOOST_TEST(res == 3);

    auto res3 = HMM_MOD(-3, 7);
    BOOST_TEST(res3 == 4);
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_12) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                matrix_1.Elements[i][j] = 1.0;
            } 
        }
    }
    hmm_mat4 res = HMM_AddMat4(matrix_1, matrix_1);
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                BOOST_TEST(res.Elements[i][j] == 2.0);
            } 
        }
    }
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_13) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                matrix_1.Elements[i][j] = 1.0;
            } 
        }
    }
    hmm_mat4 res = HMM_SubtractMat4(matrix_1, matrix_1);
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                BOOST_TEST(res.Elements[i][j] == 0);
            } 
        }
    }
}

BOOST_AUTO_TEST_CASE(TC_PREDICATE_14) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                matrix_1.Elements[i][j] = 1.0;
            } else {
                matrix_1.Elements[i][j] = 0;
            }
        }
    }
    hmm_mat4 res = HMM_MultiplyMat4(matrix_1, matrix_1);
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                BOOST_TEST(res.Elements[i][j] == 1);
            } else {
                BOOST_TEST(res.Elements[i][j] == 0);
            }
        }
    }
}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_15) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                matrix_1.Elements[i][j] = 1.0;
            } else {
                matrix_1.Elements[i][j] = 0;
            }
        }
    }
    hmm_mat4 res = HMM_MultiplyMat4f(matrix_1, 2.0);
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                BOOST_TEST(res.Elements[i][j] == 2.0);
            } 
        }
    }
}

BOOST_AUTO_TEST_CASE(TC_PREDICATE_16) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                matrix_1.Elements[i][j] = 1.0;
            } else {
                matrix_1.Elements[i][j] = 0;
            }
        }
    }

    hmm_vec4 vect;
    for(int i = 0;i < 4;++i) {
        vect.Elements[i] = i + 1;
    }

    hmm_vec4 res = HMM_MultiplyMat4ByVec4(matrix_1, vect);
    for(int i = 0 ; i < 4; ++i){
        BOOST_TEST(res.Elements[i] == i + 1);
    }

}


BOOST_AUTO_TEST_CASE(TC_PREDICATE_17) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                matrix_1.Elements[i][j] = 1.0;
            } else {
                matrix_1.Elements[i][j] = 0;
            }
        }
    }
    hmm_mat4 res = HMM_DivideMat4f(matrix_1, 2.0);
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            if(i == j){
                BOOST_TEST(res.Elements[i][j] == 0.5);
            } else {
                BOOST_TEST(res.Elements[i][j] == 0);
            }
        }
    }
}

BOOST_AUTO_TEST_CASE(TC_PREDICATE_18) {
    hmm_mat4 matrix_1;
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            matrix_1.Elements[i][j] = i + 1;
        }
    }
    hmm_mat4 res = HMM_Transpose(matrix_1);
    for(int i = 0 ; i < 4; ++i){
        for(int j = 0; j< 4; j++){
            BOOST_TEST(matrix_1.Elements[i][j] == i + 1);
        }
    }
}


BOOST_AUTO_TEST_SUITE_END()

#pragma endregion HMM_AddMat4