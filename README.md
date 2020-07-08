这是Unix网络编程卷I（第三版）的读书笔记，代码注释。所有源码。源码请到[unpv13e](https://github.com/unpbook/unpv13e)

# 编译前的工作
需要在源码 `./libfree/inet_ntop.c`定义的最后一行加入这个宏定义
```c
#define size_t socklen_t 
```
之后按照官方readme的步骤编译就好了

碰到`if_dl.h`不存在，不需要理会。之后的编译也不需要。
编译完之后生成libunp.a在源码的根目录下，可以拷贝到/usr/include 目录。
或者在`.bashrc`加入下面环境变量。
```sh
export UNIX_NET_CODE={you_path}/Documents/unpv13e
# C
export C_INCLUDE_PATH=$UNIX_NET_CODE/lib:$C_INCLUDE_PATH
# CPP
export CPLUS_INCLUDE_PATH=$UNIX_NET_CODE/lib:$CPLUS_INCLUDE_PATH

# 动态链接库搜索路径：
export LD_LIBRARY_PATH=$UNIX_NET_CODE:$LD_LIBRARY_PATH
# 静态链接库搜索路径：
export LIBRARY_PATH=$UNIX_NET_CODE:$LIBRARY_PATH
```

# 编译完之后

自己的代码使用`gcc c1.5.c -lunp -o run.out`编译即可

## vsocde 远端编译调试配置
- 在`tasks.json`修改args参数
```json
[
    "-g",
    "${file}",
    "-l",
    "unp",
    "-o",
    "${fileDirname}/run.out"
]
```

- 在`launch.json`修改
```json
"program": "${fileDirname}/run.out",
```
启动参数请根据实际代码需求添加