#include "igl/readOBJ.h"

#include "main.h"

struct Vertex
{
    float m_x;
    float m_y;
    float m_z;
    uint32_t m_abgr;

    static bgfx::VertexLayout get_layout()
    {
        bgfx::VertexLayout layout;
        layout.begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
                .end();
        return layout;
    }
};

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::impl::init()
{
    std::vector<std::vector<float>> V;
    std::vector<std::vector<int>> F;
    igl::readOBJ("F:/Projects/HinaViewer/submodules/bgfx.cmake/bgfx/examples/assets/meshes/bunny.obj", V, F);

    std::vector<Vertex> vertices;
    for (const auto &i: V)
    {
        Vertex vertex{};
        vertex.m_x = i[0];
        vertex.m_y = i[1];
        vertex.m_z = i[2];
        vertex.m_abgr = 0xff000000;
        vertices.push_back(vertex);
    }
    m_layout = Vertex::get_layout();
    m_vbh = bgfx::createVertexBuffer(bgfx::makeRef(vertices.data(), sizeof(Vertex) * vertices.size()), m_layout);
}

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::impl::update()
{

}

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::impl::shutdown()
{

}

int _main_(int _argc, char **_argv)
{
    Sample<Vertex, uint64_t> sample("03-samples", "Rendering simple static mesh.", "https://bkaradzic.github.io/bgfx/examples.html#cubes");
    return runApp(&sample, _argc, _argv);
}
