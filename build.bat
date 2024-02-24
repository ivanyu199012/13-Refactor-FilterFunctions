cls

@echo [101mg++ %* -std=c++17 -o gout.exe [0m
@g++ %* -std=c++17 -o gout.exe

@IF %ERRORLEVEL% EQU 0 (
	echo [37;4m[ g++ compiling success !! run gout.exe ][0m
  	gout.exe
) ELSE (
	echo [37;4m[ Error !!, g++ fail to compile. ][0m
)
