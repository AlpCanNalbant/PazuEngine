cd magic_enum\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd bullet3\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd assimp\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd glad\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd DirectXTK\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd DirectXHelper\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd DirectXMath\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd DirectXTex\\DDSTextureLoader\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd SOIL2\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd SDL2\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd stb\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%

cd ResourceManager\\installHeader\\build\\msvc\\%buildArch%\\%buildMode%
MSBuild.exe INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=%buildArch%;Configuration=%buildMode%
cd %depsProjectsHome%
