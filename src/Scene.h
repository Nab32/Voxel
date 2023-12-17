#pragma once
#include <iostream>
#include "Shader.h"
#include "Mesh.h"
#include "Model.h"
#include <vector>
#include <unordered_map>
#include <noise/noise.h>
#include "Textures.h"

class Scene {
public:
	Scene(Shader* shader);
	void createCube();
	void generateModels();   //IMPLEMENTATION OF CHUNKS LATER
	std::vector<Model> getModels();
	double** generateNoise();
private:
	int currentMesh;
	Shader* _shader;
	std::vector<Mesh*> _meshes;
	std::vector<Model> _modelsCube;
};