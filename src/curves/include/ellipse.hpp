#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <cmath>

#include "curve.hpp"
#include "../utility/constants.hpp"

/*
    x(t) = Rx * cos(t)
    y(t) = Ry * sin(t)
    z(t) = 0
*/

namespace curves {
    class Ellipse : public Curve {
    private:
        double Rx;
        double Ry;
    
    public:
        Ellipse() = delete;
        Ellipse(double _Rx, double _Ry) noexcept;

        Ellipse(const Ellipse&) noexcept = default;
        Ellipse(Ellipse&&) noexcept = default;

        Ellipse& operator=(const Ellipse&) noexcept = default;
        Ellipse& operator=(Ellipse&&) noexcept = default;

    public:
        vector3 getPoint(const double _t) const override;
        vector3 getFirstDerivative(const double _t) const override;

        void setRx(double _Rx);
        void setRy(double _Ry);
        double getRx() const;
        double getRy() const;
    };
}

#endif // ELLIPSE_H