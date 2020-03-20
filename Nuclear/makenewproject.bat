@echo off

REM ********************************************************************
REM
REM newproject.bat
REM
REM This windows batch script generates a set of gameplay project files.
REM The new project will be based of the template project and 
REM it will be generated with the name and location that is specified
REM as input parameters.
REM
REM IMPORTANT: This script must be run from the root of the gameplay
REM source tree.
REM
REM ********************************************************************

echo.
echo 1. Enter a name for the new project.
echo.
echo    This name will be given to the project 
echo    executable and a folder with this name
echo    will be created to store all project files.
echo    Ex. foobar
echo.
set /p projName=Project name: 
if "%projName%" == "" (
    echo.
    echo ERROR: No project name specified.
    echo.
    pause
    goto done
)
echo.

echo.
echo 2. Enter a game title.
echo.
echo    On some platforms, this title is used to
echo    identify the game during installation and
echo    on shortcuts/icons.
echo    Ex. Foo Bar
echo.
set /p title=Title: 
if "%title%" == "" (
    echo.
    echo ERROR: No game title specified.
    echo.
    pause
    goto done
)
echo.

echo.
echo 3. Enter a unique identifier for your project.
echo.
echo    This should be a human readable package name,
echo    containing at least two words separated by a
echo    period.
echo    Ex. com.example.foobar
echo.
set /p uuid=Unique ID: 
if "%uuid%" == "" (
    echo.
    echo ERROR: No uuid specified.
    echo.
    pause
    goto done
)
echo.

echo.
echo 4. Enter your game's main class name.
echo.
echo    Your initial game header and source file
echo    will be given this name and a class with 
echo    this name will be created in these files.
echo    Ex. FooBarGame
echo.
set /p className=Class name: 
if "%className%" == "" (
    echo.
    echo ERROR: No class name specified.
    echo.
    pause
    goto done
)
echo.

echo.
echo 5. Enter the project path.
echo.
echo    This can be a relative path, absolute path,
echo    or empty for the current folder. Note that
echo    a project folder named %projName% will also
echo    be created inside this folder.
echo    Ex. ./samples
echo.
set /p location=Path: 
if "%location%" == "" (
    set projPath=%projName%
) else (
    set projPath=%location%\%projName%
)
echo.

call:replacevar projPath "/" "\"

REM Does this path already exist?
if exist "%projPath%" (
    echo.
    echo ERROR: Path '%projPath%' already exists, aborting.
    echo.
    pause
    goto done

REM Disabling following code which prompts to overwrite existing path,
REM since this could be potentially damaging if the user specifies
REM an important path and then types 'y', without thinking.
REM
REM    set /p owd=Directory '%projPath%' exists, overwrite [Y,N]? 
REM    if not "!owd!" == "Y" (
REM        if not "!owd!" == "y" (
REM            echo Aborting.
REM            pause
REM            goto done
REM        )
REM    )
REM    rmdir /S /Q %projPath%
)


:done
