#ifndef HINAGUI_SHADER_H
#define HINAGUI_SHADER_H

#include "defines.h"
#include <string>

class Shader
{
public:
    virtual void init(const std::string &vertex_shader, const std::string &fragment_shader, const std::string &geometry_shader) = 0;
    virtual void use() = 0;
    virtual int get_shader_id() = 0;

    virtual void set_shader_var_bool(const std::string &name, bool value) = 0;
    virtual void set_shader_var_int(const std::string &name, int value) = 0;
    virtual void set_shader_var_float(const std::string &name, float value) = 0;
    virtual void set_shader_var_vec2(const std::string &name, const Vector2r& value) = 0;
    virtual void set_shader_var_vec3(const std::string &name, const Vector3r& value) = 0;
    virtual void set_shader_var_vec4(const std::string &name, const Vector4r& value) = 0;
    virtual void set_shader_var_mat2(const std::string &name, const Matrix2r& value) = 0;
    virtual void set_shader_var_mat3(const std::string &name, const Matrix3r& value) = 0;
    virtual void set_shader_var_mat4(const std::string &name, const Matrix4r& value) = 0;
};

#endif //HINAGUI_SHADER_H
