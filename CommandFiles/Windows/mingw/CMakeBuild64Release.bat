call Paths\\SetSystem64Paths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64ReleaseHome%
cmake %workspaceProjectsHome% -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release