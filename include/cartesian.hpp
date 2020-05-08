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

    /**
     * @brief Construct a new Cartesian object
     *
     * @param x coordinate on x axis
     * @param y coordinate on y axis
     * @param z coordinate on z axis
     */
    Cartesian(const double& x = 0.0, const double& y = 0.0,
              const double& z = 0.0);

    /**
     * @brief Construct a new Cartesian object
     *
     * @param other an existing Cartesian object
     */
    Cartesian(const Cartesian& other);
    ~Cartesian() = default;

    // access operators
    const double& x() const;
    const double& y() const;
    const double& z() const;

    void x(const double& x);
    void y(const double& y);
    void z(const double& z);

    /**
     * @brief const reference of member variable
     *
     * @param idx the index of member variable, 0 for x, 1 for y, and 2 for z
     * @return const double&
     */
    const double& operator[](uint8_t idx) const;
    /**
     * @brief reference of member variable
     *
     * @param idx the index of member variable, 0 for x, 1 for y, and 2 for z
     * @return double&
     */
    double& operator[](uint8_t idx);

    // operators overloading
    Cartesian& operator=(const Cartesian& other);
    bool operator!=(const Cartesian& other) const;
    bool operator==(const Cartesian& other) const;

    /* The following content for vector in physic */

    // scale method
    /**
     * @brief operator overloading for Vector multiplying a scalar
     *
     * @param a scalar
     * @return Cartesian
     */
    Cartesian operator*(const double& a);  // vec * scalar
    /**
     * @brief Friend operator overloading for scalar multilying a Vector
     *
     * @param a scalar
     * @param vec Vector
     * @return Cartesian
     */
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
