call Paths\\SetSystem64Paths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64DebugHome%
cmake-gui %workspaceProjectsHome%
