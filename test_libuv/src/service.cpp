#include "service.h"

uv_loop_t* Server::loop = uv_default_loop();
struct sockaddr_in add;
struct sockaddr_in Server::addr=add;
uv_tcp_t se;
uv_tcp_t Server::server=se;


void Server::SServer(string ip,int port){
	const char* ip_=ip.c_str();
	cout<<ip_<<"asdf\n";
	
	uv_tcp_init(loop, &server);
	uv_ip4_addr(ip_, port, &addr);
	uv_tcp_bind(&server, (const struct sockaddr*)&addr, 0);
	int r = uv_listen((uv_stream_t*) &server, DEFAULT_BACKLOG,on_new_connection);
	if (r) {
		fprintf(stderr, "Listen error %s\n", uv_strerror(r));
	}
	uv_run(loop, UV_RUN_DEFAULT);
}
void Server::on_new_connection(uv_stream_t *server, int status) {
	if (status < 0) {
		fprintf(stderr, "New connection error %s\n", uv_strerror(status));
		return;
	}

	uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
	uv_tcp_init(loop, client);
	if (uv_accept(server, (uv_stream_t*) client) == 0) {
		uv_read_start((uv_stream_t*) client, alloc_buffer, echo_read);
	}
	else {
		uv_close((uv_handle_t*) client, on_close);
	}
}

void Server::on_close(uv_handle_t* handle) {
    free(handle);
}

void Server::echo_write(uv_write_t *req, int status) {
    if (status) {
        fprintf(stderr, "Write error %s\n", uv_strerror(status));
    }
    free_write_req(req);
}

void Server::free_write_req(uv_write_t *req) {
    write_req_t *wr = (write_req_t*) req;
    free(wr->buf.base);
    free(wr);
}

void Server::alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
	buf->base = (char*) malloc(suggested_size);
	buf->len = suggested_size;
}
void Server::echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
	if (nread > 0) {
		write_req_t *req = (write_req_t*) malloc(sizeof(write_req_t));
		cout<<"server recieve data："<<buf->base<<"\n";
		req->buf = uv_buf_init(buf->base, nread);
		uv_write((uv_write_t*) req, client, &req->buf, 1, echo_write);
		return;
	}
	if (nread < 0) {
		if (nread != UV_EOF)
			fprintf(stderr, "Read error %s\n", uv_err_name(nread));
		uv_close((uv_handle_t*) client, on_close);
	}

	free(buf->base);
}

