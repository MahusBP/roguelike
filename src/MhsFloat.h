//
// Created by mhs on 7/17/17.
//

#ifndef ROGUELIKE_COMPAREFLOAT_H
#define ROGUELIKE_COMPAREFLOAT_H

#include <cmath>
namespace Mhs {
    static inline bool isEqual(double a, double b) {
        const double epsilon = 1.0 / std::pow(2, 10);
        return std::abs(a - b) < epsilon;
    }
}
#endif //ROGUELIKE_COMPAREFLOAT_H
