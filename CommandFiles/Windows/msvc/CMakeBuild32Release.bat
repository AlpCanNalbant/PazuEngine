call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32ReleaseHome%
cmake %workspaceProjectsHome% -G "Visual Studio 17 2022" -A win32 -Thost=x86 -DCMAKE_BUILD_TYPE=Release
