call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32ReleaseHome%
cmake-gui %workspaceProjectsHome%
