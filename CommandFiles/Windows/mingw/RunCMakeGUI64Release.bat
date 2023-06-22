call Paths\\SetSystem64Paths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64ReleaseHome%
cmake-gui %workspaceProjectsHome%
