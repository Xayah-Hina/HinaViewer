#ifndef HINAGUI_PARTICLES_H
#define HINAGUI_PARTICLES_H

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

#endif //HINAGUI_PARTICLES_H
