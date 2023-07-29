#include "include/ellipse.hpp"

namespace curves {
    Ellipse::Ellipse(double _Rx, double _Ry) noexcept 
        : Rx(_Rx <= 0. ? DEFAULT_RADIUS : _Rx), Ry(_Ry <= 0. ? DEFAULT_RADIUS : _Ry) {}

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