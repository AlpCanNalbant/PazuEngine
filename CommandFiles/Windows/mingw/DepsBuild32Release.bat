call Paths\\SetSystem32Paths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x86
set buildMode=Release
cd %depsProjectsHome%
call DepsBuild-MINGW.bat
