#ifndef THREAD_CACHE_H
#define THREAD_CACHE_H

#include "common.h"

class ThreadCache
{
public:
	// 申请和释放内存对象
	void* Allocate(size_t size);

	void Deallocate(void* ptr, size_t size);

	// 从中心缓存获取对象
	void* FetchFromCentralCache(size_t index, size_t size);

	void ListTooLong(FreeList& list, size_t size);

private:
	FreeList free_list_[NFREE_LIST];
};

// 使用TLS技术实现每个进程的内存池无锁访问
#ifdef _WIN32
	static _declspec(thread) ThreadCache* p_tls_thread_cache = nullptr;
#elif __linux__
	static ThreadCache* p_tls_thread_cache = nullptr;
#endif

#endif