#include "rendering_backend.h"

viewer::RenderingBackend::RenderingBackend(const char *name, const char *description, const char *url) : AppI(name, description, url)
{}

viewer::RenderingBackend::~RenderingBackend()
= default;

void viewer::RenderingBackend::init(int32_t _argc, const char *const *_argv, uint32_t _width, uint32_t _height)
{
    Args args(_argc, _argv);

    m_width = _width;
    m_height = _height;
    m_debug = BGFX_DEBUG_NONE;
    m_reset = BGFX_RESET_VSYNC;

    bgfx::Init init;
    init.type = args.m_type;
    init.vendorId = args.m_pciId;
    init.resolution.width = m_width;
    init.resolution.height = m_height;
    init.resolution.reset = m_reset;
    bgfx::init(init);

    // Enable debug text.
    bgfx::setDebug(m_debug);

    // Set view 0 clear state.
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0);
}

bool viewer::RenderingBackend::update()
{
    return false;
}

int viewer::RenderingBackend::shutdown()
{
    return 0;
}

void viewer::RenderingBackend::load_vertex_buffer(std::shared_ptr<IVertex> v_ptr)
{

}

void viewer::RenderingBackend::load_indices_buffer(std::shared_ptr<IMesh> m_ptr)
{

}
