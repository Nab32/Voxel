#include "Scene.h"

//Cube vertices
float cubeVert[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};


//Constructor for scene class
//Params: shader - the shader to be used
//returns: none
Scene::Scene(Shader* shader)
	: _shader(shader) {
	currentMesh = 0;
}

//This function creates a cube mesh
//Params: none
//returns: none
void Scene::createCube() {
	Mesh* cube = new Mesh(cubeVert, 36);
	_meshes.push_back(cube);
}


//This function generates the models
//Params: none
//returns: none
void Scene::generateModels() {
    Texture* cobble = new Texture("C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/textures/cobblestone.jpg", _shader);
    Texture* wood = new Texture("C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/textures/woodencrate.jpg", _shader);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (i % 2 == 0) {
                _modelsCube.push_back(Model(_meshes[0], glm::vec3(i, 1.0f, j), _shader, cobble));
            }
            else {
                _modelsCube.push_back(Model(_meshes[0], glm::vec3(i, 0.0f, j), _shader, wood));
            }
        }
    }
}


//This function returns the models
//Params: none
//returns: _modelsCube
std::vector<Model> Scene::getModels() {
	return _modelsCube;
}


double** Scene::generateNoise() {
    // Initialize the Simplex noise module
    noise::module::Perlin baseNoise;
    baseNoise.SetOctaveCount(4);
    baseNoise.SetPersistence(0.2);



    // Allocate memory for the 2D array
    double** terrainArray = new double* [128];
    for (int i = 0; i < 128; ++i) {
        terrainArray[i] = new double[128];
    }

    // Generate terrain-like noise values
    for (int y = 0; y < 128; ++y) {
        for (int x = 0; x < 128; ++x) {
            double value = 0.0;
            double amplitude = 1.0;
            double frequency = 0.1;

            // Combine multiple octaves
            for (int i = 0; i < 4; ++i) {
                value += baseNoise.GetValue(x * frequency, y * frequency, 0.0) * amplitude;
                amplitude *= 0.2;
                frequency *= 2.0;  // You can adjust this factor for different effects
            }

            terrainArray[x][y] = (value + 1.0) * 0.5;
        }
    }

    return terrainArray;
}