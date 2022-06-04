#ifndef HINAGUI_PARTICLES_H
#define HINAGUI_PARTICLES_H

#include "defines.h"

#include <vector>

class Particles
{
public:
    HINA_INLINE size_t init(Vector3r *data, size_t size)
    {
        size_t start = particles_.size();
        size_t end = start + size;
        particles_.resize(end);

        for (size_t i = start; i < start + size; ++i, ++data)
            particles_[start] = *data;

        return start;
    }

    HINA_INLINE void del(unsigned int vertices_start_offset, unsigned int vertices_size)
    {
        for (unsigned int i = 0u; i < vertices_size; ++i)
            particles_[i + vertices_start_offset] = Vector3r(REAL_MAX, REAL_MAX, REAL_MAX);
    }

    HINA_INLINE void del()
    { particles_.clear(); }

public:
    HINA_INLINE Real *get_aligned_particles_data()
    { return particles_.data()->data(); }

    HINA_INLINE Real *get_aligned_particles_data_at(unsigned int offset)
    { return particles_.at(offset).data(); }

    HINA_INLINE const Vector3r *get_ith_particle(unsigned int i)
    { return &particles_[i]; }

    HINA_INLINE void set_ith_particle(unsigned int i, const Vector3r &p)
    { particles_[i] = p; }

    HINA_INLINE size_t size()
    { return particles_.size(); }

protected:
    std::vector<Vector3r> particles_;
};

#endif //HINAGUI_PARTICLES_H
