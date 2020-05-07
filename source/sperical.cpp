#include "sperical.hpp"

namespace cosphy {

Sperical::Sperical(const double& r, const double& theta, const double& phi)
    : mr(r), mtheta(theta), mphi(phi) {}

Sperical::Sperical(const Sperical& other)
    : mr(other.mr), mtheta(other.mtheta), mphi(other.mphi) {}

const double& Sperical::r() const { return mr; }
const double& Sperical::theta() const { return mtheta; }
const double& Sperical::phi() const { return mphi; }

void Sperical::r(const double& r) { mr = r; }
void Sperical::theta(const double& theta) { mtheta = theta; }
void Sperical::phi(const double& phi) { mphi = phi; }

const double& Sperical::operator[](uint8_t idx) const { return (&mr)[idx]; }
double& Sperical::operator[](uint8_t idx) { return (&mr)[idx]; }

}  // namespace cosphy
