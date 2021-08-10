/* Author: Nicholas Zieger, 7/2/2019
 * this is for headers that will be precompiled before main is run. Be sure to include all headers for classes int
 * this file*/

#ifndef PCH_H
#define PCH_H

constexpr float EPSILON = 0.00001;

//librarbies
#include <iostream>
#include <string>
#include <cmath>

//source
#include "Tuple3d.h"
#include "tuple_features.h"
#include "Color.h"
#include "Canvas.h"

//test
#include "test_common.h"
#include "tuple_test.h"
#include "projectile.h"
#include "canvas_test.h"

#endif //PCH_H
