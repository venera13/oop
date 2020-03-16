set MyProgram="%~1"

REM Защита от запуска файла без агрументов
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM Шифрование строки
%MyProgram% crypt string.txt crypt_output.txt 52 || goto err
echo test 1 passed

REM Дешифрование строки
%MyProgram% decrypt crypt_output.txt decrypt_output.txt 52 || goto err
echo test 2 passed

REM Тесты завершились успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1