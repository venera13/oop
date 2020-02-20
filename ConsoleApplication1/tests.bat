set MyProgram="%~1"

REM ������ �� ������� ����� ��� ����������
if %MyProgram%=="" (
	echo Please specify path to programm
	exit /B 1
)

REM  Copy empty file
%MyProgram% empty.txt "%TEMP%\output.txt" || goto err
fc empty.txt "%TEMP%\output.txt" > nul || goto err
echo test 1 passed

REM  Copy non empty file
%MyProgram% notEmpty.txt "%TEMP%\output.txt" || goto err
fc notEmpty.txt "%TEMP%\output.txt"> nul || goto err
echo test 2 passed

REM  Copy missing file should fail
%MyProgram% none.txt "%TEMP%\output.txt" > nul && goto err
echo test 3 passed

REM  If output file is not specified, program must fail
%MyProgram% none.txt > nul && goto err
echo test 4 passed

REM  Copy not should file
%MyProgram% >nul && goto err
echo test 5 passed

REM ����� ����������� �������
echo All tests passed successfuly
exit /B 0

REM ���� �������� � ������ ������
:err
echo Test failed
exit /B 1