#ifndef HELIX_H
#define HELIX_H

#include "circle.hpp"

/*
    x(t) = R * cos(t)
    y(t) = R * sin(t)
    z(t) = STEP * t // TODO: here 
*/

namespace curves {
    class Helix : public Curve {
    protected:
        Ellipse ellipse;

    public:
        Circle() = delete;
        Circle(double _R);

        Circle(const Circle& _other) noexcept;
        Circle(Circle&& _other) noexcept;

        Circle& operator=(const Circle& _other) noexcept;
        Circle& operator=(Circle&& _other) noexcept;

    public:
        Vector3 getPoint(const double _t) const noexcept override;
        Vector3 getFirstDerivative(const double _t) const noexcept override;

        void setR(double _R);
        double getR() const;
    };
}

#endif // HELIX_H