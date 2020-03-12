set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM Empty file
%MyProgram% empty.txt && goto err
echo test 1 passed

REM Null matrix
%MyProgram% not_empty.txt || goto err
echo test 2 passed

REM  Copy missing file should fail
%MyProgram% none.txt && goto err
echo test 3 passed

REM Matrix
%MyProgram% matrix.txt || goto err
echo test 4 passed

REM Matrix
%MyProgram% not_empty.txt || goto err
echo test 5 passed

REM ����� ����������� �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1