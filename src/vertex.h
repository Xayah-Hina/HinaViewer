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
}


#endif //HINAVIEWER_VERTEX_H
