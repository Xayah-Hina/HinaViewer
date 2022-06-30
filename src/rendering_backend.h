#ifndef HINAVIEWER_RENDERING_BACKEND_H
#define HINAVIEWER_RENDERING_BACKEND_H

#include "common.h"
#include "bgfx_utils.h"
#include "imgui/imgui.h"

#include "particles_pool.h"
#include "mesh.h"

#include <memory>

namespace viewer
{
//    using MyParticlesPool = ParticlesPool<IVertex>;

    template<typename IVertex>
    class RenderingBackend : public entry::AppI
    {
    public:
        void init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height) override;
        int shutdown() override;
        bool update() override;

    public:
//        std::unique_ptr<ParticlesPool<IVertex>> particles_pool;

//        uint32_t m_width;
//        uint32_t m_height;
//        uint32_t m_debug;
//        uint32_t m_reset;
//        bgfx::VertexBufferHandle m_vbh;
//        bgfx::IndexBufferHandle m_ibh;
//        bgfx::ProgramHandle m_program;
//        int64_t m_timeOffset;
//        int32_t m_pt;
//
//        bool m_r;
//        bool m_g;
//        bool m_b;
//        bool m_a;
    };

    template<typename IVertex>
    void RenderingBackend<IVertex>::init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height)
    {

    }

    template<typename IVertex>
    int RenderingBackend<IVertex>::shutdown()
    {
        return 0;
    }

    template<typename IVertex>
    bool RenderingBackend<IVertex>::update()
    {
        return false;
    }
}


#endif //HINAVIEWER_RENDERING_BACKEND_H
