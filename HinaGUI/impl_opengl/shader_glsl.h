#ifndef HINAGUI_SHADER_GLSL_H
#define HINAGUI_SHADER_GLSL_H

#include "../core/shader.h"

class ShaderGLSL final : public Shader
{
public:
    void init(const std::string &vertex_shader, const std::string &fragment_shader, const std::string &geometry_shader) override;
    void use() override;

    int get_shader_id() override;

    void set_shader_var_bool(const std::string &name, bool value) override;
    void set_shader_var_int(const std::string &name, int value) override;
    void set_shader_var_float(const std::string &name, float value) override;
    void set_shader_var_vec2(const std::string &name, const Vector2r &value) override;
    void set_shader_var_vec3(const std::string &name, const Vector3r &value) override;
    void set_shader_var_vec4(const std::string &name, const Vector4r &value) override;
    void set_shader_var_mat2(const std::string &name, const Matrix2r &value) override;
    void set_shader_var_mat3(const std::string &name, const Matrix3r &value) override;
    void set_shader_var_mat4(const std::string &name, const Matrix4r &value) override;

private:
    unsigned int ID_ = 0;
};


#endif //HINAGUI_SHADER_GLSL_H
