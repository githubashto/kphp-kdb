/*
    This file is part of VK/KittenDB-Engine.

    VK/KittenDB-Engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    VK/KittenDB-Engine is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VK/KittenDB-Engine.  If not, see <http://www.gnu.org/licenses/>.

    This program is released under the GPL with the additional exemption 
    that compiling, linking, and/or using OpenSSL is allowed.
    You are free to remove this exemption from derived works.

    Copyright 2013 Vkontakte Ltd
              2013 Vitaliy Valtman
*/

#include "rpc-proxy/rpc-proxy.h"
#include "net-rpc-targets.h"
#include "net-rpc-server.h"
#include "net-rpc-client.h"
#include "tl-memcached-const.h"

#include <assert.h>


int memcached_forward (void) {
  return default_string_forward ();
}

SCHEMA_ADD(memcache) {
  if (C->methods.forward) {
    return -1;
  }
  C->methods.forward = memcached_forward;
  C->flags |= CF_ALLOW_STRING_FORWARD;
  return 0;
}

SCHEMA_REGISTER(memcache,0)
