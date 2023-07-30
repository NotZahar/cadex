#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <iomanip>
#include <algorithm>

#include "curves/include/curve.hpp"
#include "curves/include/circle.hpp"
#include "curves/include/ellipse.hpp"
#include "curves/include/helix.hpp"

void fillContainer(std::vector<std::shared_ptr<curves::Curve>>& _container) {
    const int numberOfCurves = 30;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> curvesDist(curves::curve::CIRCLE, curves::curve::HELIX);
    std::uniform_real_distribution paramsDist(curves::DEFAULT_RADIUS, curves::MAX_RADIUS);
 
    for (int i = 0; i <= numberOfCurves; ++i) {
        switch (curvesDist(gen)) {
        case curves::curve::CIRCLE:
            _container.push_back(std::make_shared<curves::Circle>(paramsDist(gen)));
            break;
        case curves::curve::ELLIPSE:
            _container.push_back(std::make_shared<curves::Ellipse>(paramsDist(gen), paramsDist(gen)));
            break;
        case curves::curve::HELIX:
            _container.push_back(std::make_shared<curves::Helix>(paramsDist(gen), paramsDist(gen)));
            break;
        }
    }
}

void printPointsAndDerivatives(const std::vector<std::shared_ptr<curves::Curve>>& _container) {
    const double t = curves::PI4;
    for (const auto& curve : _container) {
        std::cout << std::left << std::setw(9) << curve->getName() 
            << "p: ("
            << std::setw(9) << std::setprecision(6) << curve->getPoint(t).x
            << std::setw(9) << std::setprecision(6) << curve->getPoint(t).y
            << std::setw(9) << std::setprecision(6) << curve->getPoint(t).z << ")"
            << "  d: ("
            << std::setw(9) << std::setprecision(6) << curve->getFirstDerivative(t).x
            << std::setw(9) << std::setprecision(6) << curve->getFirstDerivative(t).y
            << std::setw(9) << std::setprecision(6) << curve->getFirstDerivative(t).z << ")"
            << std::endl;
    }
}

void fillSecondContainer(const std::vector<std::shared_ptr<curves::Curve>>& _container, std::vector<std::shared_ptr<curves::Circle>>& _secondContainer) {
    for (const auto& curve : _container) {
        if (auto&& circle = std::dynamic_pointer_cast<curves::Circle>(curve)) {
            _secondContainer.push_back(circle);
        }
    }
}

void sortAndPrintSecondContainer(std::vector<std::shared_ptr<curves::Circle>>& _secondContainer) {
    std::sort(_secondContainer.begin(), _secondContainer.end(), 
        [](const std::shared_ptr<curves::Circle>& lhs, const std::shared_ptr<curves::Circle>& rhs) {
            return lhs->getR() < rhs->getR();
        }
    );

    std::cout << "\nsorted:\n";
    for (const auto& circle : _secondContainer) {
        std::cout << std::left << std::setw(9) << circle->getName() << "r: " << circle->getR() << '\n';
    }
}

double computeTotalSumOfRadii(const std::vector<std::shared_ptr<curves::Circle>>& _secondContainer) {
    return std::accumulate(_secondContainer.cbegin(), _secondContainer.cend(), 0.,
        [](double sum, const std::shared_ptr<curves::Circle>& circle) {
            return sum + circle->getR();
        }
    );
}

int main() {
    std::vector<std::shared_ptr<curves::Curve>> container;
    std::vector<std::shared_ptr<curves::Circle>> secondContainer;

    fillContainer(container);
    printPointsAndDerivatives(container);
    fillSecondContainer(container, secondContainer);
    sortAndPrintSecondContainer(secondContainer);
    std::cout << "\ntotal sum: " << computeTotalSumOfRadii(secondContainer) << '\n';

    return 0;
}