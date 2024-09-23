@echo off
:: some scary dumb code
:: DO NOT REPEAT
set var=123
:: variable will have "var " name
set var = 321
set concat=%var% "%var %"

echo %var% "%var %"
echo %concat%

set x=1
set y=2a
set /a sum = x + y
echo %sum%

:: user input
:: set /P a="Enter value: "
:: echo %a%

:: string operations
set str=hello
echo %str:~1,2%
echo %str:~1%
echo %str:~-2%
echo %str:~1,-1%

echo %str:*l=%