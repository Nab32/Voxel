# Voxel engine

A simple voxel engine fully coded in C/C++ using OpenGL.


## Install
To download the project (currently only works on windows), you'll have to follow multiple steps.

* Clone the project running the command `git clone https://github.com/Nab32/Voxel.git`
* Go into the root of the project and open the terminal
* Create necessary directories using `mkdir bin` and `mkdir build`
* Go to the build directory using `cd build`
* Run CMake to generate the Visual Studio solution using this command `cmake -G "Visual Studio 17 2022" -A Win32 -DCMAKE_BUILD_TYPE=Debug ..`
* You will have a **Visual Studio** solution inside your build folder. You will simply have to open that solution and run the builder.

The executable will be available in the bin folder.
