call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x64
set buildMode=Release
cd %depsProjectsHome%
call DepsClean-MSVC.bat
