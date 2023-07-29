#ifndef CURVE_H
#define CURVE_H

#include "../utility/types.hpp"

namespace curves {
    class Curve {
    public:
        virtual ~Curve() = default;

        virtual vector3 getPoint(const double _t) const = 0;
        virtual vector3 getFirstDerivative(const double _t) const = 0;
    };
}

#endif // CURVE_H