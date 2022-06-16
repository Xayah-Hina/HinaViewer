#ifndef HINAVIEWER_RENDERING_BACKEND_H
#define HINAVIEWER_RENDERING_BACKEND_H

#include "common.h"
#include "bgfx_utils.h"
#include "imgui/imgui.h"

#include "vertex.h"
#include "mesh.h"

namespace viewer
{
    class RenderingBackend : public entry::AppI
    {
    public:
        RenderingBackend(const char *name, const char *description, const char *url);
        ~RenderingBackend() override;

    public:
        void init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height) override;
        bool update() override;
        int shutdown() override;

    public:
        void load_vertex_buffer(std::shared_ptr<IVertex> v_ptr); // RAII: pass by value to pass life cycle
        void load_indices_buffer(std::shared_ptr<IMesh> m_ptr); // RAII: pass by value to pass life cycle

        uint32_t m_width;
        uint32_t m_height;
        uint32_t m_debug;
        uint32_t m_reset;
        bgfx::VertexBufferHandle m_vbh;
//        bgfx::IndexBufferHandle m_ibh[BX_COUNTOF(ptState)];
        bgfx::ProgramHandle m_program;
        int64_t m_timeOffset;
        int32_t m_pt;

        bool m_r;
        bool m_g;
        bool m_b;
        bool m_a;
    };
}


#endif //HINAVIEWER_RENDERING_BACKEND_H
