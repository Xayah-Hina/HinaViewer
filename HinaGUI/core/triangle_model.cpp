#include "triangle_model.h"

Real *TriangleModel::get_vertices_data()
{
    return particles_.get_aligned_data();
}

int *TriangleModel::get_indices_data()
{
    return mesh_.get_aligned_data();
}

int TriangleModel::get_vertices_size()
{
    return 0;
}

int TriangleModel::get_indices_size()
{
    return 0;
}
