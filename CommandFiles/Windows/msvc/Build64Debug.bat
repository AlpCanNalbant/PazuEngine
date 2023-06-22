call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64DebugHome%
MSBuild INSTALL.vcxproj /t:build /p:Platform=x64;Configuration=Debug
