call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64ReleaseHome%
cmake-gui %workspaceProjectsHome%
