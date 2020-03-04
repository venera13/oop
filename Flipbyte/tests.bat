set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM ����� �����
%MyProgram% 6 || goto err
echo test 1 passed

REM ����
%MyProgram% 0 || goto err
echo test 2 passed

REM ����� 255
%MyProgram% 255 || goto err
echo test 3 passed

REM ������������� �����
%MyProgram% -5 && goto err
echo test 4 passed

REM ����� ������ 255
%MyProgram% 300 && goto err
echo test 5 passed

REM Float
%MyProgram% 15.4 && goto err
echo test 6 passed

REM ������
%MyProgram% abc && goto err
echo test 7 passed

REM ������ ��������
%MyProgram% && goto err
echo test 8 passed

REM ����� ����������� �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1