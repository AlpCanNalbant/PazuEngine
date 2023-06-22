cd magic_enum\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd bullet3\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd assimp\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd glad\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

@REM MinGW desteklemiyor
@REM cd DirectXTK\\build\\mingw\\%buildArch%\\%buildMode%
@REM mingw32-make install -j20
@REM cd %depsProjectsHome%

cd DirectXHelper\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd DirectXMath\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd DirectXTex\\DDSTextureLoader\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd SOIL2\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd SDL2\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd stb\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%

cd ResourceManager\\installHeader\\build\\mingw\\%buildArch%\\%buildMode%
mingw32-make install -j20
cd %depsProjectsHome%
