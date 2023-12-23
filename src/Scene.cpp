#include "Scene.h"
#include <random>

std::vector<float> cubeVert = {
    //VERTICES            //TEXTURE COORDS
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
	Mesh* cube = new Mesh(cubeVert.data(), 36);
	_meshes.push_back(cube);
}


//This function generates the models
//Params: none
//returns: none
void Scene::generateModels() {
    double** arrayTer = generateNoise();
    Texture* wood = new Texture("C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/textures/woodencrate.jpg", _shader);
    Texture* cobble = new Texture("C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/textures/cobblestone.jpg", _shader);
    Texture* dirt = new Texture("C:/Users/nabil/OneDrive/Desktop/voxel/Voxel/src/textures/dirt.jpg", _shader);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 1);
    for (int i = 0; i < 124; i++) {
        for (int j = 0; j < 124; j++) {
            // Generate a random number (0 or 1)
            int result = distribution(generator);
            _modelsCube.push_back(Model(_meshes[0], glm::vec3(i, int(arrayTer[i][j] * 15), j), _shader, result ? cobble : dirt));
            _modelsCube.push_back(Model(_meshes[0], glm::vec3(i, int(arrayTer[i][j] * 15) - 1, j), _shader, result ? cobble : dirt));
            _modelsCube.push_back(Model(_meshes[0], glm::vec3(i, int(arrayTer[i][j] * 15) - 2, j), _shader, result ? cobble : dirt));
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