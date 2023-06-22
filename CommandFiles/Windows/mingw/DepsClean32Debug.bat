call Paths\\SetSystem32Paths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x86
set buildMode=Debug
cd %depsProjectsHome%
call DepsClean-MINGW.bat
