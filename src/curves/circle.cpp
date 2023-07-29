#include "include/circle.hpp"

namespace curves {
    Circle::Circle(double _R) noexcept 
        : ellipse(_R, _R) {}

    Circle::Circle(const Circle& _other) noexcept 
        : ellipse(_other.ellipse) {}

    Circle::Circle(Circle&& _other) noexcept
        : ellipse(DEFAULT_RADIUS, DEFAULT_RADIUS) {
        *this = std::move(_other);
    }

    Circle& Circle::operator=(const Circle& _other) noexcept {
        if (this != &_other) {
            ellipse = _other.ellipse;
        }
        
        return *this;
    }

    Circle& Circle::operator=(Circle&& _other) noexcept {
        if (this != &_other) {
            ellipse = _other.ellipse;

            _other.ellipse = { DEFAULT_RADIUS, DEFAULT_RADIUS };
        }

        return *this;
    }

    vector3 Circle::getPoint(const double _t) const noexcept {
        return ellipse.getPoint(_t);
    }

    vector3 Circle::getFirstDerivative(const double _t) const noexcept {
        return ellipse.getFirstDerivative(_t);
    }

    void Circle::setR(double _R) {
        ellipse.setRx(_R);
        ellipse.setRy(_R);
    }

    double Circle::getR() const {
        ellipse.getRx();
    }
}