@ echo off
rem ����MinGW�Ļ�������
set VSPath=C:\Program Files (x86)\Microsoft Visual Studio 12.0
set m_bin=%VSPath%\vc\bin
set m_include=%VSPath%\vc\include;c:\windows
set m_lib=%VSPath%\vc\lib
set m_IDE=%VSPath%\Common7\IDE

rem ��ӻ�����������ʱ��path
set path=%path%;%m_bin%;%m_include%;%m_lib%;%m_IDE%

rem ����VS2010
@set _pf=%ProgramFiles%
@if not "[%ProgramFiles(x86)%]"=="[]" set _pf=%ProgramFiles(x86)%
call "%_pf%\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86_amd64
@set _pf=


echo ����������ӳɹ�
title Test - ACE Environment
color 17
rem C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\vsvars32.bat
cmd


rem pause