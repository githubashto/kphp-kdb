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

    Copyright 2012-2013 Vkontakte Ltd
              2012-2013 Arseny Smirnov
              2012-2013 Aliaksei Levin
*/

#include "vertex.h"
#include "data.h"

VertexPtr create_vertex (Operation op, VertexPtr first) {
  switch (op) {
#define FOREACH_OP(x) case x: {CREATE_VERTEX (res, x, first); return res;} break;
#include "foreach_op.h"
    default:
      kphp_fail();
  }
  return VertexPtr();
}

VertexPtr create_vertex (Operation op, VertexPtr first, VertexPtr second) {
  switch (op) {
#define FOREACH_OP(x) case x: {CREATE_VERTEX (res, x, first, second); return res;} break;
#include "foreach_op.h"
    default:
      kphp_fail();
  }
  return VertexPtr();
}

VertexPtr clone_vertex (VertexPtr from) {
  switch (from->type()) {
#define FOREACH_OP(x) case x: {CLONE_VERTEX (res, x, VertexAdaptor <x> (from)); return res;} break;
#include "foreach_op.h"
    default:
      kphp_fail();
  }
  return VertexPtr();
}
