# 编译要求

- cmake
- gcc 14.1.0 x86_64-w64-mingw32
- libharu

在Windows下使用vcpkg进行包管理，首先安装依赖项。

## cmake

下载地址：https://cmake.org/download/

下载最新版，按照指示安装即可。

## gcc

下载地址：https://winlibs.com/#download-release

下载后，将mingw64文件夹解压至`D:`,并将`D:\mingw64\bin`加入环境变量`$Path`

## vcpkg

```shell
git clone https://github.com/microsoft/vcpkg.git E:\dev
cd E:\dev\vcpkg;.\bootstrap-vcpkg.bat
```

将`E:\dev\vcpkg\`加入环境变量`$Path`；

```shell
vcpkg integrate install
```

进行全局集成，可以在cmake和vs项目中自动使用vcpkg中的包。
## libharu

```
vcpkg install libharu
```
# 使用方式
```shell
emf2pdf /path/to/emf
```