call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32ReleaseHome%
MSBuild INSTALL.vcxproj /t:rebuild /m:20 /p:Platform=x86;Configuration=Release
