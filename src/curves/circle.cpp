#include "include/circle.hpp"

namespace curves {
    Circle::Circle(double _R) noexcept 
        : ellipse(_R, _R) {}

    Circle::Circle(const Circle& _other) noexcept
        : ellipse(_other.ellipse) {}

    Circle::Circle(Circle&& _other) noexcept 
        : ellipse(std::move(_other.ellipse)) {}

    Circle& operator=(const Circle& _other) noexcept;
    Circle& operator=(Circle&& _other) noexcept;

    vector3 getPoint(const double _t) const noexcept override;
    vector3 getFirstDerivative(const double _t) const noexcept override;

    void setR(double _R);
    double getR() const;
    
    /*Ellipse::Ellipse(double _Rx, double _Ry) noexcept 
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
    }*/
}