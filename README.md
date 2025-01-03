# 数据备份软件
## 项目简介

- 软件开发综合实验课设：Qt图形化界面，C++开发的一款数据备份软件。
- 实现文件本地的加密压缩存储和还原，以及定时备份并支持多文件。
- 实现功能：

  - [ ] 10 支持windows软链接（快捷方式）
  - [x] 10 支持元数据
  - [x] 5 自定义备份（调用windows api，支持文件根据路径/类型/名字/时间/尺寸筛选）
  - [x] 10 打包解压（支持多文件）
  - [x] 10 压缩解压
  - [x] 10 加密解压
  - [x] 10 图形界面
  - [x] 10 定时备份
  - [ ] 15 实时备份
  - [ ] 30 网络备份

## 环境

- OS：Windows
- 开发：Visual Studio 2022, CMake, C++
- 依赖：[<u>OpenSSL</u>](http://slproweb.com/products/Win32OpenSSL.html)、[<u>Qt6及以上版本</u>](https://download.qt.io/archive/qt/)

## 运行

> [!CAUTION]
>
> 在build之前需要确保安装CMake, OpenSSL, Qt6

提供了build.bat，windows用户直接双击运行。

或者也可以依次执行：

```bat
cd build
cmake ..
cmake --build .
```





