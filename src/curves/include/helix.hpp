#ifndef HELIX_H
#define HELIX_H

#include "circle.hpp"

/*
    x(t) = R * cos(t)
    y(t) = R * sin(t)
    z(t) = STEP * t 
*/

namespace curves {
    class Helix : public Curve {
    protected:
        Circle circle;
        double STEP;

    public:
        Helix() = delete;
        Helix(double _R, double _STEP);

        Helix(const Helix& _other) noexcept;
        Helix(Helix&& _other) noexcept;

        Helix& operator=(const Helix& _other) noexcept;
        Helix& operator=(Helix&& _other) noexcept;

    public:
        vector3 getPoint(const double _t) const noexcept override;
        vector3 getFirstDerivative(const double _t) const noexcept override;
        std::string getName() const override;

        void setR(double _R);
        void setSTEP(double _STEP);
        double getR() const;
        double getSTEP() const;
    };
}

#endif // HELIX_H