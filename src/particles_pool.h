#ifndef HINAVIEWER_PARTICLES_POOL_H
#define HINAVIEWER_PARTICLES_POOL_H
// @formatter:off

#include <utility>
#define MAX_PARTICLES_POOL_SIZE 20

namespace viewer
{
    template<typename IVertex>
    struct IParticles
    {
        IParticles(const IParticles &)                                          = delete;
        IParticles &operator=(const IParticles &)                               = delete;

        virtual bgfx::VertexLayout get_layout()                                 = 0;
        virtual void*              data()                                       = 0;
        virtual size_t             size()                                       = 0;
    };

    template<typename IVertex>
    struct ParticlesPool
    {
        static void emplace_back(IParticles<IVertex> &&particles) { pool[index_next++] = std::move(particles); }

        static IParticles<IVertex> pool[MAX_PARTICLES_POOL_SIZE];
        static size_t              index_next;
    };
}

// @formatter:on
#endif //HINAVIEWER_PARTICLES_POOL_H
