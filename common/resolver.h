/*
    This file is part of VK/KittenDB-Engine Library.

    VK/KittenDB-Engine Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    VK/KittenDB-Engine Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with VK/KittenDB-Engine Library.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2010-2013 Vkontakte Ltd
              2010-2013 Nikolai Durov
              2010-2013 Andrei Lopatin
*/

#ifndef __KDB_RESOLVER_H__
#define __KDB_RESOLVER_H__

#include <netdb.h>

int kdb_hosts_loaded;
int kdb_load_hosts (void);

struct hostent *kdb_gethostbyname (const char *name);

#endif
