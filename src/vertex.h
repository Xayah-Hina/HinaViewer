#ifndef HINAVIEWER_VERTEX_H
#define HINAVIEWER_VERTEX_H

#include "bgfx_utils.h"

#include <utility>
#define MAX_PARTICLES_POOL_SIZE 20

namespace viewer
{
//    template<typename Vec3f>
//    struct IVertex
//    {
//        Vec3f pos; // 12
//        uint32_t abgr{}; // 16
//    };

//    virtual bgfx::VertexLayout get_layout()
//    {
//        bgfx::VertexLayout _layout;
//        _layout
//                .begin()
//                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
//                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
//                .end();
//        return _layout;
//    }

    template<typename IVertex>
    struct IParticles
    {
        // [IMPLEMENT] the MOVE CONSTRUCTOR and DESTRUCTOR
        IParticles(const IParticles &) = delete;
        IParticles &operator=(const IParticles &) = delete;

        // @formatter:off
        virtual bgfx::VertexLayout get_layout()       = 0;
        virtual void set_ith_vertex(const IVertex &)  = 0;
        virtual const IVertex &get_ith_vertex(size_t) = 0;
        virtual void set_ith_color(uint32_t)          = 0;
        virtual const uint32_t &get_ith_color(size_t) = 0;
        virtual size_t size()                         = 0;
        virtual void* data()                          = 0;
        // @formatter:on
    };

    template<typename IVertex>
    struct ParticlesPool
    {
        static void emplace_back(IParticles<IVertex> &&particles)
        {
            pool[index_next++] = std::move(particles);
        }

        static IParticles<IVertex> pool[MAX_PARTICLES_POOL_SIZE];
        static size_t index_next;
    };
}


#endif //HINAVIEWER_VERTEX_H
