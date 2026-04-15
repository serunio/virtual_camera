#ifndef HELLO_WINDOW_MESH_H
#define HELLO_WINDOW_MESH_H
#include "config.h"


class Mesh {
    unsigned int VAO, VBO, EBO;
    int numOfElements;
    GLenum mode;
public:
    Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const int numOfElements, const GLenum mode) : numOfElements(numOfElements), mode(mode)
    {
        glGenBuffers(1, &VBO);
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(0);
    }

    void draw() const
    {
        glBindVertexArray(VAO);
        glDrawElements( mode, numOfElements, GL_UNSIGNED_INT, 0);
    }
};



#endif //HELLO_WINDOW_MESH_H
