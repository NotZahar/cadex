#include "include/helix.hpp"

namespace curves {
    Helix::Helix(double _R, double _STEP)
        : circle(_R), STEP(_STEP) {}

    Helix::Helix(const Helix& _other) noexcept
        : circle(_other.circle), STEP(_other.STEP) {}

    Helix::Helix(Helix&& _other) noexcept
        : circle(DEFAULT_RADIUS), STEP(DEFAULT_STEP) {
        *this = std::move(_other);
    }

    Helix& Helix::operator=(const Helix& _other) noexcept {
        if (this != &_other) {
            circle = _other.circle;
            STEP = _other.STEP;
        }
        
        return *this;
    }

    Helix& Helix::operator=(Helix&& _other) noexcept {
        if (this != &_other) {
            circle = _other.circle;
            STEP = _other.STEP;

            _other.circle = Circle(DEFAULT_RADIUS);
            _other.STEP = DEFAULT_STEP;
        }

        return *this;
    }

    vector3 Helix::getPoint(const double _t) const noexcept {
        vector3 point = circle.getPoint(_t);
        point.z = STEP * _t;
        return point;
    }

    vector3 Helix::getFirstDerivative(const double _t) const noexcept {
        vector3 firstDerivative = circle.getFirstDerivative(_t);
        firstDerivative.z = STEP;
        return firstDerivative;
    }

    std::string Helix::getName() const {
        return "helix";
    }

    void Helix::setR(double _R) {
        circle.setR(_R);
    }

    void Helix::setSTEP(double _STEP) {
        STEP = _STEP;
    }

    double Helix::getR() const {
        return circle.getR();
    }

    double Helix::getSTEP() const {
        return STEP;
    }
}