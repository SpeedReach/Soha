# 定義編譯器
CXX = g++

# -wall 可讓 errors 全部印出來
# 可以在這裡加優化（-01, -02...）
#CXXFLAGS = -std=c++14 -Wall 
# 可以在這裡指定版本
CXXFLAGS = -Wall -Iinclude -MP -MD

SRC_DIR=src
BUILD_DIR=build
# 執行檔名
TARGET = game

# 以 CFILES 代表所有 .cc 檔案
CFILES = $(wildcard $(SRC_DIR)/*.cc)



# 將 .cc 替換成 .o
OBJS = $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(CFILES))
DEPFILES = $(patsubst %.o,%.d,$(OBJS))

	

all: $(TARGET)

# 連結檔案（link）
# 白話文：g++ -wall -o exec *.cpp
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 編譯檔案（compile）到 build資料夾
# 代表所有 .o depend on 對應的 .cpp
# $@ = 目標文件, $< = 第一個依賴的檔案（應該可以用$^）
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPFILES)
