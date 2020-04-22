#pragma once
#include <iostream>
#include <numeric>
#include <vector>
#include <float.h> 
#include "HMM.h"

#define TOLERANCE *utf::tolerance(1e-4)

using namespace std;
namespace utf = boost::unit_test;
namespace tt = boost::test_tools;



// template <class T>
// vector<T> operator==(const vector<T>& v1, const vector<T>& v2) {
//     return inner_product(begin(v1), end(v1), begin(v2), [&](auto a, auto b) { return a && b; },
//                          [&](auto a, auto b) { return a == b; });
// }

// template <class T>
// vector<T> operator==(const vector<vector<T>>& v1, const vector<vector<T>>& v2) {
//     return inner_product(begin(v1), end(v1), begin(v2), [&](auto a, auto b) { return a && b; },
//                          [&](auto a, auto b) { return a == b; });
// }
