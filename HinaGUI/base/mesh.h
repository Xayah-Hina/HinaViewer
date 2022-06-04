#ifndef HINAGUI_MESH_H
#define HINAGUI_MESH_H

#include "defines.h"

class Edge
{};

class Mesh
{
public:
    virtual HINA_INLINE int *get_aligned_data() = 0;

    template<typename Derived, typename std::enable_if<std::is_base_of<Mesh, Derived>::value>::type * = nullptr>
    Derived *as()
    {
        return dynamic_cast<Derived *>(this);
    }
};

#endif //HINAGUI_MESH_H
