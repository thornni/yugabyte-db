// Copyright (c) YugaByte, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
// in compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied.  See the License for the specific language governing permissions and limitations
// under the License.
//

#ifndef YB_MASTER_YQL_PEERS_VTABLE_H
#define YB_MASTER_YQL_PEERS_VTABLE_H

#include "yb/master/master.h"
#include "yb/master/yql_virtual_table.h"

namespace yb {
namespace master {

// VTable implementation of system.peers.
class PeersVTable : public YQLVirtualTable {
 public:
  explicit PeersVTable(const Master* const master_);
  CHECKED_STATUS RetrieveData(const QLReadRequestPB& request,
                              std::unique_ptr<QLRowBlock>* vtable) const;

 protected:
  Schema CreateSchema() const;

 private:
  static constexpr const char* const kPeer = "peer";
  static constexpr const char* const kDataCenter = "data_center";
  static constexpr const char* const kHostId = "host_id";
  static constexpr const char* const kPreferredIp = "preferred_ip";
  static constexpr const char* const kRack = "rack";
  static constexpr const char* const kReleaseVersion = "release_version";
  static constexpr const char* const kRPCAddress = "rpc_address";
  static constexpr const char* const kSchemaVersion = "schema_version";
  static constexpr const char* const kTokens = "tokens";
};

}  // namespace master
}  // namespace yb
#endif // YB_MASTER_YQL_PEERS_VTABLE_H
