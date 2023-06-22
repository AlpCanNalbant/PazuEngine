call Paths\\SetSystem64Paths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x64
set buildMode=Release
cd %depsProjectsHome%
call DepsClean-MINGW.bat