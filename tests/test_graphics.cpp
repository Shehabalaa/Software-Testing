/*
this file should cover the following functions in hmm.h
- hmm_mat4 HMM_Orthographic(float Left, float Right, float Bottom, float Top, float Near, float Far);
- hmm_mat4 HMM_Perspective(float FOV, float AspectRatio, float Near, float Far);
- hmm_mat4 HMM_LookAt(hmm_vec3 Eye, hmm_vec3 Center, hmm_vec3 Up);
*/

#define BOOST_TEST_MAIN
#pragma once
#include <boost/test/unit_test.hpp>

#include "test_helpers.hpp"

vector<float> Mat4Vec(hmm_mat4 m) {
    vector<float> res(4 * 4, 0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res[i * 4 + j] = m.Elements[i][j];
        }
    }

    return move(res);
}

void printMatrix(hmm_mat4 m1) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << m1.Elements[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

// https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/orthographic-projection-matrix
hmm_mat4 constructOrhographic(float Left, float Right, float Bottom, float Top, float Near, float Far) {
    hmm_mat4 Result = HMM_Mat4d(1.0f);

    Result.Elements[0][0] = 2.0f / (Right - Left);
    Result.Elements[1][1] = 2.0f / (Top - Bottom);
    Result.Elements[2][2] = -2.0f / (Far - Near);
    Result.Elements[3][0] = -1 * (Left + Right) / (Right - Left);
    Result.Elements[3][1] = -1 * (Bottom + Top) / (Top - Bottom);
    Result.Elements[3][2] = -1 * (Far + Near) / (Far - Near);

    return Result;
}

BOOST_AUTO_TEST_SUITE(HMM_Orthographicc)

// BOOST_AUTO_TEST_CASE(ALLEQUAL) {
//     hmm_mat4 expectedOutput = constructOrhographic(1, 1, 1, 1, 1, 1);

//     hmm_mat4 orthographic = HMM_Orthographic(1, 1, 1, 1, 1, 1);

//     //printMatrix(expectedOutput);
//     std::cout << std::endl;
//     //printMatrix(orthographic);

//     BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
// }

BOOST_AUTO_TEST_CASE(ALLNotEQUAL) {
    hmm_mat4 expectedOutput = constructOrhographic(1, 2, 3, 4, 5, 6);

    hmm_mat4 orthographic = HMM_Orthographic(1, 2, 3, 4, 5, 6);

    //printMatrix(expectedOutput);
    std::cout << std::endl;
    //printMatrix(orthographic);

    BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
}

// BOOST_AUTO_TEST_CASE(ALLZeors) {
//     hmm_mat4 expectedOutput = constructOrhographic(0, 0, 0, 0, 0, 0);

//     hmm_mat4 orthographic = HMM_Orthographic(0, 0, 0, 0, 0, 0);

//     //printMatrix(expectedOutput);
//     std::cout << std::endl;
//     //printMatrix(orthographic);

//     BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
// }

BOOST_AUTO_TEST_CASE(BIGNumbers) {
    std::cout << "before" << std::endl;
    hmm_mat4 expectedOutput = constructOrhographic(-FLT_MIN, FLT_MIN, 1000000, 0, 1000000, 0);

    hmm_mat4 orthographic = HMM_Orthographic(-FLT_MIN, FLT_MIN, 1000000, 0, 1000000, 0);

    //printMatrix(expectedOutput);
    std::cout << std::endl;
    //printMatrix(orthographic);

    BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_SUITE_END()

hmm_mat4 constructPersective(float FOV, float AspectRatio, float Near, float Far) {
    hmm_mat4 Result = HMM_Mat4d(0.0f);

    Result.Elements[2][3] = -1.0f;
    Result.Elements[2][2] = (Near + Far) / (Near - Far);
    Result.Elements[3][2] = (2.0f * Near * Far) / (Near - Far);

    float angle = HMM_TanF(FOV * (HMM_PI32 / 360.0f));

    Result.Elements[0][0] = 1.0f / angle;
    Result.Elements[1][1] = AspectRatio / angle;

    return Result;
}

BOOST_AUTO_TEST_SUITE(HMM_perectivee)

BOOST_AUTO_TEST_CASE(FAREQUALNEAR) {
    hmm_mat4 expectedOutput = constructPersective(100, 10, 10, 10);

    hmm_mat4 orthographic = HMM_Perspective(100, 10, 10, 10);

    BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_CASE(FAREnotQUALNEAR) {
    hmm_mat4 expectedOutput = constructPersective(100, 10, 34, 10);

    hmm_mat4 orthographic = HMM_Perspective(100, 10, 34, 10);

    BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
}

// BOOST_AUTO_TEST_CASE(ALLZeors) {
//     hmm_mat4 expectedOutput = constructPersective(0, 0, 0, 0);

//     hmm_mat4 orthographic = HMM_Perspective(0, 0, 0, 0);

//     BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
// }

BOOST_AUTO_TEST_CASE(BIGNEARANDFAR) {
    hmm_mat4 expectedOutput = constructPersective(100, 1, -FLT_MIN, +FLT_MIN);

    //printMatrix(expectedOutput);

    hmm_mat4 orthographic = HMM_Perspective(100, 1, -FLT_MIN, +FLT_MIN);

    //printMatrix(orthographic);

    BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_CASE(FOVNinty) {
    hmm_mat4 expectedOutput = constructPersective(90, 1, -FLT_MIN, +FLT_MIN);

    //printMatrix(expectedOutput);

    hmm_mat4 orthographic = HMM_Perspective(90, 1, -FLT_MIN, +FLT_MIN);

    //printMatrix(orthographic);

    BOOST_TEST(Mat4Vec(orthographic) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_SUITE_END()

hmm_mat4 constructLookAt(hmm_vec3 Eye, hmm_vec3 Center, hmm_vec3 Up) {
    hmm_mat4 lookat = HMM_Mat4d(1.0f);
    hmm_vec3 f = HMM_NormalizeVec3(HMM_SubtractVec3(Center, Eye));
    hmm_vec3 s = HMM_NormalizeVec3(HMM_Cross(f, Up));
    hmm_vec3 u = HMM_Cross(s, f);

    lookat.Elements[3][0] = -HMM_DotVec3(s, Eye);
    lookat.Elements[3][1] = -HMM_DotVec3(u, Eye);
    lookat.Elements[3][2] = HMM_DotVec3(f, Eye);
    lookat.Elements[3][3] = 1.0f;

    lookat.Elements[0][0] = s.X;
    lookat.Elements[1][0] = s.Y;
    lookat.Elements[2][0] = s.Z;

    lookat.Elements[0][1] = u.X;
    lookat.Elements[1][1] = u.Y;
    lookat.Elements[2][1] = u.Z;

    lookat.Elements[0][2] = -f.X;
    lookat.Elements[1][2] = -f.Y;
    lookat.Elements[2][2] = -f.Z;

    return lookat;
}

BOOST_AUTO_TEST_SUITE(HMM_LOOKATT)

BOOST_AUTO_TEST_CASE(EYEEQZERO) {
    hmm_vec3 Eye;
    Eye.X = 0;
    Eye.Y = 0;
    Eye.Z = 0;

    hmm_vec3 Center;
    Center.X = 1;
    Center.Y = 2;
    Center.Z = 3;

    hmm_vec3 Up;
    Up.X = 3;
    Up.Y = 4;
    Up.Z = 5;

    hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
    hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

    BOOST_TEST(Mat4Vec(lookat) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_CASE(CENTERQZERO) {
    hmm_vec3 Eye;
    Eye.X = 10;
    Eye.Y = 30;
    Eye.Z = 40;

    hmm_vec3 Center;
    Center.X = 0;
    Center.Y = 0;
    Center.Z = 0;

    hmm_vec3 Up;
    Up.X = 3;
    Up.Y = 4;
    Up.Z = 5;

    hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
    hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

    BOOST_TEST(Mat4Vec(lookat) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_CASE(CENTERQEYE, TOLERANCE) {
    hmm_vec3 Eye;
    Eye.X = 10.0f;
    Eye.Y = 30.0f;
    Eye.Z = 40.0f;

    hmm_vec3 Center;
    Center.X = 12.0f;
    Center.Y = 13.0f;
    Center.Z = 14.0f;

    hmm_vec3 Up;
    Up.X = 3.0f;
    Up.Y = 4.0f;
    Up.Z = 5.0f;

    hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
    hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);
    BOOST_TEST(Mat4Vec(lookat) == Mat4Vec(expectedOutput));
}

BOOST_AUTO_TEST_CASE(allDifferent) {
    hmm_vec3 Eye;
    Eye.X = 10;
    Eye.Y = 30;
    Eye.Z = 40;

    hmm_vec3 Center;
    Center.X = 100;
    Center.Y = 101;
    Center.Z = 102;

    hmm_vec3 Up;
    Up.X = 69;
    Up.Y = 23;
    Up.Z = 11;

    hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
    hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

    BOOST_TEST(Mat4Vec(lookat) == Mat4Vec(expectedOutput));
}

// BOOST_AUTO_TEST_CASE(ALLZEROS) {
//     hmm_vec3 Eye;
//     Eye.X = 0;
//     Eye.Y = 0;
//     Eye.Z = 0;

//     hmm_vec3 Center;
//     Center.X = 0;
//     Center.Y = 0;
//     Center.Z = 0;

//     hmm_vec3 Up;
//     Up.X = 0;
//     Up.Y = 0;
//     Up.Z = 0;

//     hmm_mat4 expectedOutput = constructLookAt(Eye, Center, Up);
//     hmm_mat4 lookat = HMM_LookAt(Eye, Center, Up);

//     BOOST_TEST(Mat4Vec(lookat) == Mat4Vec(expectedOutput));
// }

BOOST_AUTO_TEST_CASE(SCALING_VECTOR) {
    hmm_vec3 vec = {1., 2., 3.};

    hmm_mat4 mat = HMM_Scale(vec);

    hmm_mat4 expectedRes = {0.f};
    for (int i = 0; i < 3; ++i) expectedRes.Elements[i][i] = vec.Elements[i];
    expectedRes.Elements[3][3] = 1.f;

    BOOST_TEST(Mat4Vec(mat) == Mat4Vec(expectedRes));
}

BOOST_AUTO_TEST_CASE(ROTATING_VECTOR) {
    hmm_vec3 vec = {1.f, 2.f, 3.f};
    float theta = 180.f / 3;

    hmm_mat4 mat = HMM_Rotate(theta, vec);

    // normalize
    vector<float> myvec = {1.f, 2.f, 3.f};
    float norm = sqrtf(accumulate(begin(myvec), end(myvec), 0.0, [](auto a, auto b) { return a + b * b; }));
    transform(begin(myvec), end(myvec), begin(myvec), [&](auto a) { return a / norm; });

    theta = HMM_PI32 / 3;
    float comp = 1.f - cosf(theta);
    hmm_mat4 expectedRes = {0.f};

    expectedRes.Elements[0][0] = cosf(theta) + myvec[0] * myvec[0] * comp;
    expectedRes.Elements[0][1] = myvec[0] * myvec[1] * comp + myvec[2] * sinf(theta);
    expectedRes.Elements[0][2] = myvec[0] * myvec[2] * comp - myvec[1] * sinf(theta);

    expectedRes.Elements[1][0] = myvec[0] * myvec[1] * comp - myvec[2] * sinf(theta);
    expectedRes.Elements[1][1] = cosf(theta) + myvec[1] * myvec[1] * comp;
    expectedRes.Elements[1][2] = myvec[1] * myvec[2] * comp + myvec[0] * sinf(theta);

    expectedRes.Elements[2][0] = myvec[0] * myvec[2] * comp + myvec[1] * sinf(theta);
    expectedRes.Elements[2][1] = myvec[1] * myvec[2] * comp - myvec[0] * sinf(theta);
    expectedRes.Elements[2][2] = cosf(theta) + myvec[2] * myvec[2] * comp;

    expectedRes.Elements[3][3] = 1.;

    BOOST_TEST(Mat4Vec(mat) == Mat4Vec(expectedRes));
}

BOOST_AUTO_TEST_SUITE_END()
