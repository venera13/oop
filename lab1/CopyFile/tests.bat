set MyProgram="%~1"

REM Защита от запуска файла без агрументов
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM  Copy file
%MyProgram% input.txt "%TEMP%\tests\output.txt" || goto err
fc input.txt "%TEMP%\tests\output.txt" > nul || goto err
echo test 1 passed

REM  Copy empty file
%MyProgram% empty.txt "%TEMP%\tests\empty.txt" || goto err
fc empty.txt "%TEMP%\tests\empty.txt" > nul || goto err
echo test 2 passed

REM  Copy non empty file
%MyProgram% notEmpty.txt "%TEMP%\tests\NonEmptyOutput.txt" || goto err
fc notEmpty.txt "%TEMP%\tests\NonEmptyOutput.txt" > nul || goto err
echo test 3 passed

REM  Copy missing file should fail
%MyProgram% none.txt "%TEMP%\output.txt" > nul && goto err
echo test 4 passed

REM  If output file is not specified, program must fail
%MyProgram% none.txt > nul && goto err
echo test 5 passed

REM  Copy not should file
%MyProgram% >nul && goto err
echo test 6 passed

REM Тесты завершились успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1