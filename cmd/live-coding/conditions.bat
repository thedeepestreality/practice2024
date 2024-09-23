@echo off

if "%1" EQU "" (
	echo Missing argument 1
	goto exit
)

if exist %1 (
	echo File %1 already exists
) else (
	echo File %1 does not exist
	echo 1 > %1
)

:: EQU ==
:: NEQ !=
:: LSS <
:: LEQ <=
:: GTR >
:: GEQ >=
:: NOT

echo %ERRORLEVEL%
if %ERRORLEVEL%==0 (
	echo Uspeh
) else (
	echo Not uspeh
)

if /I sTr1 EQU str1 (
	echo Equal strings
) else (
	echo Not equal strings
)

:exit
