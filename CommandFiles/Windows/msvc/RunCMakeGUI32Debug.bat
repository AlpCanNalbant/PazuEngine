call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32DebugHome%
cmake-gui %workspaceProjectsHome%
