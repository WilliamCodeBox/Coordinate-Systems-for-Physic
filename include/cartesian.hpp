#if !defined(COSPHY_CARTESIAN_H)
#define COSPHY_CARTESIAN_H

#include <iomanip>
#include <iostream>

namespace cosphy {
class Cartesian {
   public:
    // Unit vectors
    static const Cartesian Uo;  // cosphy::Cartesian::Uo
    static const Cartesian Ux;
    static const Cartesian Uy;
    static const Cartesian Uz;

    // Constructors and destructors
    Cartesian(const double& x = 0.0, const double& y = 0.0,
              const double& z = 0.0);
    Cartesian(const Cartesian& other);
    ~Cartesian() = default;

    // access operators
    const double& x() const;
    const double& y() const;
    const double& z() const;

    void x(const double& x);
    void y(const double& y);
    void z(const double& z);

    const double& operator[](uint8_t idx) const;
    double& operator[](uint8_t idx);

    // operators overloading
    Cartesian& operator=(const Cartesian& other);
    bool operator!=(const Cartesian& other) const;
    bool operator==(const Cartesian& other) const;

    /* The following content for vector in physic */

    // scale method
    Cartesian operator*(const double& a);  // vec * scalar
    friend Cartesian operator*(const double& a,
                               const Cartesian& vec);  // scalar * vec
    Cartesian operator/(const double& a);              // vec / scalar

    double norm(const int& p = 2) const;
    double length() const;
    Cartesian normalized() const;

    friend double operator*(const Cartesian& v1, const Cartesian& v2);
    double dotProd(const Cartesian& other);       // dot product
    Cartesian crossProd(const Cartesian& other);  // cross product

    // iostream
    friend std::ostream& operator<<(std::ostream& os, const Cartesian& v);

   private:
    double mx;
    double my;
    double mz;
};
}  // namespace cosphy

#endif  // COSPHY_CARTESIAN_H
