call Paths\\SetSystem32Paths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32DebugHome%
cmake-gui %workspaceProjectsHome%
