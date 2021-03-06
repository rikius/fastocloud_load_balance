/*  Copyright (C) 2014-2020 FastoGT. All right reserved.
    This file is part of fastocloud.
    fastocloud is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    fastocloud is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with fastocloud.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "subscribers/server.h"

#include "subscribers/client.h"

#include <common/text_decoders/none_edcoder.h>

namespace fastocloud {
namespace server {
namespace subscribers {

SubscribersServer::SubscribersServer(const common::net::HostAndPort& host,
                                     CompressedType compressed,
                                     common::libev::IoLoopObserver* observer)
    : base_class(host, false, observer), compressed_(compressed) {}

common::libev::tcp::TcpClient* SubscribersServer::CreateClient(const common::net::socket_info& info) {
  if (compressed_ == C_STANDART) {
    return new SubscriberClient(this, info, std::make_shared<fastotv::protocol::FastoTVCompressor>());
  }
  return new SubscriberClient(this, info, std::make_shared<common::NoneEDcoder>());
}

}  // namespace subscribers
}  // namespace server
}  // namespace fastocloud
