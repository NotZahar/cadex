#ifndef CURVE_H
#define CURVE_H

#include "utility/types.hpp"

namespace curves {
    class Curve {
    public:
        virtual Vector3 getPoint(const double _t) const noexcept = 0;
        virtual Vector3 getFirstDerivative(const double _t) const noexcept = 0;

        virtual ~Curve() = default;
    };
}

#endif // CURVE_H