#ifndef HINAVIEWER_VERTEX_H
#define HINAVIEWER_VERTEX_H

#include "bgfx_utils.h"

#include "Eigen/Dense"

namespace viewer
{
    struct IVertex
    {
        virtual void init() = 0;
        static bgfx::VertexLayout m_layout;
    };

    struct VertexEigen : IVertex
    {
        void init() override;

        Eigen::Vector3f pos;
        uint32_t abgr;
    };

    template<typename Vertex, typename std::enable_if<std::is_base_of<viewer::IVertex, Vertex>::value>::type * = nullptr>
    struct Particles
    {
        
        Vertex *vertices;
    };
}


#endif //HINAVIEWER_VERTEX_H
