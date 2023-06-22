call Paths\\SetSystem32Paths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32DebugHome%
cmake %workspaceProjectsHome% -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug