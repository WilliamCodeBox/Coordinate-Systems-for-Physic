#if !defined(COSPHY_CARTESIAN_H)
#define COSPHY_CARTESIAN_H

#include <iomanip>

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

    /* The following content for vector in physic */
    double norm() const;
    double length() const;
    Cartesian normalized() const;

    double dotProd(const Cartesian& other);       // dot product
    Cartesian crossProd(const Cartesian& other);  // cross product

   private:
    double mx;
    double my;
    double mz;
};
}  // namespace cosphy

#endif  // COSPHY_CARTESIAN_H
