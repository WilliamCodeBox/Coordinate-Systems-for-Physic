#if !defined(COSPHY_SPERICAL_H)
#define COSPHY_SPERICAL_H

#include <iomanip>
#include <iostream>

namespace cosphy {

class Sperical {
   public:
    // Constructors and destructors
    Sperical(const double& r, const double& theta, const double& phi);
    Sperical(const Sperical& other);
    ~Sperical() = default;

    // access operators
    const double& r() const;
    const double& theta() const;
    const double& phi() const;

    void r(const double& r);
    void theta(const double& theta);
    void phi(const double& phi);

    const double& operator[](uint8_t idx) const;
    double& operator[](uint8_t idx);

   private:
    /**
     * @brief distance between reference point P and original point O,
     * i.e., radius
     */
    double mr;
    /**
     * @brief angle between z axis and the line OP, [0, pi] in radians
     */
    double mtheta;
    /**
     * @brief angle between x axis and the projection of OP onto xy plane,
     * [-pi, pi] in radians
     */
    double mphi;
};

}  // namespace cosphy

#endif  // COSPHY_SPERICAL_H
