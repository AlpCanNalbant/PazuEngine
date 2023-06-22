call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64ReleaseHome%
MSBuild INSTALL.vcxproj /t:clean /p:Platform=x64;Configuration=Release
