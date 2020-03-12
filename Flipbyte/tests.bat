set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM ����� �����
%MyProgram% 6 > %TEMP%\first_output.txt || goto err
fc first_test.txt "%TEMP%\first_output.txt" > nul || goto err
echo test 1 passed

REM ����� 255
%MyProgram% 255 > %TEMP%\second_output.txt || goto err
fc second_test.txt "%TEMP%\second_output.txt" > nul || goto err
echo test 2 passed

REM Float
%MyProgram% 15.4 || goto err
%MyProgram% 15.4 > %TEMP%\third_output.txt || goto err
fc third_test.txt "%TEMP%\third_output.txt" > nul || goto err
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