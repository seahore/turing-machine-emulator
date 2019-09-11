# 图灵机模拟器 C++实现 Turing Machine Simulator on C++

[![Build Status](http://img.shields.io/travis/seahore/turing-machine-sim/master.svg?style=flat)](https://travis-ci.org/seahore/turing-machine-sim)

武汉大学计算机导论课作业

## 主程序

代码均在根目录下，入口在`main.cpp`

## 演示代码

在demo目录下：

### 加一指令 x+1

可以对任意长度二进制数加一，需要在首位加入0防止溢出。

图灵机初状态为0，初始位置在最后一位。

#### e1.

`TAPE INPUT: 010`

`TAPE OUTPUT: 011`

#### e2.

`TAPE INPUT: 0111`

`TAPE OUTPUT: 1000`

### 四位加法器 4-bit-adder

可以进行四位二进制数的加法。和可以高至五位。

被加数在加号左侧，加数在加号右侧，结果显示在加号左侧；图灵机初状态为255，初始位置在最后一位。详见`description.txt`

#### e1.

`TAPE INPUT: 0010+0101B`

`TAPE OUTPUT: 0111+aaaaB`

#### e2.

`TAPE INPUT: 01111+0001B`

`TAPE OUTPUT: 10000+aaaaB`
