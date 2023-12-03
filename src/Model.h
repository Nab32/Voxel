#include <iostream>
#include <constant.h>
#include "Mesh.h"
#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Model {
    public:
        Model(Mesh* mesh, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Shader* shader);
        void render();
    private:
        Mesh* _mesh;
        Shader* _shader;
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _scale;
};