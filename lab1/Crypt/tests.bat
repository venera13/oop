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
fc string.txt decrypt_output.txt > nul || goto err
echo test 2 passed

REM Шифрование строки c key 0
%MyProgram% crypt string.txt crypt_with_key_null_output.txt 0 || goto err
echo test 3 passed

REM Дешифрование строки c key 0
%MyProgram% decrypt crypt_with_key_null_output.txt decrypt_with_key_null_output.txt 0 || goto err
fc string.txt decrypt_with_key_null_output.txt > nul || goto err
echo test 4 passed

REM Шифрование строки c key 255
%MyProgram% crypt string.txt crypt_with_last_key_output.txt 255 || goto err
echo test 5 passed

REM Дешифрование строки c key 0
%MyProgram% decrypt crypt_with_last_key_output.txt decrypt_with_last_key_output.txt 255 || goto err
fc string.txt decrypt_with_last_key_output.txt > nul || goto err
echo test 6 passed

REM Шифрование строки c невалидным ключем
%MyProgram% crypt string.txt crypt_with_last_key_output.txt 300 && goto err
echo test 7 passed

REM Шифрование строки c невалидным типом шифрования
%MyProgram% null string.txt crypt_with_last_key_output.txt 1 && goto err
echo test 8 passed

REM Шифрование пустого файла
%MyProgram% crypt empty.txt crypt_empty_file_output.txt 1 || goto err
echo test 9 passed

REM Шифрование несуществующего файла
%MyProgram% crypt none.txt crypt_none_file_output.txt 1 && goto err
echo test 10 passed

REM Тесты завершились успешно
echo All tests passed successfuly
exit /B 0

REM Сюда попадаем в случае ошибки
:err
echo Test failed
exit /B 1