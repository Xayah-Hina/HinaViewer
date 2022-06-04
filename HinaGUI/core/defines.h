#ifndef HINAGUI_DEFINES_H
#define HINAGUI_DEFINES_H

#include "Eigen/Dense"

#include <cfloat>

#if defined(WIN32) || defined(_WIN32) || defined(WIN64)
  #define HINA_INLINE __forceinline
#else
#define HINA_INLINE __attribute__((always_inline))
#endif

#ifdef HINA_USE_DOUBLE
using Real = double;
#define REAL_MAX DBL_MAX
#define REAL_MIN DBL_MIN
#else
using Real = float;
#define REAL_MAX FLT_MAX
#define REAL_MIN FLT_MIN
#endif

using Vector2r = Eigen::Matrix<Real, 2, 1, Eigen::DontAlign>;
using Vector3r = Eigen::Matrix<Real, 3, 1, Eigen::DontAlign>;
using Vector4r = Eigen::Matrix<Real, 4, 1, Eigen::DontAlign>;
using Vector5r = Eigen::Matrix<Real, 5, 1, Eigen::DontAlign>;
using Vector6r = Eigen::Matrix<Real, 6, 1, Eigen::DontAlign>;
using Matrix2r = Eigen::Matrix<Real, 2, 2, Eigen::DontAlign>;
using Matrix3r = Eigen::Matrix<Real, 3, 3, Eigen::DontAlign>;
using Matrix4r = Eigen::Matrix<Real, 4, 4, Eigen::DontAlign>;

const Vector4r WHITE = Vector4r(1.f, 1.f, 1.f, 1.f);
const Vector4r BLACK = Vector4r(0.f, 0.f, 0.f, 1.f);
const Vector4r RED = Vector4r(1.f, 0.f, 0.f, 1.f);
const Vector4r GREEN = Vector4r(0.f, 1.f, 0.f, 1.f);
const Vector4r BLUE = Vector4r(0.f, 0.f, 1.f, 1.f);

#endif //HINAGUI_DEFINES_H
