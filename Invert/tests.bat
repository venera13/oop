set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM  Matrix
%MyProgram% matrix.txt || goto err
echo test 1 passed

REM ����� ����������� �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1