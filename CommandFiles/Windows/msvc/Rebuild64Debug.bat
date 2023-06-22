call Paths\\SetSystemPaths.bat
call Paths\\SetCommonPaths.bat
cd %workspaceCMakeBuild64DebugHome%
MSBuild INSTALL.vcxproj /t:rebuild /p:Platform=x64;Configuration=Debug
