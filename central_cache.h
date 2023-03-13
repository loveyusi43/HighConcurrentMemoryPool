#ifndef CENTRAL_CACHE_H
#define CENTRAL_CACHE_H

#include "common.h"

class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &instance_;
	}

	Span* GetOneSpan(SpanList& list, size_t size);

	size_t FetchRangeObj(void*& start, void*& end, size_t n, size_t byte_size);

	void ReleaseListToSpans(void* start, size_t byte_size);

private:
	CentralCache() = default;

	CentralCache(const CentralCache&) = delete;

	SpanList span_list_[NFREE_LIST];

	static CentralCache instance_;
};

#endif