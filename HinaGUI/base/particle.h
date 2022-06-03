#ifndef HINAGUI_PARTICLE_H
#define HINAGUI_PARTICLE_H

#include "defines.h"

#include <vector>

template<typename T>
class Particles
{
public:
    virtual HINA_INLINE Real *get_aligned_data() = 0;
    virtual HINA_INLINE const T &get_ith_particle(unsigned int i) = 0;
    virtual HINA_INLINE void set_ith_particle(unsigned int i, const T &) = 0;

    template<typename Derived, typename std::enable_if<std::is_base_of<Particles<T>, Derived>::value>::type * = nullptr>
    Derived *as()
    {
        return dynamic_cast<Derived *>(this);
    }
};

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

#endif //HINAGUI_PARTICLE_H
