#include "create_node.h"
void watcher(zhandle_t *zh, int type,
        int state, const char *path,void *watcherCtx){
	WatchCtx *ctx=(WatchCtx*)watcherCtx;
	cout<<"type："<<type<<"\n";
	cout<<"state: "<<state<<"\n";
	cout<<"path: "<<path<<"\n";
	ctx->type_=type;
	ctx->state_=state;
	ctx->path_=(char*)path;
		
}

void TestZoo(){
	
	const char hp[]="127.0.0.1:2181";
	WatchCtx ctx;	
	char pathbuf[80];
	int rc;
	char buff[10] = "testall";
	
	struct Stat stat_a = {0};
	
	//add znode
	zhandle_t *zk = zookeeper_init(hp, watcher, 10000, 0, &ctx, 0);
	
	
	rc = zoo_create2(zk, "/par", "like-c0", 7,
                       &ZOO_OPEN_ACL_UNSAFE, 0, pathbuf, sizeof(pathbuf), &stat_a);
	rc = zoo_create2(zk, "/par/c2", "like-c0", 7,
                       &ZOO_OPEN_ACL_UNSAFE, 0, pathbuf, sizeof(pathbuf), &stat_a);
					   
	rc = zoo_create2(zk, "/par/c5", "like-c1", 7,
                       &ZOO_OPEN_ACL_UNSAFE, 0, pathbuf, sizeof(pathbuf), &stat_a);				   
					   

	if(0==rc){
		cout<<"ZOK \n";
	}else{
		cout<<"failed \n";
	}
	
	struct String_vector strings;
    struct Stat  stat_b;
	

	//get child info
    rc = zoo_get_children2(zk, "/par", 0, &strings, &stat_b);
	cout<<"count:"<<strings.count<<"\n";
	for(int i=0;i<strings.count;i++){
		cout<<strings.data[i]<<"\n";
	}
	
	//triger watcher 
	struct Stat  stat,stat001;
	WatchCtx ctxLocal;
	
	//listen watcher
	rc = zoo_wexists(zk, "/par/c2", watcher, &ctxLocal, &stat);
	cout<<"test watcher\n";
	//trigger watcher 
	zoo_set2(zk,"/par/c2","like-c9",7,-1,&stat001);
			
}


