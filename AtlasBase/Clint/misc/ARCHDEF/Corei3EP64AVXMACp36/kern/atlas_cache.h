/* generated by ATLAS/tune/sysinfo/cacheInfo_x86.c */
#ifndef ATLAS_CACHE_H
   #define ATLAS_CACHE_H 1
#define x86_NHYPTHR 2 /* hyperthreading number */
#define x86_NCORPAK 32 /* ncores per package */

#define L1C_SZ 32768L
#define L1C_LS 64
#define L1C_NSET 64
#define L1C_NWAY 8
#define L1C_INCLUSIVE 1
#define L1C_NSHARE 1
#define L1C_SURE 1
#ifdef SREAL
   #define L1C_ELTS 8192
   #define L1C_LSELTS 16
#elif defined(DREAL) || defined(SCPLX)
   #define L1C_ELTS 4096
   #define L1C_LSELTS 8
#elif defined(DCPLX)
   #define L1C_ELTS 2048
   #define L1C_LSELTS 4
#endif

#define L1C_SZ 32768L
#define L1C_LS 64
#define L1C_NSET 64
#define L1C_NWAY 8
#define L1C_NSHARE 1
#define L1C_SURE 1
#ifdef SREAL
   #define L1C_ELTS 8192L
   #define L1C_LSELTS 16
#elif defined(DREAL) || defined(SCPLX)
   #define L1C_ELTS 4096L
   #define L1C_LSELTS 8
#elif defined(DCPLX)
   #define L1C_ELTS 2048L
   #define L1C_LSELTS 4
#endif

#define L2C_SZ 262144L
#define L2C_LS 64
#define L2C_NSET 512
#define L2C_NWAY 8
#define L2C_INCLUSIVE 0
#define L2C_NSHARE 1
#define L2C_SURE 1
#ifdef SREAL
   #define L2C_ELTS 65536L
   #define L2C_LSELTS 16
#elif defined(DREAL) || defined(SCPLX)
   #define L2C_ELTS 32768L
   #define L2C_LSELTS 8
#elif defined(DCPLX)
   #define L2C_ELTS 16384L
   #define L2C_LSELTS 4
#endif

#define L3C_SZ 1474560L
#define L3C_LS 64
#define L3C_NSET 36864
#define L3C_NWAY 20
#define L3C_INCLUSIVE 1
#define L3C_NSHARE 32
#define L3C_SURE 1
#ifdef SREAL
   #define L3C_ELTS 368640L
   #define L3C_LSELTS 16
#elif defined(DREAL) || defined(SCPLX)
   #define L3C_ELTS 184320L
   #define L3C_LSELTS 8
#elif defined(DCPLX)
   #define L3C_ELTS 92160L
   #define L3C_LSELTS 4
#endif

#define LLPC_LVL 2
#define LLPC_SZ  L2C_SZ
#define LLPC_LSELTS L2C_LSELTS
#define LLC_LVL 3
#define LLC_LSELTS L3C_LSELTS
#define LLC_SZ   L3C_SZ
#define LLC_ELTS L3C_ELTS
#define ATL_SAFELS 64

#define TLB_PLVLS 1
#define TLB_LVLS 2
#define NTLB0 100
#define NTLB1 1552
#define TOTPTLB 100
#define TOTTLB 1652

#endif /* done multiple inclusion guard */
