#ifndef __DFTS_THRAEDWRAP_H_
#define __DFTS_THRAEDWRAP_H_

template <class T>
void thread_wrapper(void *v)
{
	T *x = reinterpret_cast<T *>(v);
	x->run();
}

#endif // __DFTS_THRAEDWRAP_H_
