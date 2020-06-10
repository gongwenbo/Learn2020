#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <unistd.h>
#include <cstddef>
#include <memory>

#include <uv.h>
#define DEFAULT_BACKLOG 128

using namespace std;

typedef struct {
    uv_write_t req;
    uv_buf_t buf;
} write_req_t;
