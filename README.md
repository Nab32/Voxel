# Voxel engine

A simple voxel engine fully coded in C/C++ using OpenGL. The game currently generates a random 128x128 world every 5 seconds to showcase the noise generation algorithm.


## Install
To download the project (currently only works on windows), you'll have to follow multiple steps.

* Clone the project running the command `git clone https://github.com/Nab32/Voxel.git`
* Go into the root of the project and open the terminal
* Create necessary directories using `mkdir bin` and `mkdir build`
* Go to the build directory using `cd build`
* Run CMake to generate the Visual Studio solution using this command `cmake -G "Visual Studio 17 2022" -A Win32 ..`
* You will have a **Visual Studio** solution inside your build folder. You will simply have to open that solution and run the builder.

The executable will be available in the bin folder.

## Images
![voxel_img2](https://github.com/Nab32/Voxel/assets/90017423/51247212-8291-4a7a-a349-92314a3fb63a)
![voxel_img1](https://github.com/Nab32/Voxel/assets/90017423/1ff1b5e4-28e0-4350-bb16-6aacac0b5550)

