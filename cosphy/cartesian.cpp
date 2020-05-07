#include "cartesian.hpp"

#include <cmath>

namespace cosphy {

// Unit vectors
const Cartesian Cartesian::Uo(0.0, 0.0, 0.0);
const Cartesian Cartesian::Ux(1.0, 0.0, 0.0);
const Cartesian Cartesian::Uy(0.0, 1.0, 0.0);
const Cartesian Cartesian::Uz(0.0, 0.0, 1.0);

// Constructors and destructors
Cartesian::Cartesian(const double& x, const double& y, const double& z)
    : mx(x), my(y), mz(z) {}

Cartesian::Cartesian(const Cartesian& other)
    : mx(other.mx), my(other.my), mz(other.mz) {}

// access operators
const double& Cartesian::x() const { return mx; }
const double& Cartesian::y() const { return my; }
const double& Cartesian::z() const { return mz; }

void Cartesian::x(const double& x) { mx = x; }
void Cartesian::y(const double& y) { my = y; }
void Cartesian::z(const double& z) { mz = z; }

const double& Cartesian::operator[](uint8_t idx) const { return (&mx)[idx]; }
double& Cartesian::operator[](uint8_t idx) { return (&mx)[idx]; }

// operators overloading
Cartesian& Cartesian::operator=(const Cartesian& other) {
    mx = other.mx;
    my = other.my;
    mz = other.mz;
    return *this;
}

bool Cartesian::operator==(const Cartesian& other) {
    return (mx == other.mx) && (my == other.my) && (mz == other.mz);
}

bool Cartesian::operator!=(const Cartesian& other) {
    return this->operator==(other) ? false : true;
}

// methods for vector
Cartesian Cartesian::operator*(const double& a) {
    return Cartesian(mx * a, my * a, mz * a);
}
Cartesian operator*(const double& a, const Cartesian& vec) {
    return Cartesian(vec.x() * a, vec.y() * a, vec.z() * a);
}
Cartesian Cartesian::operator/(const double& a) {
    return Cartesian(mx / a, my / a, mz / a);
}

double Cartesian::norm(const int& p) const {
    return pow(pow(mx, p) + pow(my, p) + pow(mz, p), 1.0 / p);
}
double Cartesian::length() const { return this->norm(2); }
Cartesian Cartesian::normalized() const {
    Cartesian normalizedVec;

    double length = this->length();
    if (length != 0.0) {
        normalizedVec.x(mx / length);
        normalizedVec.y(my / length);
        normalizedVec.z(mz / length);
    }

    return normalizedVec;
}

}  // namespace cosphy
