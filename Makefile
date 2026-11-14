# 编译器使用 gcc
CC = gcc	
# -Wall 开启全部常见警告，-I 添加头文件搜索路径
CFLAGS = -Wall -Iapi/inc
# 生成的可执行文件的名称是 main
TARGET = main
# 存放生成的.o的目标文件的文件夹是build
BUILD_DIR = build

# wildcard 匹配文件，把当前文件下和api/src下的.c文件拿出来存入列表，立即赋值(:=)给SRCS
SRCS := $(wildcard *.c api/src/*.c)
# patsubst 模式替换函数，把列表里面的.c文件替换到指定文件目录下的.o文件
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

# make 不带参数时，默认执行第一个目标，习惯命名为all
all: $(BUILD_DIR)/$(TARGET)

# 指定目标可执行文件依赖的所有目标文件
$(BUILD_DIR)/$(TARGET): $(OBJS)
	# 编译器 gcc 链接所有与生成可执行文件有关的目标文件
	$(CC) $(OBJS) -o $@

# 编译前，自动创建当前 .o 所在目录
$(BUILD_DIR)/%.o: %.c
	# mkdir -p 递归创建文件夹，$(dir $@) 取出文件夹的目录部分
	@mkdir -p $(dir $@)
	# $@ 本条规则要生成的产物（目标），$< 本条规则第一个依赖文件
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
