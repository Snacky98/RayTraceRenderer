/* Author: Nicholas Ziegler, 7/2/2019
 * this is for headers that will be precompiled before main is run. Be sure to include all headers for classes in
 * this file*/

#ifndef PCH_H
#define PCH_H

constexpr double EPSILON = 0.00001;

//librarbies
#include <iostream>
#include <string>
#include <iterator>
#include <cmath>

//source
#include "Tuple3d.h"
#include "Color.h"
#include "canvas.h"

//test
#include "test_common.h"
#include "tuple_test.h"
#include "projectile.h"
#include "canvas_test.h"

#endif //PCH_H
