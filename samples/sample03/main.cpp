#include "Eigen/Dense"
#include "igl/read_triangle_mesh.h"
#include "igl/edges.h"

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
    Eigen::MatrixXf V;
    Eigen::MatrixXi F;
    Eigen::MatrixXi E;
//    igl::read_triangle_mesh("F:/Projects/HinaViewer/submodules/bgfx.cmake/bgfx/examples/assets/meshes/cube.obj", V, F);
    igl::readOBJ("F:/Projects/HinaViewer/submodules/bgfx.cmake/bgfx/examples/assets/meshes/cube.obj", V, F);
    igl::edges(F, E);

    m_vertices.clear();
    m_vertices.reserve(V.size());
    for (int i = 0; i < V.rows(); ++i)
    {
        Vertex vertex{};
        vertex.m_x = V(i, 0);
        vertex.m_y = V(i, 1);
        vertex.m_z = V(i, 2);
        vertex.m_abgr = 0xff000000;
        m_vertices.push_back(vertex);
    }
    m_layout = Vertex::get_layout();
    m_vbh = bgfx::createVertexBuffer(bgfx::makeRef(&m_vertices[0], sizeof(Vertex) * m_vertices.size()), m_layout);

    m_indices.clear();
    m_indices.reserve(F.size());
    for (int i = 0; i < F.rows(); ++i)
        for (int j = 0; j < F.cols(); ++j)
            m_indices.push_back(F(i, j));
    m_ibh = bgfx::createIndexBuffer(bgfx::makeRef(m_indices.data(), sizeof(Index) * m_indices.size()));

    m_edges.clear();
    m_edges.reserve(E.size());
    for (int i = 0; i < E.rows(); ++i)
        for (int j = 0; j < E.cols(); ++j)
            m_edges.push_back(E(i, j));
    m_ebh = bgfx::createIndexBuffer(bgfx::makeRef(m_edges.data(), sizeof(Index) * m_edges.size()));
    m_program = loadProgram("vs_sample01", "fs_sample01");
}

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::impl::update()
{
    const bx::Vec3 at = {0.0f, 0.0f, 0.0f};
    const bx::Vec3 eye = {0.0f, 0.0f, -4.0f};
    {
        float view[16];
        bx::mtxLookAt(view, eye, at);

        float proj[16];
        bx::mtxProj(proj, 60.0f, float(m_width) / float(m_height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        bgfx::setViewTransform(0, view, proj);

        // Set view 0 default viewport.
        bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height));

        float mtx[16];
        bx::mtxIdentity(mtx);
        bgfx::setTransform(mtx);
    }

    // This dummy draw call is here to make sure that view 0 is cleared
    // if no other draw calls are submitted to view 0.
    bgfx::touch(0);

    uint64_t state = 0
                     | BGFX_STATE_WRITE_R
                     | BGFX_STATE_WRITE_G
                     | BGFX_STATE_WRITE_B
                     | BGFX_STATE_WRITE_A
                     | BGFX_STATE_WRITE_Z
                     | BGFX_STATE_DEPTH_TEST_LESS
                     | BGFX_STATE_CULL_CW
                     | BGFX_STATE_MSAA
                     | BGFX_STATE_PT_LINES;

    bgfx::setVertexBuffer(0, m_vbh);
    bgfx::setIndexBuffer(m_ebh);
    bgfx::setState(state);
    bgfx::submit(0, m_program);

    bgfx::frame();
}

template<typename Vertex, typename Index>
void Sample<Vertex, Index>::impl::shutdown()
{
    bgfx::destroy(m_ibh);
    bgfx::destroy(m_vbh);
    bgfx::destroy(m_program);
}

int _main_(int _argc, char **_argv)
{
    Sample<Vertex, uint16_t> sample("03-samples", "Rendering simple static mesh.", "https://bkaradzic.github.io/bgfx/examples.html#cubes");
    return runApp(&sample, _argc, _argv);
}
