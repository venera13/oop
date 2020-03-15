set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM ����� �����
%MyProgram% 6 > %TEMP%\integer_output_file.txt || goto err
fc integer_test.txt "%TEMP%\integer_output_file.txt" > nul || goto err
echo test 1 passed

REM ����� 255
%MyProgram% 255 > %TEMP%\last_eight_bit_integer_output_file.txt || goto err
fc last_eight_bit_integer_test.txt "%TEMP%\last_eight_bit_integer_output_file.txt" > nul || goto err
echo test 2 passed

REM Float number
%MyProgram% 15.4 > %TEMP%\float_number_output_file.txt || goto err
fc float_number_test.txt "%TEMP%\float_number_output_file.txt" > nul || goto err
echo test 3 passed

REM ������������� �����
%MyProgram% -5 && goto err
echo test 4 passed

REM ����� ������ 255
%MyProgram% 300 && goto err
echo test 5 passed

REM ������
%MyProgram% abc && goto err
echo test 6 passed

REM ������ ��������
%MyProgram% && goto err
echo test 7 passed

REM ����� ����������� �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1