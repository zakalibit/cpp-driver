/*
  Copyright (c) DataStax, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef __CASS_PROTOCOL_HPP_INCLUDED__
#define __CASS_PROTOCOL_HPP_INCLUDED__

#include "cassandra.h"
#include "constants.hpp"

namespace cass {

inline bool is_protocol_at_least_v5_or_dse_v2(int version) {
  if (version & DSE_PROTOCOL_VERSION_BIT) {
    return version >= CASS_PROTOCOL_VERSION_DSEV2;
  } else {
    return version >= CASS_PROTOCOL_VERSION_V5;
  }
}

inline bool supports_set_keyspace(int version) {
  return is_protocol_at_least_v5_or_dse_v2(version);
}

inline bool supports_result_metadata_id(int version) {
  return is_protocol_at_least_v5_or_dse_v2(version);
}

} // namespace cass

#endif
