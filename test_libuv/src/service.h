#pragma once
#include "common.h"

class Server{
	public:
		Server(){
			loop = uv_default_loop();
		};
		void SServer(string ip,int port);
		static void on_new_connection(uv_stream_t *server, int status);
		static void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);
		static void echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf);
		static void on_close(uv_handle_t* handle);
		static void echo_write(uv_write_t *req, int status);
		static void free_write_req(uv_write_t *req)	;

	public:
		static struct sockaddr_in addr;
		static uv_tcp_t server;
		static uv_loop_t* loop;
				
};

