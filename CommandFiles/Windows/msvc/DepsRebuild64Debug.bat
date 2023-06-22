call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x64
set buildMode=Debug
cd %depsProjectsHome%
call DepsBuild-MSVC.bat
