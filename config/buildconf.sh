# This file is auto-generated, changes made to it will be lost. Please edit makebuildscripts.py instead.

if [ -z "${SNIPER_ROOT}" ] ; then SNIPER_ROOT=$(readlink -f "$(dirname "${BASH_SOURCE[0]}")/..") ; fi

GRAPHITE_CC="/home/ssingh/GCC-4.6.2/bin/gcc"
GRAPHITE_CFLAGS="-mno-sse4 -mno-sse4.1 -mno-sse4.2 -mno-sse4a -mno-avx -mno-avx2 -I${SNIPER_ROOT}/include "
GRAPHITE_CXX="/home/ssingh/GCC-4.6.2/bin/g++"
GRAPHITE_CXXFLAGS="-mno-sse4 -mno-sse4.1 -mno-sse4.2 -mno-sse4a -mno-avx -mno-avx2 -I${SNIPER_ROOT}/include "
GRAPHITE_LD="/home/ssingh/GCC-4.6.2/bin/g++"
GRAPHITE_LDFLAGS="-static -L${SNIPER_ROOT}/lib -pthread "
GRAPHITE_LD_LIBRARY_PATH=""
GRAPHITE_UPCCFLAGS="-I${SNIPER_ROOT}/include  -link-with='/home/ssingh/GCC-4.6.2/bin/g++ -static -L${SNIPER_ROOT}/lib -pthread'"
PIN_HOME="/home/ssingh/sniper_trace_config/alberto_sniper/pin_kit"
SNIPER_CC="/home/ssingh/GCC-4.6.2/bin/gcc"
SNIPER_CFLAGS="-mno-sse4 -mno-sse4.1 -mno-sse4.2 -mno-sse4a -mno-avx -mno-avx2 -I${SNIPER_ROOT}/include "
SNIPER_CXX="/home/ssingh/GCC-4.6.2/bin/g++"
SNIPER_CXXFLAGS="-mno-sse4 -mno-sse4.1 -mno-sse4.2 -mno-sse4a -mno-avx -mno-avx2 -I${SNIPER_ROOT}/include "
SNIPER_LD="/home/ssingh/GCC-4.6.2/bin/g++"
SNIPER_LDFLAGS="-static -L${SNIPER_ROOT}/lib -pthread "
SNIPER_LD_LIBRARY_PATH=""
SNIPER_UPCCFLAGS="-I${SNIPER_ROOT}/include  -link-with='/home/ssingh/GCC-4.6.2/bin/g++ -static -L${SNIPER_ROOT}/lib -pthread'"
