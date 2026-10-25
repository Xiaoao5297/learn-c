# 教程示例代码的统一构建入口。
#
# 用法：
#   make -C examples          # 编译全部示例到 examples/build/
#   make -C examples clean    # 清理编译产物
#   make -C examples list     # 列出所有可执行文件路径

CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra
LDLIBS ?= -lm

SRCS := $(shell find . -name '*.c' -not -path './build/*' | sort)
BINS := $(patsubst ./%.c,build/%,$(SRCS))

.PHONY: all clean list verify

all: $(BINS)

build/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -rf build

list:
	@printf '%s\n' $(BINS)

verify:
	python3 ../scripts/verify_examples.py
