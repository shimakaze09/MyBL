//
// Created by Admin on 26/02/2025.
//

#pragma once

#include <array>
#include <vector>

namespace My {
template <typename T>
class Pool {
 public:
  Pool() = default;
  Pool(Pool&& pool) noexcept;
  ~Pool();

  template <typename... Args>
  T* Request(Args&&... args);
  void Recycle(T* object);
  void Reserve(size_t n);
  void Clear();

 private:
  void NewBlock();

 private:
  static const size_t BLOCK_SIZE = 1024;
  using Block = std::array<T, BLOCK_SIZE>;

  std::vector<Block*> blocks;
  std::vector<T*> freeAdresses;
};
}  // namespace My

#include "detail/Pool.inl"
