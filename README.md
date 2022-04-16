# 1 运行代码
进入到 src 文件中，输入以下命令：

> make all

即可完成代码编译，并且在终端中输出结果。

# 2 结构说明

- bin/ 用来存放编译后的文件
- data/ 用来存放生成的数据集
- src/ 用来存放代码文件
- include/ 用来存放代码的头文件
- test/ 用来存放测试函数正确与否的测试用例

# 3 参数设计

- 如果你想要自定义数据流的大小，请修改 include/def.h 中的 STREAM_LENGTH 参数，并重新编译。
- 如果你想要自定义窗口的大小，请修改 include/def.h 中的 WINDOW_SIZE 参数，并重新编译。
- 如果你想要自定义查询长度，请修改 include/def.h 中的 QUERY_LENGTH 参数，并重新编译。
