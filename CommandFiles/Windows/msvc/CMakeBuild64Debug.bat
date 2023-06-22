call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64DebugHome%
cmake %workspaceProjectsHome% -G "Visual Studio 17 2022" -A x64 -Thost=x64 -DCMAKE_BUILD_TYPE=Debug
