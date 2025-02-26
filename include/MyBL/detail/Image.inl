//
// Created by Admin on 26/02/2025.
//

#pragma once

namespace My {
template <typename T, typename>
T& Image::At(size_t x, size_t y) {
  assert(T::N == channel);
  return reinterpret_cast<T&>(At(x, y, 0));
}

template <typename T, typename>
void Image::SetAll(const T& color) {
  if constexpr (std::is_same_v<T, float>) {
    for (size_t i = 0; i < width * height * channel; i++)
      data[i] = color;
  } else {
    for (size_t j = 0; j < height; j++) {
      for (size_t i = 0; i < width; i++) {
        At<T>(i, j) = color;
      }
    }
  }
}
}  // namespace My
