#ifndef HINAGUI_MESH_H
#define HINAGUI_MESH_H

#include "defines.h"

#include <vector>

struct Vertex
{
    std::vector<unsigned int> e_list;
    std::vector<unsigned int> f_list;
};

struct Edge
{
    unsigned int v_start, v_end;
    unsigned int f_1, f_2;
};

struct Face
{
    std::vector<unsigned int> e_list;
};

class Mesh
{
public:
    HINA_INLINE void init(unsigned int *data, size_t size, const std::vector<unsigned int> &textures_id, unsigned int vertices_per_face = 3)
    {
        indices_.resize(size);
        for (size_t i = 0; i < size; ++i, ++data)
            indices_[i] = *data;
        textures_id_ = textures_id;
    }

    HINA_INLINE void clear()
    {
        indices_.clear();
        vertices_.clear();
        edges_.clear();
        faces_.clear();
    }

public:
    HINA_INLINE unsigned int *get_aligned_indices_data()
    { return indices_.data(); }

    HINA_INLINE Face *get_ith_face(unsigned int i)
    { return &faces_[i]; }

    HINA_INLINE size_t size()
    { return indices_.size() / vertices_per_face_; }

    [[nodiscard]] HINA_INLINE unsigned int vertices_per_face() const
    { return vertices_per_face_; }

protected:
    unsigned int vertices_per_face_;
    std::vector<unsigned int> indices_;
    std::vector<Vertex> vertices_;
    std::vector<Edge> edges_;
    std::vector<Face> faces_;

    std::vector<unsigned int> textures_id_;
};

#endif //HINAGUI_MESH_H






