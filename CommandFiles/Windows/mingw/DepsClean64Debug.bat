call Paths\\SetSystem64Paths.bat
call Paths\\SetCommonPaths.bat
set buildArch=x64
set buildMode=Debug
cd %depsProjectsHome%
call DepsClean-MINGW.bat
:: Tehlikeli ve seytani bunlari kullanma!
:: cd %depsLib64DebugHome%
:: del /q .\\*
:: cd %depsBin64DebugHome%
:: del /q .\\*.dll
:: cd %depsIncludeHome%
:: call %commandsHome%\\Paths\\CleanCurrentFolder.bat
