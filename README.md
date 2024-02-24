<!-- omit in toc -->
# Refactor-Filter Example

<!-- omit in toc -->
## Blog
[Electron + Django, package it to production](https://ivanyu2021.hashnode.dev/electron-django-package-it-to-production)

<!-- omit in toc -->
- [Requirements](#requirements)
- [Installation](#installation)
- [Package](#package)
- [Run](#run)

## Requirements
- Python 3.9.10
- Virtualenv 20.13.1
- Node js 14.18.3

## Installation
```cmd
npm install

cd python
virtualenv edtwExampleEnv
edtwExampleEnv\Scripts\activate

cd edtwExample
pip install -r requirements.txt
```
## Package

```cmd
REM Back to python folder
cd ..
pyinstaller --name=edtwExample edtwExample\manage.py --noconfirm

REM Back to root folder
cd ..
npm run package
```

## Run
```
cd out\edtwexample-win32-x64
edtwexample.exe
```