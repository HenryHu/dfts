CXX = g++
CXXFLAGS = -I/usr/local/include/nspr -g -I/usr/local/include/cryptopp -pipe -fno-strict-aliasing `pcre++-config --cflags`
LDFLAGS = -L/usr/local/lib  -lcryptopp -pthread -lnspr4 `pcre++-config --libs`
SRCS = clientmanager.cpp config.cpp clientservice.cpp logger.cpp clientcommand.cpp netmgr.cpp main.cpp core.cpp usermanager.cpp filemanager.cpp \
	   packet.cpp keymgr.cpp cfgmgr.cpp user.cpp userhash.cpp file.cpp datahash.cpp block.cpp datahasher.cpp search.cpp searchresult.cpp searchmgr.cpp
OBJS = clientmanager.o config.o clientservice.o logger.o clientcommand.o netmgr.o main.o core.o usermanager.o filemanager.o packet.o keymgr.o cfgmgr.o \
	   user.o userhash.o file.o datahash.o block.o datahasher.o search.o searchresult.o searchmgr.o

all: dfts ctags

dfts: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${LDFLAGS} -o $@

ctags:
	exctags -R *.cpp *.h /usr/local/include/nspr/ /usr/local/include/cryptopp/

clean:
	rm -f ${OBJS} dfts

depend:
	makedepend -- ${CXXFLAGS} -I/usr/include/c++/4.2/ -- ${SRCS}
# DO NOT DELETE

clientmanager.o: clientmanager.h /usr/local/include/nspr/prio.h
clientmanager.o: /usr/local/include/nspr/prlong.h
clientmanager.o: /usr/local/include/nspr/prtypes.h
clientmanager.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
clientmanager.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
clientmanager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
clientmanager.o: /usr/local/include/nspr/obsolete/protypes.h
clientmanager.o: /usr/include/sys/types.h /usr/include/machine/endian.h
clientmanager.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
clientmanager.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
clientmanager.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prtime.h
clientmanager.o: /usr/local/include/nspr/prinrval.h
clientmanager.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
clientmanager.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
clientmanager.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
clientmanager.o: /usr/include/arpa/inet.h /usr/include/netdb.h
clientmanager.o: /usr/include/rpc/types.h /usr/include/sys/time.h
clientmanager.o: /usr/include/time.h /usr/include/netconfig.h
clientmanager.o: /usr/local/include/nspr/prthread.h
clientmanager.o: /usr/include/c++/4.2/vector
clientmanager.o: /usr/include/c++/4.2/bits/functexcept.h
clientmanager.o: /usr/include/c++/4.2/bits/c++config.h
clientmanager.o: /usr/include/c++/4.2/bits/os_defines.h
clientmanager.o: /usr/include/c++/4.2/bits/cpu_defines.h
clientmanager.o: /usr/include/c++/4.2/exception_defines.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_algobase.h
clientmanager.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
clientmanager.o: /usr/include/string.h /usr/include/strings.h
clientmanager.o: /usr/include/c++/4.2/climits /usr/include/limits.h
clientmanager.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
clientmanager.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
clientmanager.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
clientmanager.o: /usr/include/c++/4.2/bits/c++locale.h
clientmanager.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
clientmanager.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
clientmanager.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
clientmanager.o: /usr/include/c++/4.2/bits/c++io.h
clientmanager.o: /usr/include/c++/4.2/bits/gthr.h
clientmanager.o: /usr/include/c++/4.2/bits/gthr-default.h
clientmanager.o: /usr/include/pthread.h /usr/include/sched.h
clientmanager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
clientmanager.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
clientmanager.o: /usr/include/_ctype.h /usr/include/runetype.h
clientmanager.o: /usr/include/c++/4.2/bits/stringfwd.h
clientmanager.o: /usr/include/c++/4.2/bits/postypes.h
clientmanager.o: /usr/include/c++/4.2/cwchar /usr/include/c++/4.2/ctime
clientmanager.o: /usr/include/wchar.h /usr/include/stdint.h
clientmanager.o: /usr/include/machine/_stdint.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_pair.h
clientmanager.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
clientmanager.o: /usr/include/c++/4.2/ext/type_traits.h
clientmanager.o: /usr/include/c++/4.2/utility
clientmanager.o: /usr/include/c++/4.2/bits/stl_relops.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
clientmanager.o: /usr/include/c++/4.2/bits/concept_check.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_iterator.h
clientmanager.o: /usr/include/c++/4.2/debug/debug.h
clientmanager.o: /usr/include/c++/4.2/bits/allocator.h
clientmanager.o: /usr/include/c++/4.2/bits/c++allocator.h
clientmanager.o: /usr/include/c++/4.2/ext/new_allocator.h
clientmanager.o: /usr/include/c++/4.2/new /usr/include/c++/4.2/exception
clientmanager.o: /usr/include/c++/4.2/bits/stl_construct.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_vector.h
clientmanager.o: /usr/include/c++/4.2/bits/stl_bvector.h
clientmanager.o: /usr/include/c++/4.2/bits/vector.tcc clientservice.h core.h
clientmanager.o: clientcommand.h config.h /usr/include/errno.h threadwrap.h
clientmanager.o: /usr/local/include/nspr/prnetdb.h
config.o: config.h /usr/include/errno.h /usr/include/sys/cdefs.h
clientservice.o: clientservice.h /usr/local/include/nspr/prio.h
clientservice.o: /usr/local/include/nspr/prlong.h
clientservice.o: /usr/local/include/nspr/prtypes.h
clientservice.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
clientservice.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
clientservice.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
clientservice.o: /usr/local/include/nspr/obsolete/protypes.h
clientservice.o: /usr/include/sys/types.h /usr/include/machine/endian.h
clientservice.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
clientservice.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
clientservice.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prtime.h
clientservice.o: /usr/local/include/nspr/prinrval.h
clientservice.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
clientservice.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
clientservice.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
clientservice.o: /usr/include/arpa/inet.h /usr/include/netdb.h
clientservice.o: /usr/include/rpc/types.h /usr/include/sys/time.h
clientservice.o: /usr/include/time.h /usr/include/netconfig.h
clientservice.o: /usr/local/include/nspr/prthread.h core.h clientcommand.h
clientservice.o: config.h /usr/include/errno.h /usr/include/stdio.h
clientservice.o: threadwrap.h /usr/include/strings.h usermanager.h packet.h
clientservice.o: /usr/include/c++/4.2/string
clientservice.o: /usr/include/c++/4.2/bits/c++config.h
clientservice.o: /usr/include/c++/4.2/bits/os_defines.h
clientservice.o: /usr/include/c++/4.2/bits/cpu_defines.h
clientservice.o: /usr/include/c++/4.2/bits/stringfwd.h
clientservice.o: /usr/include/c++/4.2/bits/char_traits.h
clientservice.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
clientservice.o: /usr/include/string.h
clientservice.o: /usr/include/c++/4.2/bits/stl_algobase.h
clientservice.o: /usr/include/c++/4.2/climits /usr/include/limits.h
clientservice.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
clientservice.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
clientservice.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
clientservice.o: /usr/include/c++/4.2/bits/c++locale.h
clientservice.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
clientservice.o: /usr/include/c++/4.2/cstdio /usr/include/c++/4.2/cstdarg
clientservice.o: /usr/include/stdarg.h /usr/include/c++/4.2/bits/c++io.h
clientservice.o: /usr/include/c++/4.2/bits/gthr.h
clientservice.o: /usr/include/c++/4.2/bits/gthr-default.h
clientservice.o: /usr/include/pthread.h /usr/include/sched.h
clientservice.o: /usr/include/unistd.h /usr/include/sys/unistd.h
clientservice.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
clientservice.o: /usr/include/_ctype.h /usr/include/runetype.h
clientservice.o: /usr/include/c++/4.2/bits/postypes.h
clientservice.o: /usr/include/c++/4.2/cwchar /usr/include/c++/4.2/ctime
clientservice.o: /usr/include/wchar.h /usr/include/stdint.h
clientservice.o: /usr/include/machine/_stdint.h
clientservice.o: /usr/include/c++/4.2/bits/functexcept.h
clientservice.o: /usr/include/c++/4.2/exception_defines.h
clientservice.o: /usr/include/c++/4.2/bits/stl_pair.h
clientservice.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
clientservice.o: /usr/include/c++/4.2/ext/type_traits.h
clientservice.o: /usr/include/c++/4.2/utility
clientservice.o: /usr/include/c++/4.2/bits/stl_relops.h
clientservice.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
clientservice.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
clientservice.o: /usr/include/c++/4.2/bits/concept_check.h
clientservice.o: /usr/include/c++/4.2/bits/stl_iterator.h
clientservice.o: /usr/include/c++/4.2/debug/debug.h
clientservice.o: /usr/include/c++/4.2/memory
clientservice.o: /usr/include/c++/4.2/bits/allocator.h
clientservice.o: /usr/include/c++/4.2/bits/c++allocator.h
clientservice.o: /usr/include/c++/4.2/ext/new_allocator.h
clientservice.o: /usr/include/c++/4.2/new /usr/include/c++/4.2/exception
clientservice.o: /usr/include/c++/4.2/bits/stl_construct.h
clientservice.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
clientservice.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
clientservice.o: /usr/include/c++/4.2/limits
clientservice.o: /usr/include/c++/4.2/bits/ostream_insert.h
clientservice.o: /usr/include/c++/4.2/bits/stl_function.h
clientservice.o: /usr/include/c++/4.2/bits/basic_string.h
clientservice.o: /usr/include/c++/4.2/ext/atomicity.h
clientservice.o: /usr/include/c++/4.2/bits/atomic_word.h
clientservice.o: /usr/include/c++/4.2/algorithm
clientservice.o: /usr/include/c++/4.2/bits/stl_algo.h
clientservice.o: /usr/include/c++/4.2/bits/stl_heap.h
clientservice.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
clientservice.o: /usr/include/c++/4.2/bits/basic_string.tcc userhash.h user.h
clientservice.o: /usr/include/c++/4.2/list
clientservice.o: /usr/include/c++/4.2/bits/stl_list.h
clientservice.o: /usr/include/c++/4.2/bits/list.tcc
clientservice.o: /usr/local/include/nspr/prlock.h
clientservice.o: /usr/local/include/nspr/prnetdb.h
clientservice.o: /usr/local/include/nspr/prprf.h
logger.o: config.h /usr/include/errno.h /usr/include/sys/cdefs.h
logger.o: /usr/include/stdarg.h /usr/include/sys/_types.h
logger.o: /usr/include/machine/_types.h /usr/include/stdio.h
logger.o: /usr/include/sys/_null.h /usr/local/include/nspr/prerror.h
logger.o: /usr/local/include/nspr/prtypes.h
logger.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
logger.o: /usr/local/include/nspr/obsolete/protypes.h
logger.o: /usr/include/sys/types.h /usr/include/machine/endian.h
logger.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
logger.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
logger.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prerr.h
logger.o: /usr/include/string.h /usr/include/strings.h
clientcommand.o: clientcommand.h
netmgr.o: netmgr.h /usr/local/include/nspr/prio.h
netmgr.o: /usr/local/include/nspr/prlong.h /usr/local/include/nspr/prtypes.h
netmgr.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
netmgr.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
netmgr.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
netmgr.o: /usr/local/include/nspr/obsolete/protypes.h
netmgr.o: /usr/include/sys/types.h /usr/include/machine/endian.h
netmgr.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
netmgr.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
netmgr.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prtime.h
netmgr.o: /usr/local/include/nspr/prinrval.h /usr/local/include/nspr/prinet.h
netmgr.o: /usr/include/sys/socket.h /usr/include/sys/_iovec.h
netmgr.o: /usr/include/machine/param.h /usr/include/netinet/in.h
netmgr.o: /usr/include/netinet6/in6.h /usr/include/arpa/inet.h
netmgr.o: /usr/include/netdb.h /usr/include/rpc/types.h
netmgr.o: /usr/include/sys/time.h /usr/include/time.h
netmgr.o: /usr/include/netconfig.h /usr/local/include/nspr/prthread.h core.h
netmgr.o: /usr/local/include/nspr/prtpool.h /usr/local/include/nspr/prerror.h
netmgr.o: /usr/local/include/nspr/prerr.h packet.h
netmgr.o: /usr/include/c++/4.2/string /usr/include/c++/4.2/bits/c++config.h
netmgr.o: /usr/include/c++/4.2/bits/os_defines.h
netmgr.o: /usr/include/c++/4.2/bits/cpu_defines.h
netmgr.o: /usr/include/c++/4.2/bits/stringfwd.h
netmgr.o: /usr/include/c++/4.2/bits/char_traits.h
netmgr.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
netmgr.o: /usr/include/string.h /usr/include/strings.h
netmgr.o: /usr/include/c++/4.2/bits/stl_algobase.h
netmgr.o: /usr/include/c++/4.2/climits /usr/include/limits.h
netmgr.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
netmgr.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
netmgr.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
netmgr.o: /usr/include/c++/4.2/bits/c++locale.h /usr/include/c++/4.2/clocale
netmgr.o: /usr/include/locale.h /usr/include/c++/4.2/cstdio
netmgr.o: /usr/include/stdio.h /usr/include/c++/4.2/cstdarg
netmgr.o: /usr/include/stdarg.h /usr/include/c++/4.2/bits/c++io.h
netmgr.o: /usr/include/c++/4.2/bits/gthr.h
netmgr.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
netmgr.o: /usr/include/sched.h /usr/include/unistd.h
netmgr.o: /usr/include/sys/unistd.h /usr/include/c++/4.2/cctype
netmgr.o: /usr/include/ctype.h /usr/include/_ctype.h /usr/include/runetype.h
netmgr.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
netmgr.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h
netmgr.o: /usr/include/stdint.h /usr/include/machine/_stdint.h
netmgr.o: /usr/include/c++/4.2/bits/functexcept.h
netmgr.o: /usr/include/c++/4.2/exception_defines.h
netmgr.o: /usr/include/c++/4.2/bits/stl_pair.h
netmgr.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
netmgr.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
netmgr.o: /usr/include/c++/4.2/bits/stl_relops.h
netmgr.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
netmgr.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
netmgr.o: /usr/include/c++/4.2/bits/concept_check.h
netmgr.o: /usr/include/c++/4.2/bits/stl_iterator.h
netmgr.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
netmgr.o: /usr/include/c++/4.2/bits/allocator.h
netmgr.o: /usr/include/c++/4.2/bits/c++allocator.h
netmgr.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
netmgr.o: /usr/include/c++/4.2/exception
netmgr.o: /usr/include/c++/4.2/bits/stl_construct.h
netmgr.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
netmgr.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
netmgr.o: /usr/include/c++/4.2/limits
netmgr.o: /usr/include/c++/4.2/bits/ostream_insert.h
netmgr.o: /usr/include/c++/4.2/bits/stl_function.h
netmgr.o: /usr/include/c++/4.2/bits/basic_string.h
netmgr.o: /usr/include/c++/4.2/ext/atomicity.h
netmgr.o: /usr/include/c++/4.2/bits/atomic_word.h
netmgr.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
netmgr.o: /usr/include/c++/4.2/bits/stl_heap.h
netmgr.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
netmgr.o: /usr/include/c++/4.2/bits/basic_string.tcc packethook.h
netmgr.o: /usr/include/c++/4.2/map /usr/include/c++/4.2/bits/stl_tree.h
netmgr.o: /usr/include/c++/4.2/bits/stl_map.h
netmgr.o: /usr/include/c++/4.2/bits/stl_multimap.h threadwrap.h config.h
netmgr.o: /usr/include/errno.h /usr/local/include/nspr/prnetdb.h intercmd.h
netmgr.o: usermanager.h userhash.h user.h /usr/include/c++/4.2/list
netmgr.o: /usr/include/c++/4.2/bits/stl_list.h
netmgr.o: /usr/include/c++/4.2/bits/list.tcc /usr/local/include/nspr/prlock.h
netmgr.o: filemanager.h file.h block.h datahash.h
netmgr.o: /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream
netmgr.o: /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h
netmgr.o: /usr/include/c++/4.2/bits/ios_base.h
netmgr.o: /usr/include/c++/4.2/bits/locale_classes.h
netmgr.o: /usr/include/c++/4.2/streambuf
netmgr.o: /usr/include/c++/4.2/bits/streambuf.tcc
netmgr.o: /usr/include/c++/4.2/bits/basic_ios.h
netmgr.o: /usr/include/c++/4.2/bits/streambuf_iterator.h
netmgr.o: /usr/include/c++/4.2/bits/locale_facets.h
netmgr.o: /usr/include/c++/4.2/cwctype /usr/include/wctype.h
netmgr.o: /usr/include/c++/4.2/bits/ctype_base.h
netmgr.o: /usr/include/c++/4.2/bits/ctype_inline.h
netmgr.o: /usr/include/c++/4.2/bits/codecvt.h
netmgr.o: /usr/include/c++/4.2/bits/time_members.h
netmgr.o: /usr/include/c++/4.2/bits/messages_members.h
netmgr.o: /usr/include/c++/4.2/bits/basic_ios.tcc
netmgr.o: /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale
netmgr.o: /usr/include/c++/4.2/bits/locale_facets.tcc
netmgr.o: /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream
netmgr.o: /usr/include/c++/4.2/bits/istream.tcc
main.o: clientmanager.h /usr/local/include/nspr/prio.h
main.o: /usr/local/include/nspr/prlong.h /usr/local/include/nspr/prtypes.h
main.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
main.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
main.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
main.o: /usr/local/include/nspr/obsolete/protypes.h /usr/include/sys/types.h
main.o: /usr/include/machine/endian.h /usr/include/sys/_pthreadtypes.h
main.o: /usr/include/sys/select.h /usr/include/sys/_sigset.h
main.o: /usr/include/sys/_timeval.h /usr/include/sys/timespec.h
main.o: /usr/local/include/nspr/prtime.h /usr/local/include/nspr/prinrval.h
main.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
main.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
main.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
main.o: /usr/include/arpa/inet.h /usr/include/netdb.h
main.o: /usr/include/rpc/types.h /usr/include/sys/time.h /usr/include/time.h
main.o: /usr/include/netconfig.h /usr/local/include/nspr/prthread.h
main.o: /usr/include/c++/4.2/vector /usr/include/c++/4.2/bits/functexcept.h
main.o: /usr/include/c++/4.2/bits/c++config.h
main.o: /usr/include/c++/4.2/bits/os_defines.h
main.o: /usr/include/c++/4.2/bits/cpu_defines.h
main.o: /usr/include/c++/4.2/exception_defines.h
main.o: /usr/include/c++/4.2/bits/stl_algobase.h /usr/include/c++/4.2/cstring
main.o: /usr/include/c++/4.2/cstddef /usr/include/string.h
main.o: /usr/include/strings.h /usr/include/c++/4.2/climits
main.o: /usr/include/limits.h /usr/include/sys/limits.h
main.o: /usr/include/machine/_limits.h /usr/include/sys/syslimits.h
main.o: /usr/include/c++/4.2/cstdlib /usr/include/stdlib.h
main.o: /usr/include/c++/4.2/iosfwd /usr/include/c++/4.2/bits/c++locale.h
main.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
main.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
main.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
main.o: /usr/include/c++/4.2/bits/c++io.h /usr/include/c++/4.2/bits/gthr.h
main.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
main.o: /usr/include/sched.h /usr/include/unistd.h /usr/include/sys/unistd.h
main.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
main.o: /usr/include/_ctype.h /usr/include/runetype.h
main.o: /usr/include/c++/4.2/bits/stringfwd.h
main.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
main.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h /usr/include/stdint.h
main.o: /usr/include/machine/_stdint.h /usr/include/c++/4.2/bits/stl_pair.h
main.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
main.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
main.o: /usr/include/c++/4.2/bits/stl_relops.h
main.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
main.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
main.o: /usr/include/c++/4.2/bits/concept_check.h
main.o: /usr/include/c++/4.2/bits/stl_iterator.h
main.o: /usr/include/c++/4.2/debug/debug.h
main.o: /usr/include/c++/4.2/bits/allocator.h
main.o: /usr/include/c++/4.2/bits/c++allocator.h
main.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
main.o: /usr/include/c++/4.2/exception
main.o: /usr/include/c++/4.2/bits/stl_construct.h
main.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
main.o: /usr/include/c++/4.2/bits/stl_vector.h
main.o: /usr/include/c++/4.2/bits/stl_bvector.h
main.o: /usr/include/c++/4.2/bits/vector.tcc clientservice.h core.h
main.o: clientcommand.h usermanager.h packet.h /usr/include/c++/4.2/string
main.o: /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/memory
main.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
main.o: /usr/include/c++/4.2/limits
main.o: /usr/include/c++/4.2/bits/ostream_insert.h
main.o: /usr/include/c++/4.2/bits/stl_function.h
main.o: /usr/include/c++/4.2/bits/basic_string.h
main.o: /usr/include/c++/4.2/ext/atomicity.h
main.o: /usr/include/c++/4.2/bits/atomic_word.h
main.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
main.o: /usr/include/c++/4.2/bits/stl_heap.h
main.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
main.o: /usr/include/c++/4.2/bits/basic_string.tcc userhash.h user.h
main.o: /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h
main.o: /usr/include/c++/4.2/bits/list.tcc /usr/local/include/nspr/prlock.h
main.o: netmgr.h /usr/local/include/nspr/prtpool.h
main.o: /usr/local/include/nspr/prerror.h /usr/local/include/nspr/prerr.h
main.o: packethook.h /usr/include/c++/4.2/map
main.o: /usr/include/c++/4.2/bits/stl_tree.h
main.o: /usr/include/c++/4.2/bits/stl_map.h
main.o: /usr/include/c++/4.2/bits/stl_multimap.h cfgmgr.h config.h
main.o: /usr/include/errno.h /usr/local/include/nspr/prnetdb.h keymgr.h
main.o: /usr/local/include/cryptopp/files.h
main.o: /usr/local/include/cryptopp/cryptlib.h
main.o: /usr/local/include/cryptopp/stdcpp.h /usr/include/assert.h
main.o: /usr/include/c++/4.2/typeinfo /usr/local/include/cryptopp/filters.h
main.o: /usr/local/include/cryptopp/simple.h
main.o: /usr/local/include/cryptopp/misc.h
main.o: /usr/local/include/cryptopp/smartptr.h
main.o: /usr/local/include/cryptopp/secblock.h
main.o: /usr/local/include/cryptopp/queue.h
main.o: /usr/local/include/cryptopp/algparam.h /usr/include/c++/4.2/deque
main.o: /usr/include/c++/4.2/bits/stl_deque.h
main.o: /usr/include/c++/4.2/bits/deque.tcc
main.o: /usr/local/include/cryptopp/argnames.h /usr/include/c++/4.2/iostream
main.o: /usr/include/c++/4.2/ostream /usr/include/c++/4.2/ios
main.o: /usr/include/c++/4.2/bits/localefwd.h
main.o: /usr/include/c++/4.2/bits/ios_base.h
main.o: /usr/include/c++/4.2/bits/locale_classes.h
main.o: /usr/include/c++/4.2/streambuf
main.o: /usr/include/c++/4.2/bits/streambuf.tcc
main.o: /usr/include/c++/4.2/bits/basic_ios.h
main.o: /usr/include/c++/4.2/bits/streambuf_iterator.h
main.o: /usr/include/c++/4.2/bits/locale_facets.h
main.o: /usr/include/c++/4.2/cwctype /usr/include/wctype.h
main.o: /usr/include/c++/4.2/bits/ctype_base.h
main.o: /usr/include/c++/4.2/bits/ctype_inline.h
main.o: /usr/include/c++/4.2/bits/codecvt.h
main.o: /usr/include/c++/4.2/bits/time_members.h
main.o: /usr/include/c++/4.2/bits/messages_members.h
main.o: /usr/include/c++/4.2/bits/basic_ios.tcc
main.o: /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale
main.o: /usr/include/c++/4.2/bits/locale_facets.tcc
main.o: /usr/include/c++/4.2/istream /usr/include/c++/4.2/bits/istream.tcc
main.o: /usr/include/c++/4.2/fstream /usr/include/c++/4.2/bits/basic_file.h
main.o: /usr/include/c++/4.2/bits/fstream.tcc
core.o: core.h
usermanager.o: usermanager.h /usr/local/include/nspr/prio.h
usermanager.o: /usr/local/include/nspr/prlong.h
usermanager.o: /usr/local/include/nspr/prtypes.h
usermanager.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
usermanager.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
usermanager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
usermanager.o: /usr/local/include/nspr/obsolete/protypes.h
usermanager.o: /usr/include/sys/types.h /usr/include/machine/endian.h
usermanager.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
usermanager.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
usermanager.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prtime.h
usermanager.o: /usr/local/include/nspr/prinrval.h
usermanager.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
usermanager.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
usermanager.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
usermanager.o: /usr/include/arpa/inet.h /usr/include/netdb.h
usermanager.o: /usr/include/rpc/types.h /usr/include/sys/time.h
usermanager.o: /usr/include/time.h /usr/include/netconfig.h core.h packet.h
usermanager.o: /usr/include/c++/4.2/string
usermanager.o: /usr/include/c++/4.2/bits/c++config.h
usermanager.o: /usr/include/c++/4.2/bits/os_defines.h
usermanager.o: /usr/include/c++/4.2/bits/cpu_defines.h
usermanager.o: /usr/include/c++/4.2/bits/stringfwd.h
usermanager.o: /usr/include/c++/4.2/bits/char_traits.h
usermanager.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
usermanager.o: /usr/include/string.h /usr/include/strings.h
usermanager.o: /usr/include/c++/4.2/bits/stl_algobase.h
usermanager.o: /usr/include/c++/4.2/climits /usr/include/limits.h
usermanager.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
usermanager.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
usermanager.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
usermanager.o: /usr/include/c++/4.2/bits/c++locale.h
usermanager.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
usermanager.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
usermanager.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
usermanager.o: /usr/include/c++/4.2/bits/c++io.h
usermanager.o: /usr/include/c++/4.2/bits/gthr.h
usermanager.o: /usr/include/c++/4.2/bits/gthr-default.h
usermanager.o: /usr/include/pthread.h /usr/include/sched.h
usermanager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
usermanager.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
usermanager.o: /usr/include/_ctype.h /usr/include/runetype.h
usermanager.o: /usr/include/c++/4.2/bits/postypes.h
usermanager.o: /usr/include/c++/4.2/cwchar /usr/include/c++/4.2/ctime
usermanager.o: /usr/include/wchar.h /usr/include/stdint.h
usermanager.o: /usr/include/machine/_stdint.h
usermanager.o: /usr/include/c++/4.2/bits/functexcept.h
usermanager.o: /usr/include/c++/4.2/exception_defines.h
usermanager.o: /usr/include/c++/4.2/bits/stl_pair.h
usermanager.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
usermanager.o: /usr/include/c++/4.2/ext/type_traits.h
usermanager.o: /usr/include/c++/4.2/utility
usermanager.o: /usr/include/c++/4.2/bits/stl_relops.h
usermanager.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
usermanager.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
usermanager.o: /usr/include/c++/4.2/bits/concept_check.h
usermanager.o: /usr/include/c++/4.2/bits/stl_iterator.h
usermanager.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
usermanager.o: /usr/include/c++/4.2/bits/allocator.h
usermanager.o: /usr/include/c++/4.2/bits/c++allocator.h
usermanager.o: /usr/include/c++/4.2/ext/new_allocator.h
usermanager.o: /usr/include/c++/4.2/new /usr/include/c++/4.2/exception
usermanager.o: /usr/include/c++/4.2/bits/stl_construct.h
usermanager.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
usermanager.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
usermanager.o: /usr/include/c++/4.2/limits
usermanager.o: /usr/include/c++/4.2/bits/ostream_insert.h
usermanager.o: /usr/include/c++/4.2/bits/stl_function.h
usermanager.o: /usr/include/c++/4.2/bits/basic_string.h
usermanager.o: /usr/include/c++/4.2/ext/atomicity.h
usermanager.o: /usr/include/c++/4.2/bits/atomic_word.h
usermanager.o: /usr/include/c++/4.2/algorithm
usermanager.o: /usr/include/c++/4.2/bits/stl_algo.h
usermanager.o: /usr/include/c++/4.2/bits/stl_heap.h
usermanager.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
usermanager.o: /usr/include/c++/4.2/bits/basic_string.tcc userhash.h user.h
usermanager.o: /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h
usermanager.o: /usr/include/c++/4.2/bits/list.tcc
usermanager.o: /usr/local/include/nspr/prlock.h config.h /usr/include/errno.h
usermanager.o: netmgr.h /usr/local/include/nspr/prthread.h
usermanager.o: /usr/local/include/nspr/prtpool.h
usermanager.o: /usr/local/include/nspr/prerror.h
usermanager.o: /usr/local/include/nspr/prerr.h packethook.h
usermanager.o: /usr/include/c++/4.2/map /usr/include/c++/4.2/bits/stl_tree.h
usermanager.o: /usr/include/c++/4.2/bits/stl_map.h
usermanager.o: /usr/include/c++/4.2/bits/stl_multimap.h keymgr.h
usermanager.o: /usr/local/include/cryptopp/files.h
usermanager.o: /usr/local/include/cryptopp/cryptlib.h
usermanager.o: /usr/local/include/cryptopp/stdcpp.h /usr/include/assert.h
usermanager.o: /usr/include/c++/4.2/typeinfo
usermanager.o: /usr/local/include/cryptopp/filters.h
usermanager.o: /usr/local/include/cryptopp/simple.h
usermanager.o: /usr/local/include/cryptopp/misc.h
usermanager.o: /usr/local/include/cryptopp/smartptr.h
usermanager.o: /usr/local/include/cryptopp/secblock.h
usermanager.o: /usr/local/include/cryptopp/queue.h
usermanager.o: /usr/local/include/cryptopp/algparam.h
usermanager.o: /usr/include/c++/4.2/deque
usermanager.o: /usr/include/c++/4.2/bits/stl_deque.h
usermanager.o: /usr/include/c++/4.2/bits/deque.tcc
usermanager.o: /usr/local/include/cryptopp/argnames.h
usermanager.o: /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream
usermanager.o: /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h
usermanager.o: /usr/include/c++/4.2/bits/ios_base.h
usermanager.o: /usr/include/c++/4.2/bits/locale_classes.h
usermanager.o: /usr/include/c++/4.2/streambuf
usermanager.o: /usr/include/c++/4.2/bits/streambuf.tcc
usermanager.o: /usr/include/c++/4.2/bits/basic_ios.h
usermanager.o: /usr/include/c++/4.2/bits/streambuf_iterator.h
usermanager.o: /usr/include/c++/4.2/bits/locale_facets.h
usermanager.o: /usr/include/c++/4.2/cwctype /usr/include/wctype.h
usermanager.o: /usr/include/c++/4.2/bits/ctype_base.h
usermanager.o: /usr/include/c++/4.2/bits/ctype_inline.h
usermanager.o: /usr/include/c++/4.2/bits/codecvt.h
usermanager.o: /usr/include/c++/4.2/bits/time_members.h
usermanager.o: /usr/include/c++/4.2/bits/messages_members.h
usermanager.o: /usr/include/c++/4.2/bits/basic_ios.tcc
usermanager.o: /usr/include/c++/4.2/bits/ostream.tcc
usermanager.o: /usr/include/c++/4.2/locale
usermanager.o: /usr/include/c++/4.2/bits/locale_facets.tcc
usermanager.o: /usr/include/c++/4.2/istream
usermanager.o: /usr/include/c++/4.2/bits/istream.tcc
usermanager.o: /usr/include/c++/4.2/fstream
usermanager.o: /usr/include/c++/4.2/bits/basic_file.h
usermanager.o: /usr/include/c++/4.2/bits/fstream.tcc cfgmgr.h intercmd.h
usermanager.o: /usr/local/include/nspr/prnetdb.h
filemanager.o: filemanager.h /usr/local/include/nspr/prio.h
filemanager.o: /usr/local/include/nspr/prlong.h
filemanager.o: /usr/local/include/nspr/prtypes.h
filemanager.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
filemanager.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
filemanager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
filemanager.o: /usr/local/include/nspr/obsolete/protypes.h
filemanager.o: /usr/include/sys/types.h /usr/include/machine/endian.h
filemanager.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
filemanager.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
filemanager.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prtime.h
filemanager.o: /usr/local/include/nspr/prinrval.h
filemanager.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
filemanager.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
filemanager.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
filemanager.o: /usr/include/arpa/inet.h /usr/include/netdb.h
filemanager.o: /usr/include/rpc/types.h /usr/include/sys/time.h
filemanager.o: /usr/include/time.h /usr/include/netconfig.h core.h packet.h
filemanager.o: /usr/include/c++/4.2/string
filemanager.o: /usr/include/c++/4.2/bits/c++config.h
filemanager.o: /usr/include/c++/4.2/bits/os_defines.h
filemanager.o: /usr/include/c++/4.2/bits/cpu_defines.h
filemanager.o: /usr/include/c++/4.2/bits/stringfwd.h
filemanager.o: /usr/include/c++/4.2/bits/char_traits.h
filemanager.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
filemanager.o: /usr/include/string.h /usr/include/strings.h
filemanager.o: /usr/include/c++/4.2/bits/stl_algobase.h
filemanager.o: /usr/include/c++/4.2/climits /usr/include/limits.h
filemanager.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
filemanager.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
filemanager.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
filemanager.o: /usr/include/c++/4.2/bits/c++locale.h
filemanager.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
filemanager.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
filemanager.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
filemanager.o: /usr/include/c++/4.2/bits/c++io.h
filemanager.o: /usr/include/c++/4.2/bits/gthr.h
filemanager.o: /usr/include/c++/4.2/bits/gthr-default.h
filemanager.o: /usr/include/pthread.h /usr/include/sched.h
filemanager.o: /usr/include/unistd.h /usr/include/sys/unistd.h
filemanager.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
filemanager.o: /usr/include/_ctype.h /usr/include/runetype.h
filemanager.o: /usr/include/c++/4.2/bits/postypes.h
filemanager.o: /usr/include/c++/4.2/cwchar /usr/include/c++/4.2/ctime
filemanager.o: /usr/include/wchar.h /usr/include/stdint.h
filemanager.o: /usr/include/machine/_stdint.h
filemanager.o: /usr/include/c++/4.2/bits/functexcept.h
filemanager.o: /usr/include/c++/4.2/exception_defines.h
filemanager.o: /usr/include/c++/4.2/bits/stl_pair.h
filemanager.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
filemanager.o: /usr/include/c++/4.2/ext/type_traits.h
filemanager.o: /usr/include/c++/4.2/utility
filemanager.o: /usr/include/c++/4.2/bits/stl_relops.h
filemanager.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
filemanager.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
filemanager.o: /usr/include/c++/4.2/bits/concept_check.h
filemanager.o: /usr/include/c++/4.2/bits/stl_iterator.h
filemanager.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
filemanager.o: /usr/include/c++/4.2/bits/allocator.h
filemanager.o: /usr/include/c++/4.2/bits/c++allocator.h
filemanager.o: /usr/include/c++/4.2/ext/new_allocator.h
filemanager.o: /usr/include/c++/4.2/new /usr/include/c++/4.2/exception
filemanager.o: /usr/include/c++/4.2/bits/stl_construct.h
filemanager.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
filemanager.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
filemanager.o: /usr/include/c++/4.2/limits
filemanager.o: /usr/include/c++/4.2/bits/ostream_insert.h
filemanager.o: /usr/include/c++/4.2/bits/stl_function.h
filemanager.o: /usr/include/c++/4.2/bits/basic_string.h
filemanager.o: /usr/include/c++/4.2/ext/atomicity.h
filemanager.o: /usr/include/c++/4.2/bits/atomic_word.h
filemanager.o: /usr/include/c++/4.2/algorithm
filemanager.o: /usr/include/c++/4.2/bits/stl_algo.h
filemanager.o: /usr/include/c++/4.2/bits/stl_heap.h
filemanager.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
filemanager.o: /usr/include/c++/4.2/bits/basic_string.tcc
filemanager.o: /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h
filemanager.o: /usr/include/c++/4.2/bits/list.tcc file.h block.h datahash.h
filemanager.o: /usr/local/include/nspr/prlock.h /usr/include/c++/4.2/map
filemanager.o: /usr/include/c++/4.2/bits/stl_tree.h
filemanager.o: /usr/include/c++/4.2/bits/stl_map.h
filemanager.o: /usr/include/c++/4.2/bits/stl_multimap.h config.h
filemanager.o: /usr/include/errno.h intercmd.h /usr/include/c++/4.2/iostream
filemanager.o: /usr/include/c++/4.2/ostream /usr/include/c++/4.2/ios
filemanager.o: /usr/include/c++/4.2/bits/localefwd.h
filemanager.o: /usr/include/c++/4.2/bits/ios_base.h
filemanager.o: /usr/include/c++/4.2/bits/locale_classes.h
filemanager.o: /usr/include/c++/4.2/streambuf
filemanager.o: /usr/include/c++/4.2/bits/streambuf.tcc
filemanager.o: /usr/include/c++/4.2/bits/basic_ios.h
filemanager.o: /usr/include/c++/4.2/bits/streambuf_iterator.h
filemanager.o: /usr/include/c++/4.2/bits/locale_facets.h
filemanager.o: /usr/include/c++/4.2/cwctype /usr/include/wctype.h
filemanager.o: /usr/include/c++/4.2/bits/ctype_base.h
filemanager.o: /usr/include/c++/4.2/bits/ctype_inline.h
filemanager.o: /usr/include/c++/4.2/bits/codecvt.h
filemanager.o: /usr/include/c++/4.2/bits/time_members.h
filemanager.o: /usr/include/c++/4.2/bits/messages_members.h
filemanager.o: /usr/include/c++/4.2/bits/basic_ios.tcc
filemanager.o: /usr/include/c++/4.2/bits/ostream.tcc
filemanager.o: /usr/include/c++/4.2/locale
filemanager.o: /usr/include/c++/4.2/bits/locale_facets.tcc
filemanager.o: /usr/include/c++/4.2/typeinfo /usr/include/c++/4.2/istream
filemanager.o: /usr/include/c++/4.2/bits/istream.tcc netmgr.h
filemanager.o: /usr/local/include/nspr/prthread.h
filemanager.o: /usr/local/include/nspr/prtpool.h
filemanager.o: /usr/local/include/nspr/prerror.h
filemanager.o: /usr/local/include/nspr/prerr.h packethook.h datahasher.h
packet.o: packet.h /usr/local/include/nspr/prio.h
packet.o: /usr/local/include/nspr/prlong.h /usr/local/include/nspr/prtypes.h
packet.o: /usr/local/include/nspr/prcpucfg.h /usr/include/stddef.h
packet.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
packet.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
packet.o: /usr/local/include/nspr/obsolete/protypes.h
packet.o: /usr/include/sys/types.h /usr/include/machine/endian.h
packet.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/select.h
packet.o: /usr/include/sys/_sigset.h /usr/include/sys/_timeval.h
packet.o: /usr/include/sys/timespec.h /usr/local/include/nspr/prtime.h
packet.o: /usr/local/include/nspr/prinrval.h /usr/local/include/nspr/prinet.h
packet.o: /usr/include/sys/socket.h /usr/include/sys/_iovec.h
packet.o: /usr/include/machine/param.h /usr/include/netinet/in.h
packet.o: /usr/include/netinet6/in6.h /usr/include/arpa/inet.h
packet.o: /usr/include/netdb.h /usr/include/rpc/types.h
packet.o: /usr/include/sys/time.h /usr/include/time.h
packet.o: /usr/include/netconfig.h /usr/include/c++/4.2/string
packet.o: /usr/include/c++/4.2/bits/c++config.h
packet.o: /usr/include/c++/4.2/bits/os_defines.h
packet.o: /usr/include/c++/4.2/bits/cpu_defines.h
packet.o: /usr/include/c++/4.2/bits/stringfwd.h
packet.o: /usr/include/c++/4.2/bits/char_traits.h
packet.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
packet.o: /usr/include/string.h /usr/include/strings.h
packet.o: /usr/include/c++/4.2/bits/stl_algobase.h
packet.o: /usr/include/c++/4.2/climits /usr/include/limits.h
packet.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
packet.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
packet.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
packet.o: /usr/include/c++/4.2/bits/c++locale.h /usr/include/c++/4.2/clocale
packet.o: /usr/include/locale.h /usr/include/c++/4.2/cstdio
packet.o: /usr/include/stdio.h /usr/include/c++/4.2/cstdarg
packet.o: /usr/include/stdarg.h /usr/include/c++/4.2/bits/c++io.h
packet.o: /usr/include/c++/4.2/bits/gthr.h
packet.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
packet.o: /usr/include/sched.h /usr/include/unistd.h
packet.o: /usr/include/sys/unistd.h /usr/include/c++/4.2/cctype
packet.o: /usr/include/ctype.h /usr/include/_ctype.h /usr/include/runetype.h
packet.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
packet.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h
packet.o: /usr/include/stdint.h /usr/include/machine/_stdint.h
packet.o: /usr/include/c++/4.2/bits/functexcept.h
packet.o: /usr/include/c++/4.2/exception_defines.h
packet.o: /usr/include/c++/4.2/bits/stl_pair.h
packet.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
packet.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
packet.o: /usr/include/c++/4.2/bits/stl_relops.h
packet.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
packet.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
packet.o: /usr/include/c++/4.2/bits/concept_check.h
packet.o: /usr/include/c++/4.2/bits/stl_iterator.h
packet.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
packet.o: /usr/include/c++/4.2/bits/allocator.h
packet.o: /usr/include/c++/4.2/bits/c++allocator.h
packet.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
packet.o: /usr/include/c++/4.2/exception
packet.o: /usr/include/c++/4.2/bits/stl_construct.h
packet.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
packet.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
packet.o: /usr/include/c++/4.2/limits
packet.o: /usr/include/c++/4.2/bits/ostream_insert.h
packet.o: /usr/include/c++/4.2/bits/stl_function.h
packet.o: /usr/include/c++/4.2/bits/basic_string.h
packet.o: /usr/include/c++/4.2/ext/atomicity.h
packet.o: /usr/include/c++/4.2/bits/atomic_word.h
packet.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
packet.o: /usr/include/c++/4.2/bits/stl_heap.h
packet.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
packet.o: /usr/include/c++/4.2/bits/basic_string.tcc
packet.o: /usr/local/include/nspr/prnetdb.h
keymgr.o: keymgr.h /usr/local/include/cryptopp/files.h
keymgr.o: /usr/local/include/cryptopp/cryptlib.h config.h
keymgr.o: /usr/include/errno.h /usr/include/sys/cdefs.h
keymgr.o: /usr/local/include/cryptopp/stdcpp.h /usr/include/stddef.h
keymgr.o: /usr/include/sys/_null.h /usr/include/sys/_types.h
keymgr.o: /usr/include/machine/_types.h /usr/include/assert.h
keymgr.o: /usr/include/limits.h /usr/include/sys/limits.h
keymgr.o: /usr/include/machine/_limits.h /usr/include/sys/syslimits.h
keymgr.o: /usr/include/c++/4.2/memory
keymgr.o: /usr/include/c++/4.2/bits/stl_algobase.h
keymgr.o: /usr/include/c++/4.2/bits/c++config.h
keymgr.o: /usr/include/c++/4.2/bits/os_defines.h
keymgr.o: /usr/include/c++/4.2/bits/cpu_defines.h
keymgr.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
keymgr.o: /usr/include/string.h /usr/include/strings.h
keymgr.o: /usr/include/c++/4.2/climits /usr/include/c++/4.2/cstdlib
keymgr.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
keymgr.o: /usr/include/c++/4.2/bits/c++locale.h /usr/include/c++/4.2/clocale
keymgr.o: /usr/include/locale.h /usr/include/c++/4.2/cstdio
keymgr.o: /usr/include/stdio.h /usr/include/c++/4.2/cstdarg
keymgr.o: /usr/include/stdarg.h /usr/include/c++/4.2/bits/c++io.h
keymgr.o: /usr/include/c++/4.2/bits/gthr.h
keymgr.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
keymgr.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
keymgr.o: /usr/include/sched.h /usr/include/time.h
keymgr.o: /usr/include/sys/timespec.h /usr/include/unistd.h
keymgr.o: /usr/include/sys/types.h /usr/include/machine/endian.h
keymgr.o: /usr/include/sys/select.h /usr/include/sys/_timeval.h
keymgr.o: /usr/include/sys/unistd.h /usr/include/c++/4.2/cctype
keymgr.o: /usr/include/ctype.h /usr/include/_ctype.h /usr/include/runetype.h
keymgr.o: /usr/include/c++/4.2/bits/stringfwd.h
keymgr.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
keymgr.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h
keymgr.o: /usr/include/stdint.h /usr/include/machine/_stdint.h
keymgr.o: /usr/include/c++/4.2/bits/functexcept.h
keymgr.o: /usr/include/c++/4.2/exception_defines.h
keymgr.o: /usr/include/c++/4.2/bits/stl_pair.h
keymgr.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
keymgr.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
keymgr.o: /usr/include/c++/4.2/bits/stl_relops.h
keymgr.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
keymgr.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
keymgr.o: /usr/include/c++/4.2/bits/concept_check.h
keymgr.o: /usr/include/c++/4.2/bits/stl_iterator.h
keymgr.o: /usr/include/c++/4.2/debug/debug.h
keymgr.o: /usr/include/c++/4.2/bits/allocator.h
keymgr.o: /usr/include/c++/4.2/bits/c++allocator.h
keymgr.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
keymgr.o: /usr/include/c++/4.2/exception
keymgr.o: /usr/include/c++/4.2/bits/stl_construct.h
keymgr.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
keymgr.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
keymgr.o: /usr/include/c++/4.2/limits /usr/include/c++/4.2/string
keymgr.o: /usr/include/c++/4.2/bits/char_traits.h
keymgr.o: /usr/include/c++/4.2/bits/ostream_insert.h
keymgr.o: /usr/include/c++/4.2/bits/stl_function.h
keymgr.o: /usr/include/c++/4.2/bits/basic_string.h
keymgr.o: /usr/include/c++/4.2/ext/atomicity.h
keymgr.o: /usr/include/c++/4.2/bits/atomic_word.h
keymgr.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
keymgr.o: /usr/include/c++/4.2/bits/stl_heap.h
keymgr.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
keymgr.o: /usr/include/c++/4.2/bits/basic_string.tcc
keymgr.o: /usr/include/c++/4.2/typeinfo /usr/local/include/cryptopp/filters.h
keymgr.o: /usr/local/include/cryptopp/simple.h
keymgr.o: /usr/local/include/cryptopp/misc.h
keymgr.o: /usr/local/include/cryptopp/smartptr.h
keymgr.o: /usr/local/include/cryptopp/secblock.h
keymgr.o: /usr/local/include/cryptopp/queue.h
keymgr.o: /usr/local/include/cryptopp/algparam.h /usr/include/c++/4.2/deque
keymgr.o: /usr/include/c++/4.2/bits/stl_deque.h
keymgr.o: /usr/include/c++/4.2/bits/deque.tcc
keymgr.o: /usr/local/include/cryptopp/argnames.h
keymgr.o: /usr/include/c++/4.2/iostream /usr/include/c++/4.2/ostream
keymgr.o: /usr/include/c++/4.2/ios /usr/include/c++/4.2/bits/localefwd.h
keymgr.o: /usr/include/c++/4.2/bits/ios_base.h
keymgr.o: /usr/include/c++/4.2/bits/locale_classes.h
keymgr.o: /usr/include/c++/4.2/streambuf
keymgr.o: /usr/include/c++/4.2/bits/streambuf.tcc
keymgr.o: /usr/include/c++/4.2/bits/basic_ios.h
keymgr.o: /usr/include/c++/4.2/bits/streambuf_iterator.h
keymgr.o: /usr/include/c++/4.2/bits/locale_facets.h
keymgr.o: /usr/include/c++/4.2/cwctype /usr/include/wctype.h
keymgr.o: /usr/include/c++/4.2/bits/ctype_base.h
keymgr.o: /usr/include/c++/4.2/bits/ctype_inline.h
keymgr.o: /usr/include/c++/4.2/bits/codecvt.h
keymgr.o: /usr/include/c++/4.2/bits/time_members.h
keymgr.o: /usr/include/c++/4.2/bits/messages_members.h
keymgr.o: /usr/include/c++/4.2/bits/basic_ios.tcc
keymgr.o: /usr/include/c++/4.2/bits/ostream.tcc /usr/include/c++/4.2/locale
keymgr.o: /usr/include/c++/4.2/bits/locale_facets.tcc
keymgr.o: /usr/include/c++/4.2/istream /usr/include/c++/4.2/bits/istream.tcc
keymgr.o: /usr/include/c++/4.2/fstream /usr/include/c++/4.2/bits/basic_file.h
keymgr.o: /usr/include/c++/4.2/bits/fstream.tcc
keymgr.o: /usr/local/include/cryptopp/rsa.h
keymgr.o: /usr/local/include/cryptopp/pubkey.h
keymgr.o: /usr/local/include/cryptopp/modarith.h
keymgr.o: /usr/local/include/cryptopp/integer.h
keymgr.o: /usr/local/include/cryptopp/algebra.h
keymgr.o: /usr/local/include/cryptopp/eprecomp.h /usr/include/c++/4.2/vector
keymgr.o: /usr/include/c++/4.2/bits/stl_vector.h
keymgr.o: /usr/include/c++/4.2/bits/stl_bvector.h
keymgr.o: /usr/include/c++/4.2/bits/vector.tcc
keymgr.o: /usr/local/include/cryptopp/fips140.h
keymgr.o: /usr/local/include/cryptopp/asn.h
keymgr.o: /usr/local/include/cryptopp/pkcspad.h
keymgr.o: /usr/local/include/cryptopp/oaep.h
keymgr.o: /usr/local/include/cryptopp/sha.h
keymgr.o: /usr/local/include/cryptopp/iterhash.h
keymgr.o: /usr/local/include/cryptopp/emsa2.h /usr/local/include/nspr/prio.h
keymgr.o: /usr/local/include/nspr/prlong.h /usr/local/include/nspr/prtypes.h
keymgr.o: /usr/local/include/nspr/prcpucfg.h
keymgr.o: /usr/local/include/nspr/obsolete/protypes.h
keymgr.o: /usr/local/include/nspr/prtime.h /usr/local/include/nspr/prinrval.h
keymgr.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
keymgr.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
keymgr.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
keymgr.o: /usr/include/arpa/inet.h /usr/include/netdb.h
keymgr.o: /usr/include/rpc/types.h /usr/include/sys/time.h
keymgr.o: /usr/include/netconfig.h /usr/local/include/cryptopp/base64.h
keymgr.o: /usr/local/include/cryptopp/basecode.h
keymgr.o: /usr/local/include/cryptopp/osrng.h
cfgmgr.o: cfgmgr.h /usr/include/c++/4.2/string
cfgmgr.o: /usr/include/c++/4.2/bits/c++config.h
cfgmgr.o: /usr/include/c++/4.2/bits/os_defines.h
cfgmgr.o: /usr/include/c++/4.2/bits/cpu_defines.h
cfgmgr.o: /usr/include/c++/4.2/bits/stringfwd.h
cfgmgr.o: /usr/include/c++/4.2/bits/char_traits.h
cfgmgr.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
cfgmgr.o: /usr/include/stddef.h /usr/include/sys/cdefs.h
cfgmgr.o: /usr/include/sys/_null.h /usr/include/sys/_types.h
cfgmgr.o: /usr/include/machine/_types.h /usr/include/string.h
cfgmgr.o: /usr/include/strings.h /usr/include/c++/4.2/bits/stl_algobase.h
cfgmgr.o: /usr/include/c++/4.2/climits /usr/include/limits.h
cfgmgr.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
cfgmgr.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
cfgmgr.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
cfgmgr.o: /usr/include/c++/4.2/bits/c++locale.h /usr/include/c++/4.2/clocale
cfgmgr.o: /usr/include/locale.h /usr/include/c++/4.2/cstdio
cfgmgr.o: /usr/include/stdio.h /usr/include/c++/4.2/cstdarg
cfgmgr.o: /usr/include/stdarg.h /usr/include/c++/4.2/bits/c++io.h
cfgmgr.o: /usr/include/c++/4.2/bits/gthr.h
cfgmgr.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
cfgmgr.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
cfgmgr.o: /usr/include/sched.h /usr/include/time.h
cfgmgr.o: /usr/include/sys/timespec.h /usr/include/unistd.h
cfgmgr.o: /usr/include/sys/types.h /usr/include/machine/endian.h
cfgmgr.o: /usr/include/sys/select.h /usr/include/sys/_timeval.h
cfgmgr.o: /usr/include/sys/unistd.h /usr/include/c++/4.2/cctype
cfgmgr.o: /usr/include/ctype.h /usr/include/_ctype.h /usr/include/runetype.h
cfgmgr.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
cfgmgr.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h
cfgmgr.o: /usr/include/stdint.h /usr/include/machine/_stdint.h
cfgmgr.o: /usr/include/c++/4.2/bits/functexcept.h
cfgmgr.o: /usr/include/c++/4.2/exception_defines.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_pair.h
cfgmgr.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
cfgmgr.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
cfgmgr.o: /usr/include/c++/4.2/bits/stl_relops.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
cfgmgr.o: /usr/include/c++/4.2/bits/concept_check.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_iterator.h
cfgmgr.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
cfgmgr.o: /usr/include/c++/4.2/bits/allocator.h
cfgmgr.o: /usr/include/c++/4.2/bits/c++allocator.h
cfgmgr.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
cfgmgr.o: /usr/include/c++/4.2/exception
cfgmgr.o: /usr/include/c++/4.2/bits/stl_construct.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
cfgmgr.o: /usr/include/c++/4.2/limits
cfgmgr.o: /usr/include/c++/4.2/bits/ostream_insert.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_function.h
cfgmgr.o: /usr/include/c++/4.2/bits/basic_string.h
cfgmgr.o: /usr/include/c++/4.2/ext/atomicity.h
cfgmgr.o: /usr/include/c++/4.2/bits/atomic_word.h
cfgmgr.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_heap.h
cfgmgr.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
cfgmgr.o: /usr/include/c++/4.2/bits/basic_string.tcc
user.o: user.h /usr/include/c++/4.2/string
user.o: /usr/include/c++/4.2/bits/c++config.h
user.o: /usr/include/c++/4.2/bits/os_defines.h
user.o: /usr/include/c++/4.2/bits/cpu_defines.h
user.o: /usr/include/c++/4.2/bits/stringfwd.h
user.o: /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring
user.o: /usr/include/c++/4.2/cstddef /usr/include/stddef.h
user.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
user.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
user.o: /usr/include/string.h /usr/include/strings.h
user.o: /usr/include/c++/4.2/bits/stl_algobase.h /usr/include/c++/4.2/climits
user.o: /usr/include/limits.h /usr/include/sys/limits.h
user.o: /usr/include/machine/_limits.h /usr/include/sys/syslimits.h
user.o: /usr/include/c++/4.2/cstdlib /usr/include/stdlib.h
user.o: /usr/include/c++/4.2/iosfwd /usr/include/c++/4.2/bits/c++locale.h
user.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
user.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
user.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
user.o: /usr/include/c++/4.2/bits/c++io.h /usr/include/c++/4.2/bits/gthr.h
user.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
user.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
user.o: /usr/include/sched.h /usr/include/time.h /usr/include/sys/timespec.h
user.o: /usr/include/unistd.h /usr/include/sys/types.h
user.o: /usr/include/machine/endian.h /usr/include/sys/select.h
user.o: /usr/include/sys/_timeval.h /usr/include/sys/unistd.h
user.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
user.o: /usr/include/_ctype.h /usr/include/runetype.h
user.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
user.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h /usr/include/stdint.h
user.o: /usr/include/machine/_stdint.h
user.o: /usr/include/c++/4.2/bits/functexcept.h
user.o: /usr/include/c++/4.2/exception_defines.h
user.o: /usr/include/c++/4.2/bits/stl_pair.h
user.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
user.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
user.o: /usr/include/c++/4.2/bits/stl_relops.h
user.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
user.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
user.o: /usr/include/c++/4.2/bits/concept_check.h
user.o: /usr/include/c++/4.2/bits/stl_iterator.h
user.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
user.o: /usr/include/c++/4.2/bits/allocator.h
user.o: /usr/include/c++/4.2/bits/c++allocator.h
user.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
user.o: /usr/include/c++/4.2/exception
user.o: /usr/include/c++/4.2/bits/stl_construct.h
user.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
user.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
user.o: /usr/include/c++/4.2/limits
user.o: /usr/include/c++/4.2/bits/ostream_insert.h
user.o: /usr/include/c++/4.2/bits/stl_function.h
user.o: /usr/include/c++/4.2/bits/basic_string.h
user.o: /usr/include/c++/4.2/ext/atomicity.h
user.o: /usr/include/c++/4.2/bits/atomic_word.h
user.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
user.o: /usr/include/c++/4.2/bits/stl_heap.h
user.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
user.o: /usr/include/c++/4.2/bits/basic_string.tcc
user.o: /usr/local/include/nspr/prtypes.h /usr/local/include/nspr/prcpucfg.h
user.o: /usr/local/include/nspr/obsolete/protypes.h /usr/include/c++/4.2/list
user.o: /usr/include/c++/4.2/bits/stl_list.h
user.o: /usr/include/c++/4.2/bits/list.tcc
userhash.o: userhash.h user.h /usr/include/c++/4.2/string
userhash.o: /usr/include/c++/4.2/bits/c++config.h
userhash.o: /usr/include/c++/4.2/bits/os_defines.h
userhash.o: /usr/include/c++/4.2/bits/cpu_defines.h
userhash.o: /usr/include/c++/4.2/bits/stringfwd.h
userhash.o: /usr/include/c++/4.2/bits/char_traits.h
userhash.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
userhash.o: /usr/include/stddef.h /usr/include/sys/cdefs.h
userhash.o: /usr/include/sys/_null.h /usr/include/sys/_types.h
userhash.o: /usr/include/machine/_types.h /usr/include/string.h
userhash.o: /usr/include/strings.h /usr/include/c++/4.2/bits/stl_algobase.h
userhash.o: /usr/include/c++/4.2/climits /usr/include/limits.h
userhash.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
userhash.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
userhash.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
userhash.o: /usr/include/c++/4.2/bits/c++locale.h
userhash.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
userhash.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
userhash.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
userhash.o: /usr/include/c++/4.2/bits/c++io.h
userhash.o: /usr/include/c++/4.2/bits/gthr.h
userhash.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
userhash.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
userhash.o: /usr/include/sched.h /usr/include/time.h
userhash.o: /usr/include/sys/timespec.h /usr/include/unistd.h
userhash.o: /usr/include/sys/types.h /usr/include/machine/endian.h
userhash.o: /usr/include/sys/select.h /usr/include/sys/_timeval.h
userhash.o: /usr/include/sys/unistd.h /usr/include/c++/4.2/cctype
userhash.o: /usr/include/ctype.h /usr/include/_ctype.h
userhash.o: /usr/include/runetype.h /usr/include/c++/4.2/bits/postypes.h
userhash.o: /usr/include/c++/4.2/cwchar /usr/include/c++/4.2/ctime
userhash.o: /usr/include/wchar.h /usr/include/stdint.h
userhash.o: /usr/include/machine/_stdint.h
userhash.o: /usr/include/c++/4.2/bits/functexcept.h
userhash.o: /usr/include/c++/4.2/exception_defines.h
userhash.o: /usr/include/c++/4.2/bits/stl_pair.h
userhash.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
userhash.o: /usr/include/c++/4.2/ext/type_traits.h
userhash.o: /usr/include/c++/4.2/utility
userhash.o: /usr/include/c++/4.2/bits/stl_relops.h
userhash.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
userhash.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
userhash.o: /usr/include/c++/4.2/bits/concept_check.h
userhash.o: /usr/include/c++/4.2/bits/stl_iterator.h
userhash.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
userhash.o: /usr/include/c++/4.2/bits/allocator.h
userhash.o: /usr/include/c++/4.2/bits/c++allocator.h
userhash.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
userhash.o: /usr/include/c++/4.2/exception
userhash.o: /usr/include/c++/4.2/bits/stl_construct.h
userhash.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
userhash.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
userhash.o: /usr/include/c++/4.2/limits
userhash.o: /usr/include/c++/4.2/bits/ostream_insert.h
userhash.o: /usr/include/c++/4.2/bits/stl_function.h
userhash.o: /usr/include/c++/4.2/bits/basic_string.h
userhash.o: /usr/include/c++/4.2/ext/atomicity.h
userhash.o: /usr/include/c++/4.2/bits/atomic_word.h
userhash.o: /usr/include/c++/4.2/algorithm
userhash.o: /usr/include/c++/4.2/bits/stl_algo.h
userhash.o: /usr/include/c++/4.2/bits/stl_heap.h
userhash.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
userhash.o: /usr/include/c++/4.2/bits/basic_string.tcc
userhash.o: /usr/local/include/nspr/prtypes.h
userhash.o: /usr/local/include/nspr/prcpucfg.h
userhash.o: /usr/local/include/nspr/obsolete/protypes.h
userhash.o: /usr/include/c++/4.2/list /usr/include/c++/4.2/bits/stl_list.h
userhash.o: /usr/include/c++/4.2/bits/list.tcc
userhash.o: /usr/local/include/nspr/prlock.h config.h /usr/include/errno.h
file.o: file.h /usr/include/c++/4.2/string
file.o: /usr/include/c++/4.2/bits/c++config.h
file.o: /usr/include/c++/4.2/bits/os_defines.h
file.o: /usr/include/c++/4.2/bits/cpu_defines.h
file.o: /usr/include/c++/4.2/bits/stringfwd.h
file.o: /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring
file.o: /usr/include/c++/4.2/cstddef /usr/include/stddef.h
file.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
file.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
file.o: /usr/include/string.h /usr/include/strings.h
file.o: /usr/include/c++/4.2/bits/stl_algobase.h /usr/include/c++/4.2/climits
file.o: /usr/include/limits.h /usr/include/sys/limits.h
file.o: /usr/include/machine/_limits.h /usr/include/sys/syslimits.h
file.o: /usr/include/c++/4.2/cstdlib /usr/include/stdlib.h
file.o: /usr/include/c++/4.2/iosfwd /usr/include/c++/4.2/bits/c++locale.h
file.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
file.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
file.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
file.o: /usr/include/c++/4.2/bits/c++io.h /usr/include/c++/4.2/bits/gthr.h
file.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
file.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
file.o: /usr/include/sched.h /usr/include/time.h /usr/include/sys/timespec.h
file.o: /usr/include/unistd.h /usr/include/sys/types.h
file.o: /usr/include/machine/endian.h /usr/include/sys/select.h
file.o: /usr/include/sys/_timeval.h /usr/include/sys/unistd.h
file.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
file.o: /usr/include/_ctype.h /usr/include/runetype.h
file.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
file.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h /usr/include/stdint.h
file.o: /usr/include/machine/_stdint.h
file.o: /usr/include/c++/4.2/bits/functexcept.h
file.o: /usr/include/c++/4.2/exception_defines.h
file.o: /usr/include/c++/4.2/bits/stl_pair.h
file.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
file.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
file.o: /usr/include/c++/4.2/bits/stl_relops.h
file.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
file.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
file.o: /usr/include/c++/4.2/bits/concept_check.h
file.o: /usr/include/c++/4.2/bits/stl_iterator.h
file.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
file.o: /usr/include/c++/4.2/bits/allocator.h
file.o: /usr/include/c++/4.2/bits/c++allocator.h
file.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
file.o: /usr/include/c++/4.2/exception
file.o: /usr/include/c++/4.2/bits/stl_construct.h
file.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
file.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
file.o: /usr/include/c++/4.2/limits
file.o: /usr/include/c++/4.2/bits/ostream_insert.h
file.o: /usr/include/c++/4.2/bits/stl_function.h
file.o: /usr/include/c++/4.2/bits/basic_string.h
file.o: /usr/include/c++/4.2/ext/atomicity.h
file.o: /usr/include/c++/4.2/bits/atomic_word.h
file.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
file.o: /usr/include/c++/4.2/bits/stl_heap.h
file.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
file.o: /usr/include/c++/4.2/bits/basic_string.tcc block.h datahash.h
file.o: /usr/local/include/nspr/prtypes.h /usr/local/include/nspr/prcpucfg.h
file.o: /usr/local/include/nspr/obsolete/protypes.h
file.o: /usr/local/include/nspr/prio.h /usr/local/include/nspr/prlong.h
file.o: /usr/local/include/nspr/prtime.h /usr/local/include/nspr/prinrval.h
file.o: /usr/local/include/nspr/prinet.h /usr/include/sys/socket.h
file.o: /usr/include/sys/_iovec.h /usr/include/machine/param.h
file.o: /usr/include/netinet/in.h /usr/include/netinet6/in6.h
file.o: /usr/include/arpa/inet.h /usr/include/netdb.h
file.o: /usr/include/rpc/types.h /usr/include/sys/time.h
file.o: /usr/include/netconfig.h /usr/local/include/nspr/prlock.h config.h
file.o: /usr/include/errno.h
datahash.o: datahash.h /usr/include/c++/4.2/string
datahash.o: /usr/include/c++/4.2/bits/c++config.h
datahash.o: /usr/include/c++/4.2/bits/os_defines.h
datahash.o: /usr/include/c++/4.2/bits/cpu_defines.h
datahash.o: /usr/include/c++/4.2/bits/stringfwd.h
datahash.o: /usr/include/c++/4.2/bits/char_traits.h
datahash.o: /usr/include/c++/4.2/cstring /usr/include/c++/4.2/cstddef
datahash.o: /usr/include/stddef.h /usr/include/sys/cdefs.h
datahash.o: /usr/include/sys/_null.h /usr/include/sys/_types.h
datahash.o: /usr/include/machine/_types.h /usr/include/string.h
datahash.o: /usr/include/strings.h /usr/include/c++/4.2/bits/stl_algobase.h
datahash.o: /usr/include/c++/4.2/climits /usr/include/limits.h
datahash.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
datahash.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
datahash.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
datahash.o: /usr/include/c++/4.2/bits/c++locale.h
datahash.o: /usr/include/c++/4.2/clocale /usr/include/locale.h
datahash.o: /usr/include/c++/4.2/cstdio /usr/include/stdio.h
datahash.o: /usr/include/c++/4.2/cstdarg /usr/include/stdarg.h
datahash.o: /usr/include/c++/4.2/bits/c++io.h
datahash.o: /usr/include/c++/4.2/bits/gthr.h
datahash.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
datahash.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
datahash.o: /usr/include/sched.h /usr/include/time.h
datahash.o: /usr/include/sys/timespec.h /usr/include/unistd.h
datahash.o: /usr/include/sys/types.h /usr/include/machine/endian.h
datahash.o: /usr/include/sys/select.h /usr/include/sys/_timeval.h
datahash.o: /usr/include/sys/unistd.h /usr/include/c++/4.2/cctype
datahash.o: /usr/include/ctype.h /usr/include/_ctype.h
datahash.o: /usr/include/runetype.h /usr/include/c++/4.2/bits/postypes.h
datahash.o: /usr/include/c++/4.2/cwchar /usr/include/c++/4.2/ctime
datahash.o: /usr/include/wchar.h /usr/include/stdint.h
datahash.o: /usr/include/machine/_stdint.h
datahash.o: /usr/include/c++/4.2/bits/functexcept.h
datahash.o: /usr/include/c++/4.2/exception_defines.h
datahash.o: /usr/include/c++/4.2/bits/stl_pair.h
datahash.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
datahash.o: /usr/include/c++/4.2/ext/type_traits.h
datahash.o: /usr/include/c++/4.2/utility
datahash.o: /usr/include/c++/4.2/bits/stl_relops.h
datahash.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
datahash.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
datahash.o: /usr/include/c++/4.2/bits/concept_check.h
datahash.o: /usr/include/c++/4.2/bits/stl_iterator.h
datahash.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
datahash.o: /usr/include/c++/4.2/bits/allocator.h
datahash.o: /usr/include/c++/4.2/bits/c++allocator.h
datahash.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
datahash.o: /usr/include/c++/4.2/exception
datahash.o: /usr/include/c++/4.2/bits/stl_construct.h
datahash.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
datahash.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
datahash.o: /usr/include/c++/4.2/limits
datahash.o: /usr/include/c++/4.2/bits/ostream_insert.h
datahash.o: /usr/include/c++/4.2/bits/stl_function.h
datahash.o: /usr/include/c++/4.2/bits/basic_string.h
datahash.o: /usr/include/c++/4.2/ext/atomicity.h
datahash.o: /usr/include/c++/4.2/bits/atomic_word.h
datahash.o: /usr/include/c++/4.2/algorithm
datahash.o: /usr/include/c++/4.2/bits/stl_algo.h
datahash.o: /usr/include/c++/4.2/bits/stl_heap.h
datahash.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
datahash.o: /usr/include/c++/4.2/bits/basic_string.tcc
block.o: block.h datahash.h /usr/include/c++/4.2/string
block.o: /usr/include/c++/4.2/bits/c++config.h
block.o: /usr/include/c++/4.2/bits/os_defines.h
block.o: /usr/include/c++/4.2/bits/cpu_defines.h
block.o: /usr/include/c++/4.2/bits/stringfwd.h
block.o: /usr/include/c++/4.2/bits/char_traits.h /usr/include/c++/4.2/cstring
block.o: /usr/include/c++/4.2/cstddef /usr/include/stddef.h
block.o: /usr/include/sys/cdefs.h /usr/include/sys/_null.h
block.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
block.o: /usr/include/string.h /usr/include/strings.h
block.o: /usr/include/c++/4.2/bits/stl_algobase.h
block.o: /usr/include/c++/4.2/climits /usr/include/limits.h
block.o: /usr/include/sys/limits.h /usr/include/machine/_limits.h
block.o: /usr/include/sys/syslimits.h /usr/include/c++/4.2/cstdlib
block.o: /usr/include/stdlib.h /usr/include/c++/4.2/iosfwd
block.o: /usr/include/c++/4.2/bits/c++locale.h /usr/include/c++/4.2/clocale
block.o: /usr/include/locale.h /usr/include/c++/4.2/cstdio
block.o: /usr/include/stdio.h /usr/include/c++/4.2/cstdarg
block.o: /usr/include/stdarg.h /usr/include/c++/4.2/bits/c++io.h
block.o: /usr/include/c++/4.2/bits/gthr.h
block.o: /usr/include/c++/4.2/bits/gthr-default.h /usr/include/pthread.h
block.o: /usr/include/sys/_pthreadtypes.h /usr/include/sys/_sigset.h
block.o: /usr/include/sched.h /usr/include/time.h /usr/include/sys/timespec.h
block.o: /usr/include/unistd.h /usr/include/sys/types.h
block.o: /usr/include/machine/endian.h /usr/include/sys/select.h
block.o: /usr/include/sys/_timeval.h /usr/include/sys/unistd.h
block.o: /usr/include/c++/4.2/cctype /usr/include/ctype.h
block.o: /usr/include/_ctype.h /usr/include/runetype.h
block.o: /usr/include/c++/4.2/bits/postypes.h /usr/include/c++/4.2/cwchar
block.o: /usr/include/c++/4.2/ctime /usr/include/wchar.h
block.o: /usr/include/stdint.h /usr/include/machine/_stdint.h
block.o: /usr/include/c++/4.2/bits/functexcept.h
block.o: /usr/include/c++/4.2/exception_defines.h
block.o: /usr/include/c++/4.2/bits/stl_pair.h
block.o: /usr/include/c++/4.2/bits/cpp_type_traits.h
block.o: /usr/include/c++/4.2/ext/type_traits.h /usr/include/c++/4.2/utility
block.o: /usr/include/c++/4.2/bits/stl_relops.h
block.o: /usr/include/c++/4.2/bits/stl_iterator_base_types.h
block.o: /usr/include/c++/4.2/bits/stl_iterator_base_funcs.h
block.o: /usr/include/c++/4.2/bits/concept_check.h
block.o: /usr/include/c++/4.2/bits/stl_iterator.h
block.o: /usr/include/c++/4.2/debug/debug.h /usr/include/c++/4.2/memory
block.o: /usr/include/c++/4.2/bits/allocator.h
block.o: /usr/include/c++/4.2/bits/c++allocator.h
block.o: /usr/include/c++/4.2/ext/new_allocator.h /usr/include/c++/4.2/new
block.o: /usr/include/c++/4.2/exception
block.o: /usr/include/c++/4.2/bits/stl_construct.h
block.o: /usr/include/c++/4.2/bits/stl_uninitialized.h
block.o: /usr/include/c++/4.2/bits/stl_raw_storage_iter.h
block.o: /usr/include/c++/4.2/limits
block.o: /usr/include/c++/4.2/bits/ostream_insert.h
block.o: /usr/include/c++/4.2/bits/stl_function.h
block.o: /usr/include/c++/4.2/bits/basic_string.h
block.o: /usr/include/c++/4.2/ext/atomicity.h
block.o: /usr/include/c++/4.2/bits/atomic_word.h
block.o: /usr/include/c++/4.2/algorithm /usr/include/c++/4.2/bits/stl_algo.h
block.o: /usr/include/c++/4.2/bits/stl_heap.h
block.o: /usr/include/c++/4.2/bits/stl_tempbuf.h
block.o: /usr/include/c++/4.2/bits/basic_string.tcc
datahasher.o: datahasher.h
