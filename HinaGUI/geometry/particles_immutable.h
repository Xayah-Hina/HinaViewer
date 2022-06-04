#ifndef HINAGUI_PARTICLES_IMMUTABLE_H
#define HINAGUI_PARTICLES_IMMUTABLE_H

#include "../base/particles.h"

class ImmutableParticles final : public Particles<Vector3r>
{
public:
    Real *get_aligned_data() override
    {
        return particles_.data()->data();
    }

    HINA_INLINE const Vector3r &get_ith_particle(unsigned int i) override
    {
        return particles_[i];
    }

    HINA_INLINE void set_ith_particle(unsigned int i, const Vector3r &p) override
    {
        particles_[i] = p;
    }

private:
    std::vector<Vector3r> particles_;
};


#endif //HINAGUI_PARTICLES_IMMUTABLE_H
