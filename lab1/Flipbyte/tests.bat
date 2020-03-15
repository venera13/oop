set MyProgram="%~1"

REM Защита от запуска файла без агрументов
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM Целое число
%MyProgram% 6 > %TEMP%\integer_output_file.txt || goto err
fc integer_test.txt "%TEMP%\integer_output_file.txt" > nul || goto err
echo test 1 passed

REM Число 255
%MyProgram% 255 > %TEMP%\last_eight_bit_integer_output_file.txt || goto err
fc last_eight_bit_integer_test.txt "%TEMP%\last_eight_bit_integer_output_file.txt" > nul || goto err
echo test 2 passed

REM Float number
%MyProgram% 15.4 > %TEMP%\float_number_output_file.txt || goto err
fc float_number_test.txt "%TEMP%\float_number_output_file.txt" > nul || goto err
echo test 3 passed

REM Отрицательное число
%MyProgram% -5 && goto err
echo test 4 passed

REM Число больше 255
%MyProgram% 300 && goto err
echo test 5 passed

REM Строка
%MyProgram% abc && goto err
echo test 6 passed

REM Пустой параметр
%MyProgram% && goto err
echo test 7 passed

REM Тесты завершились успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1