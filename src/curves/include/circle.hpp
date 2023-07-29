#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.hpp"

/*
    x(t) = R * cos(t)
    y(t) = R * sin(t)
    z(t) = 0
*/

namespace curves {
    class Circle : public Curve {
    protected: 
        Ellipse ellipse;

    public:
        Circle() = delete;
        explicit Circle(double _R) noexcept;

        Circle(const Circle& _other) noexcept;
        Circle(Circle&& _other) noexcept;

        Circle& operator=(const Circle& _other) noexcept;
        Circle& operator=(Circle&& _other) noexcept;

    public:
        vector3 getPoint(const double _t) const noexcept override;
        vector3 getFirstDerivative(const double _t) const noexcept override;

        void setR(double _R);
        double getR() const;
    };
}

#endif // CIRCLE_H