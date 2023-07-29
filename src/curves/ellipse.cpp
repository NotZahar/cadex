#include "include/ellipse.hpp"

namespace curves {
    Ellipse::Ellipse(double _Rx, double _Ry) noexcept 
        : Rx(_Rx <= 0. ? DEFAULT_RADIUS : _Rx), Ry(_Ry <= 0. ? DEFAULT_RADIUS : _Ry) {}

    Ellipse::Ellipse(const Ellipse& _other) noexcept
        : Rx(_other.Rx), Ry(_other.Ry) {}
    
    Ellipse::Ellipse(Ellipse&& _other) noexcept
        : Rx(DEFAULT_RADIUS), Ry(DEFAULT_RADIUS) {
        *this = std::move(_other);
    }

    Ellipse& Ellipse::operator=(const Ellipse& _other) noexcept {
        if (this != &_other) {
            Rx = _other.Rx;
            Ry = _other.Ry;
        }
        
        return *this;
    }

    Ellipse& Ellipse::operator=(Ellipse&& _other) noexcept {
        if (this != &_other) {
            Rx = _other.Rx;
            Ry = _other.Ry;

            _other.Rx = DEFAULT_RADIUS;
            _other.Ry = DEFAULT_RADIUS;
        }

        return *this;
    }

    vector3 Ellipse::getPoint(const double _t) const {
        return { Rx * std::cos(_t), Ry * std::sin(_t), 0 };
    }

    vector3 Ellipse::getFirstDerivative(const double _t) const {
        return { -Rx * std::sin(_t), Ry * std::cos(_t), 0 };
    }

    void Ellipse::setRx(double _Rx) {
        Rx = (_Rx <= 0 ? Rx : _Rx);
    }

    void Ellipse::setRy(double _Ry) {
        Ry = (_Ry <= 0 ? Ry : _Ry);
    }

    double Ellipse::getRx() const {
        return Rx;
    }

    double Ellipse::getRy() const {
        return Ry;
    }
}