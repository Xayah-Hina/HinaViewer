#include "shader_glsl.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

std::string load_shader_code(const std::string &file_path)
{
    if (file_path.empty()) return "";

    std::ifstream sf;
    std::stringstream ss;

    sf.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    sf.open(file_path);
    ss << sf.rdbuf();
    sf.close();

    return ss.str();
}

void check_shader(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

void ShaderGLSL::init(const std::string &vertex_shader, const std::string &fragment_shader, const std::string &geometry_shader)
{
    const char *vertex_shader_code;
    const char *fragment_shader_code;
    const char *geometry_shader_code; // TODO: to support geometry shader in the future

    try
    {
        vertex_shader_code = load_shader_code(vertex_shader).c_str();
        fragment_shader_code = load_shader_code(fragment_shader).c_str();
        geometry_shader_code = load_shader_code(geometry_shader).c_str();
    } catch (std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

    unsigned int vertex_ID;
    vertex_ID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_ID, 1, &vertex_shader_code, NULL);
    glCompileShader(vertex_ID);
    check_shader(vertex_ID, "VERTEX");

    unsigned int fragment_ID;
    fragment_ID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_ID, 1, &fragment_shader_code, NULL);
    glCompileShader(fragment_ID);
    check_shader(fragment_ID, "FRAGMENT");

    ID_ = glCreateProgram();
    glAttachShader(ID_, vertex_ID);
    glAttachShader(ID_, fragment_ID);
    glLinkProgram(ID_);
    check_shader(ID_, "PROGRAM");

    glDeleteShader(vertex_ID);
    glDeleteShader(fragment_ID);
}

void ShaderGLSL::use()
{
    glUseProgram(ID_);
}

int ShaderGLSL::get_shader_id()
{
    return ID_;
}

void ShaderGLSL::set_shader_var_bool(const std::string &name, bool value)
{
    glUniform1i(glGetUniformLocation(ID_, name.c_str()), (int)value);
}

void ShaderGLSL::set_shader_var_int(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(ID_, name.c_str()), value);
}

void ShaderGLSL::set_shader_var_float(const std::string &name, float value)
{
    glUniform1f(glGetUniformLocation(ID_, name.c_str()), value);
}

void ShaderGLSL::set_shader_var_vec2(const std::string &name, const Vector2r &value)
{
    // Fixme: Ensure value is float based, else error prone
    glUniform2fv(glGetUniformLocation(ID_, name.c_str()), 1, value.data());
}

void ShaderGLSL::set_shader_var_vec3(const std::string &name, const Vector3r &value)
{
    glUniform3fv(glGetUniformLocation(ID_, name.c_str()), 1, value.data());
}

void ShaderGLSL::set_shader_var_vec4(const std::string &name, const Vector4r &value)
{
    glUniform4fv(glGetUniformLocation(ID_, name.c_str()), 1, value.data());
}

void ShaderGLSL::set_shader_var_mat2(const std::string &name, const Matrix2r &value)
{
    glUniformMatrix2fv(glGetUniformLocation(ID_, name.c_str()), 1, GL_FALSE, value.data());
}

void ShaderGLSL::set_shader_var_mat3(const std::string &name, const Matrix3r &value)
{
    glUniformMatrix3fv(glGetUniformLocation(ID_, name.c_str()), 1, GL_FALSE, value.data());
}

void ShaderGLSL::set_shader_var_mat4(const std::string &name, const Matrix4r &value)
{
    glUniformMatrix4fv(glGetUniformLocation(ID_, name.c_str()), 1, GL_FALSE, value.data());
}
