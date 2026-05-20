#ifndef SHADER_H
#define SHADER_H

#include "config.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;

class Shader 
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath)
    {
        unsigned int vertex = getShader(vertexPath, GL_VERTEX_SHADER);
        unsigned int fragment = getShader(fragmentPath, GL_FRAGMENT_SHADER);

        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);

        int success;
        char infoLog[1024];
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(ID, 1024, NULL, infoLog);
            cout << "ERROR::PROGRAM_COMPILATION_ERROR:\n " << infoLog << "\n" << endl;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void use()
    {
        glUseProgram(ID);
    }

    void setInt(const string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setFloat(const string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setMat4(const string &name, mat4 value)
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value_ptr(value));
    }

    void setVec3(const string &name, vec3 value)
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
    }

    void setVec3V(const string &name, vector<vec3>& value) const
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), value.size(), value_ptr(value[0]));
    }

    void setBool(const string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }


private:
    unsigned int getShader(const char* shaderPath, GLenum type) 
    {
        string shaderCodeStr;
        ifstream shaderFile;

        shaderFile.exceptions (ifstream::failbit | ifstream::badbit);
        try
        {
            shaderFile.open(shaderPath);
            stringstream shaderStream;
            shaderStream << shaderFile.rdbuf();
            shaderFile.close();
            shaderCodeStr = shaderStream.str();
        }
        catch (ifstream::failure& e)
        {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << endl;
        }
        const char* shaderCode = shaderCodeStr.c_str();

        unsigned int shader;
        shader = glCreateShader(type);
        glShaderSource(shader, 1, &shaderCode, NULL);
        glCompileShader(shader);

        int success;
        char infoLog[1024];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            cout << "ERROR::SHADER_COMPILATION_ERROR:\n " << infoLog << "\n" << endl;
        }
        return shader;
    }
};
#endif