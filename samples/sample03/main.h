#ifndef HINAVIEWER_MAIN_H
#define HINAVIEWER_MAIN_H

#include "common.h"
#include "bgfx_utils.h"
#include "imgui/imgui.h"

#include <vector>
#include <memory>

template<typename Vertex, typename Index>
class Sample : public entry::AppI
{
private:
    struct impl;
    std::unique_ptr<impl> m_impl;

public:
    Sample(const char *name, const char *description, const char *url);

    ~Sample() override;

    void init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height) override;

    int shutdown() override;

    bool update() override;
};

template<typename Vertex, typename Index>
Sample<Vertex, Index>::Sample(const char *name, const char *description, const char *url):AppI(name, description, url), m_impl(std::make_unique<Sample<Vertex, Index>::impl>())
{}

template<typename Vertex, typename Index>
Sample<Vertex, Index>::~Sample()
= default;

template<typename Vertex, typename Index>
struct Sample<Vertex, Index>::impl
{
    uint32_t m_width{}, m_height{};
    uint32_t m_debug{}, m_reset{};
    std::vector<Vertex> m_vertices;
    std::vector<Index> m_indices;
    std::vector<Index> m_edges;

    bgfx::VertexLayout m_layout;
    bgfx::VertexBufferHandle m_vbh;
    bgfx::IndexBufferHandle m_ibh;
    bgfx::IndexBufferHandle m_ebh;
    bgfx::ProgramHandle m_program;
    entry::MouseState m_mouseState;


    void init();
    void update();
    void shutdown();
};

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height)
{
    m_impl->m_width = _width;
    m_impl->m_height = _height;
    m_impl->m_debug = BGFX_DEBUG_NONE;
    m_impl->m_reset = BGFX_RESET_VSYNC;

    Args args(_argc, _argv);
    bgfx::Init init;
    init.type = args.m_type;
    init.vendorId = args.m_pciId;
    init.resolution.width = _width;
    init.resolution.height = _height;
    init.resolution.reset = m_impl->m_reset;
    bgfx::init(init);
    bgfx::setDebug(m_impl->m_debug);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0xffffffff, 1.0f, 0);

    m_impl->init();

    imguiCreate();
}

template<typename Vertex, typename Index>
bool Sample<Vertex, Index>::update()
{
    if (!entry::processEvents(m_impl->m_width, m_impl->m_height, m_impl->m_debug, m_impl->m_reset, &m_impl->m_mouseState))
    {
        imguiBeginFrame(m_impl->m_mouseState.m_mx, m_impl->m_mouseState.m_my, (m_impl->m_mouseState.m_buttons[entry::MouseButton::Left] ? IMGUI_MBUT_LEFT : 0)
                                                              | (m_impl->m_mouseState.m_buttons[entry::MouseButton::Right] ? IMGUI_MBUT_RIGHT : 0)
                                                              | (m_impl->m_mouseState.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0), m_impl->m_mouseState.m_mz, uint16_t(m_impl->m_width), uint16_t(m_impl->m_height)
        );

        showExampleDialog(this);

        ImGui::SetNextWindowPos(
                ImVec2(m_impl->m_width - m_impl->m_width / 5.0f - 10.0f, 10.0f), ImGuiCond_FirstUseEver
        );
        ImGui::SetNextWindowSize(
                ImVec2(m_impl->m_width / 5.0f, m_impl->m_height / 3.5f), ImGuiCond_FirstUseEver
        );
        ImGui::Begin("Settings", NULL, 0);

        ImGui::End();

        m_impl->update();

        imguiEndFrame();

        return true;
    }
    return false;
}

template<typename Vertex, typename Index>
int Sample<Vertex, Index>::shutdown()
{
    imguiDestroy();
    m_impl->shutdown();
    bgfx::shutdown();
    return 0;
}

#endif //HINAVIEWER_MAIN_H
