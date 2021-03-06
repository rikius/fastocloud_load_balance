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

#include "http/client.h"

namespace fastocloud {
namespace server {
namespace http {

HttpClient::HttpClient(common::libev::IoLoop* server, const common::net::socket_info& info)
    : base_class(server, info), is_verified_(false) {}

bool HttpClient::IsVerified() const {
  return is_verified_;
}

void HttpClient::SetVerified(bool verified) {
  is_verified_ = verified;
}

common::Optional<base::FrontSubscriberInfo> HttpClient::MakeFrontSubscriberInfo() const {
  const auto login = GetLogin();
  if (!login) {
    return common::Optional<base::FrontSubscriberInfo>();
  }

  return base::FrontSubscriberInfo(login->GetUserID(), login->GetLogin(), login->GetDeviceID(),
                                   login->GetExpiredDate());
}

common::ErrnoError HttpClient::SendNotification(const fastotv::commands_info::NotificationTextInfo& notify) {
  UNUSED(notify);
  return common::make_errno_error("Send notification for http not supported", ENOENT);
}

const char* HttpClient::ClassName() const {
  return "HttpClient";
}

}  // namespace http
}  // namespace server
}  // namespace fastocloud
