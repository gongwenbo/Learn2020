#include "common.h"
typedef struct watchcontex{
	int type_;
	int state_;
	char *path_;
}WatchCtx;
	
void watcher(zhandle_t *zh, int type,
        int state, const char *path,void *watcherCtx);

void TestZoo();