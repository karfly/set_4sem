CHCP 1251>nul
set f1= "C:\Users\Егор\Set\set_4sem\Yegor\test.c"
set f2= "C:\Users\Егор\Set\set_4sem\Yegor\set.c"
set fout= "C:\Users\Егор\Set\set_4sem\Yegor\test.exe"

set Compiler_dir= "C:\Program Files (x86)\CodeBlocks\MinGW\bin\"
cd %Compiler_dir%
set Compiler= "mingw32-gcc.exe"
cls
%Compiler% %f1% %f2% -o %fout%
pause
cls
%fout%
