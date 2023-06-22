call Paths\\SetSystem64Paths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x64
set buildMode=Debug
cd %depsProjectsHome%
call DepsBuild-MINGW.bat
