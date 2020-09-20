#pragma once 
class UdpSer{
	public:
		UdpSer(string ip,int port){
			char* ip_addr=ip.c_str();
			

		}
		void UdpRecieve(){
			loop = uv_default_loop();			
			uv_udp_init(loop, &recv_socket);
			struct sockaddr_in recv_addr;
			uv_ip4_addr("0.0.0.0", 68, &recv_addr);
			uv_udp_bind(&recv_socket, (const struct sockaddr *)&recv_addr, UV_UDP_REUSEADDR);
			uv_udp_recv_start(&recv_socket, alloc_buffer, on_read);
			uv_run(loop, UV_RUN_DEFAULT);
			return uv_run(loop, UV_RUN_DEFAULT);
						
		}
		static void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
			buf->base = malloc(suggested_size);
			buf->len = suggested_size;
		}
		static void on_read(uv_udp_t *req, ssize_t nread, const uv_buf_t *buf, const struct sockaddr *addr, unsigned flags) {
			if (nread < 0) {
				fprintf(stderr, "Read error %s\n", uv_err_name(nread));
				uv_close((uv_handle_t*) req, NULL);
				free(buf->base);
				return;
			}
			
			char sender[17] = { 0 };
			uv_ip4_name((const struct sockaddr_in*) addr, sender, 16);
			fprintf(stderr, "Recv from %s\n", sender);
			
			// ... DHCP specific code
			unsigned int *as_integer = (unsigned int*)buf->base;
			unsigned int ipbin = ntohl(as_integer[4]);
			unsigned char ip[4] = {0};
			int i;
			for (i = 0; i < 4; i++)
				ip[i] = (ipbin >> i*8) & 0xff;
			fprintf(stderr, "Offered IP %d.%d.%d.%d\n", ip[3], ip[2], ip[1], ip[0]);
			
			free(buf->base);
			uv_udp_recv_stop(req);
		}
	public:
		static uv_loop_t *loop;
		struct sockaddr_in recv_addr;
		
}