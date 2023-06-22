call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild32ReleaseHome%
MSBuild INSTALL.vcxproj /t:clean /p:Platform=x86;Configuration=Release
