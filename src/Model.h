#pragma once
#include <iostream>
#include "constant.h"
#include "Mesh.h"
#include "Shader.h"
#include "Textures.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Model {
    public:
        //TODO: Model(Mesh* mesh, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Shader* shader);
        Model(Mesh* mesh, glm::vec3 position, Shader* shader, Texture* text);
        void updateModel();
        void changePosition(glm::vec3 newPosition);
        void render();
    private:
        Mesh* _mesh;
        Shader* _shader;
        Texture* _text;
        glm::mat4 _model;
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _scale;
};