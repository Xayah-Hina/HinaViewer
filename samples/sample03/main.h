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
Sample<Vertex, Index>::Sample(const char *name, const char *description, const char *url):AppI(name, description, url)
{}

template<typename Vertex, typename Index>
Sample<Vertex, Index>::~Sample()
= default;

template<typename Vertex, typename Index>
struct Sample<Vertex, Index>::impl
{
    uint32_t m_width{}, m_height{};
    bgfx::VertexLayout m_layout;

    bgfx::VertexBufferHandle m_vbh;
    bgfx::IndexBufferHandle m_ibh;
    bgfx::ProgramHandle m_program;

    void init();
    void update();
    void shutdown();
};

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height)
{
    Args args(_argc, _argv);
    bgfx::Init init;
    init.type = args.m_type;
    init.vendorId = args.m_pciId;
    init.resolution.width = _width;
    init.resolution.height = _height;
    init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);
    bgfx::setDebug(BGFX_DEBUG_NONE);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0);

    m_impl->m_width = _width;
    m_impl->m_height = _height;

    m_impl->init();
}

template<typename Vertex, typename Index>
bool Sample<Vertex, Index>::update()
{
    m_impl->update();
    return true;
}

template<typename Vertex, typename Index>
int Sample<Vertex, Index>::shutdown()
{
    m_impl->shutdown();
    return 0;
}

#endif //HINAVIEWER_MAIN_H
