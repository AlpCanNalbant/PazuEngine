call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x86
set buildMode=Debug
cd %depsProjectsHome%
call DepsRebuild-MSVC.bat
