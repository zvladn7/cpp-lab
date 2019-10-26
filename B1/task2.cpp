#include "tasks.hpp"
#include <fstream>
#include <vector>
#include <memory>

const std::size_t initSize = 1024;

void secondTask(const std::string &filename) {
  using charsArr = std::unique_ptr<char[], decltype(&free)>;

  std::ifstream inputFile(filename);
  if (!inputFile) {
   throw std::invalid_argument("File doesn't exist or you've just typed the wrong name of it!\n");
  }
  std::size_t size = initSize;

  charsArr c_array(static_cast<char *>(malloc(size)), &free);
  if (!c_array) {
    throw std::runtime_error("Memory couldn't be allocated!\n");
  }
  std::size_t count = 0;
  while (inputFile) {
    inputFile.read(&c_array[count], initSize);
    count += inputFile.gcount();
    if (inputFile.gcount() == initSize) {
      size += initSize;
      charsArr tmp_c_array(static_cast<char *>(realloc(c_array.get(),size)), &free);
      if (!tmp_c_array) {
        throw std::runtime_error("Memory couldn't be allocated for new chars sequence!\n");
      }
      c_array.release();
      std::swap(tmp_c_array, c_array);
    }
    if (!inputFile.eof() && inputFile.fail()) {
      throw std::runtime_error("Reading was failed!\n");
    }
  }

  std::vector<char> vector(&c_array[0], &c_array[count]);
  for (const auto& it: vector) {
    std::cout << it;
  }
}
