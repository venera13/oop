set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM ���������� ������
%MyProgram% crypt string.txt crypt_output.txt 52 || goto err
echo test 1 passed

REM ������������ ������
%MyProgram% decrypt crypt_output.txt decrypt_output.txt 52 || goto err
echo test 2 passed

REM ����� ����������� �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1