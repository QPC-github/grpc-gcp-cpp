// Copyright 2022 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Copyright 2017 The CRC32C Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef CRC32C_CRC32C_READ_LE_H_
#define CRC32C_CRC32C_READ_LE_H_

#include <cstdint>
#include <cstring>

#include "./crc32c_config.h"

namespace crc32c {

// Reads a little-endian 32-bit integer from a 32-bit-aligned buffer.
inline uint32_t ReadUint32LE(const uint8_t* buffer) {
#if BYTE_ORDER_BIG_ENDIAN
  return ((static_cast<uint32_t>(static_cast<uint8_t>(buffer[0]))) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[1])) << 8) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[2])) << 16) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[3])) << 24));
#else   // !BYTE_ORDER_BIG_ENDIAN
  uint32_t result;
  // This should be optimized to a single instruction.
  std::memcpy(&result, buffer, sizeof(result));
  return result;
#endif  // BYTE_ORDER_BIG_ENDIAN
}

// Reads a little-endian 64-bit integer from a 64-bit-aligned buffer.
inline uint64_t ReadUint64LE(const uint8_t* buffer) {
#if BYTE_ORDER_BIG_ENDIAN
  return ((static_cast<uint32_t>(static_cast<uint8_t>(buffer[0]))) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[1])) << 8) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[2])) << 16) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[3])) << 24) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[4])) << 32) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[5])) << 40) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[6])) << 48) |
          (static_cast<uint32_t>(static_cast<uint8_t>(buffer[7])) << 56));
#else   // !BYTE_ORDER_BIG_ENDIAN
  uint64_t result;
  // This should be optimized to a single instruction.
  std::memcpy(&result, buffer, sizeof(result));
  return result;
#endif  // BYTE_ORDER_BIG_ENDIAN
}

}  // namespace crc32c

#endif  // CRC32C_CRC32C_READ_LE_H_
