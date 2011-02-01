/* This file generated by /home/whaley/TEST/ATLAS3.9.25.6/obj32/..//tune/blas/gemm/txover.c
 */
#ifndef ATL_TXOVER_H
   #define ATL_TXOVER_H 1

   #define ATL_PDIM 7
static const int ATL_tmmNN_SQmnk_XO[7] = 
   {0,61,68,86,129,231,0};
static const int ATL_tmmNT_SQmnk_XO[7] = 
   {0,0,67,75,134,253,523};
static const int ATL_tmmTN_SQmnk_XO[7] = 
   {0,0,66,107,129,219,422};
#define ATL_tmmTT_SQmnk_XO ATL_tmmNN_SQmnk_XO
static const int *ATL_tmm_SQmnk_XO[4] =
{ATL_tmmNN_SQmnk_XO, ATL_tmmNT_SQmnk_XO,
 ATL_tmmTN_SQmnk_XO, ATL_tmmTT_SQmnk_XO};
static const int ATL_tmmNN_SmnLk_XO[63] = 
   {0,0,0,0,0,0,0,0,0,3419,0,0,0,0,0,0,3071,0,0,0,0,0,0,1300,3552,0,0,0,0,0,421,1460,0,0,0,0,0,131,489,1117,0,0,0,0,32,1043,0,0,0,0,0,16,23,73,638,0,0,0,16,0,23,0,0};
static const int ATL_tmmNT_SmnLk_XO[63] = 
   {0,0,0,0,0,0,0,0,0,2964,0,0,0,0,0,0,2964,0,0,0,0,0,0,1239,3558,0,0,0,0,0,467,1385,3636,0,0,0,0,123,723,1368,0,0,0,0,38,107,342,0,0,0,16,0,28,65,1074,0,0,0,0,16,24,288,1043};
static const int ATL_tmmTN_SmnLk_XO[63] = 
   {0,0,0,0,0,0,0,0,0,3536,0,0,0,0,0,0,3536,0,0,0,0,0,0,1222,4265,0,0,0,0,0,448,1670,0,0,0,0,0,167,412,3858,0,0,0,0,40,81,435,4410,0,0,0,16,21,189,670,3008,0,0,0,16,22,226,0};
#define ATL_tmmTT_SmnLk_XO ATL_tmmNN_SmnLk_XO
static const int *ATL_tmm_SmnLk_XO[4] =
{ATL_tmmNN_SmnLk_XO, ATL_tmmNT_SmnLk_XO,
 ATL_tmmTN_SmnLk_XO, ATL_tmmTT_SmnLk_XO};
static const int ATL_tmmNN_SmkLn_XO[63] = 
   {0,3697,4073,0,0,0,0,0,0,3321,0,0,0,0,0,0,3321,6000,0,0,0,0,0,1239,3476,0,0,0,0,0,431,1451,3059,0,0,0,0,119,0,3110,0,0,0,0,35,92,1535,3008,0,0,0,16,35,92,718,3475,0,0,0,16,36,182,5345};
static const int ATL_tmmNT_SmkLn_XO[63] = 
   {0,0,3830,0,0,0,0,0,0,2695,0,0,0,0,0,0,2695,0,0,0,0,0,0,1194,0,0,0,0,0,0,357,1444,4254,0,0,0,0,121,494,3390,0,0,0,0,36,124,284,0,0,0,0,16,37,100,0,5813,0,0,16,21,39,269,752};
#define ATL_tmmTN_SmkLn_XO ATL_tmmNN_SmkLn_XO
#define ATL_tmmTT_SmkLn_XO ATL_tmmNT_SmkLn_XO
static const int *ATL_tmm_SmkLn_XO[4] =
{ATL_tmmNN_SmkLn_XO, ATL_tmmNT_SmkLn_XO,
 ATL_tmmTN_SmkLn_XO, ATL_tmmTT_SmkLn_XO};
static const int ATL_tmmNN_SnkLm_XO[63] = 
   {3612,5403,0,0,0,0,0,0,0,3612,0,0,0,0,0,0,3612,0,0,0,0,0,1070,1252,3645,0,0,0,0,0,421,1462,5539,0,0,0,0,104,421,1640,0,0,0,0,32,80,272,0,0,0,0,16,37,74,705,0,0,0,0,16,33,204,1020};
#define ATL_tmmNT_SnkLm_XO ATL_tmmNN_SnkLm_XO
static const int ATL_tmmTN_SnkLm_XO[63] = 
   {2877,0,0,0,0,0,0,0,2877,3072,0,0,0,0,0,0,2877,0,0,0,0,0,1005,1184,3536,0,0,0,0,0,368,1412,0,0,0,0,0,128,416,1057,0,0,0,0,32,80,272,0,0,0,0,16,32,0,2101,3943,0,0,0,16,33,1518,1979};
#define ATL_tmmTT_SnkLm_XO ATL_tmmTN_SnkLm_XO
static const int *ATL_tmm_SnkLm_XO[4] =
{ATL_tmmNN_SnkLm_XO, ATL_tmmNT_SnkLm_XO,
 ATL_tmmTN_SnkLm_XO, ATL_tmmTT_SnkLm_XO};
static const int ATL_tmmNN_SmLnk_XO[63] = 
   {0,0,159,291,512,3639,0,0,0,159,1004,0,0,3516,0,0,132,262,512,0,3879,0,0,132,268,512,0,0,0,102,138,258,539,2647,0,0,0,67,134,272,2149,0,0,0,52,75,136,374,2138,0,0,29,53,94,0,643,0,0,22,41,85,265,0};
static const int ATL_tmmNT_SmLnk_XO[63] = 
   {0,0,140,281,519,2355,3517,0,0,140,257,519,3879,0,0,0,140,266,950,1737,0,0,0,140,0,0,1376,0,0,0,140,264,521,1362,3139,0,0,66,132,325,862,0,0,0,45,88,133,396,899,0,0,31,63,117,277,843,0,0,21,37,86,240,591};
static const int ATL_tmmTN_SmLnk_XO[63] = 
   {0,0,173,281,518,0,0,0,0,158,263,527,2191,0,0,0,143,335,515,0,3032,0,0,131,256,513,0,0,0,103,139,262,847,0,3139,0,0,67,136,0,889,3134,0,0,45,86,129,476,2140,0,32,32,63,105,0,1544,0,0,22,42,69,302,498};
static const int ATL_tmmTT_SmLnk_XO[63] = 
   {0,0,164,287,1152,0,4000,0,0,164,262,515,1212,0,0,164,164,259,639,3153,0,0,0,133,259,540,0,0,0,0,133,268,519,1858,2895,0,0,73,133,310,714,1748,0,0,53,128,0,384,0,0,0,28,53,110,432,2134,0,0,20,55,0,196,498};
static const int *ATL_tmm_SmLnk_XO[4] =
{ATL_tmmNN_SmLnk_XO, ATL_tmmNT_SmLnk_XO,
 ATL_tmmTN_SmLnk_XO, ATL_tmmTT_SmLnk_XO};
static const int ATL_tmmNN_SnLmk_XO[63] = 
   {0,0,169,364,518,2203,0,0,169,169,282,535,2428,0,0,0,132,0,516,1278,3395,0,0,132,277,521,0,2056,0,112,128,267,526,0,0,0,0,66,134,264,611,2274,0,0,57,87,147,414,0,0,0,27,65,123,292,937,0,0,22,43,71,0,373};
static const int ATL_tmmNT_SnLmk_XO[63] = 
   {0,0,176,393,532,2320,0,0,0,162,264,527,1181,0,0,0,162,258,645,1478,3516,0,0,130,262,517,1405,3395,0,0,130,268,0,1058,3017,0,0,68,130,259,602,2520,0,0,54,81,150,0,1610,0,28,28,50,100,340,2507,0,0,21,37,72,241,466};
static const int ATL_tmmTN_SnLmk_XO[63] = 
   {0,0,164,364,658,0,0,0,0,164,275,522,1512,4000,0,164,164,264,746,1308,4000,0,0,131,263,1077,1913,0,0,0,131,266,519,1029,2526,0,0,70,130,264,622,2271,0,0,50,84,189,1492,1797,0,0,30,54,107,326,3129,0,0,23,47,78,0,514};
static const int ATL_tmmTT_SnLmk_XO[63] = 
   {0,0,173,367,550,2012,3280,0,161,167,349,521,2197,4000,0,0,155,333,513,0,3637,0,0,130,275,519,2206,2905,0,110,131,256,651,1196,3633,0,90,0,129,262,696,1407,0,0,51,82,146,438,3504,0,0,33,64,89,377,2135,0,0,23,46,77,237,560};
static const int *ATL_tmm_SnLmk_XO[4] =
{ATL_tmmNN_SnLmk_XO, ATL_tmmNT_SnLmk_XO,
 ATL_tmmTN_SnLmk_XO, ATL_tmmTT_SnLmk_XO};
static const int ATL_tmmNN_SkLmn_XO[63] = 
   {0,0,153,298,541,1534,0,0,0,153,298,463,1102,2917,0,0,153,256,402,1332,2534,0,0,93,189,361,0,0,0,0,87,137,353,0,3016,0,0,66,111,186,710,1541,0,0,66,66,159,531,0,0,0,36,67,137,382,1547,0,26,26,37,133,251,435};
static const int ATL_tmmNT_SkLmn_XO[63] = 
   {0,0,178,275,566,1689,3761,0,0,178,244,469,1537,0,0,0,157,212,454,1320,0,0,103,103,222,378,2165,0,0,0,87,150,321,869,0,0,0,73,97,212,587,0,0,0,66,85,150,601,1150,0,0,36,65,130,397,1423,0,27,27,39,140,238,2132};
static const int ATL_tmmTN_SkLmn_XO[63] = 
   {0,0,147,277,527,1365,3397,0,0,147,263,487,1019,3638,0,147,147,250,340,2225,3878,0,101,101,208,330,1652,2532,0,0,86,182,324,0,1974,0,0,73,100,396,707,2524,0,0,65,0,0,1334,1963,0,50,64,70,142,291,2138,0,28,28,40,151,214,2132};
#define ATL_tmmTT_SkLmn_XO ATL_tmmNN_SkLmn_XO
static const int *ATL_tmm_SkLmn_XO[4] =
{ATL_tmmNN_SkLmn_XO, ATL_tmmNT_SkLmn_XO,
 ATL_tmmTN_SkLmn_XO, ATL_tmmTT_SkLmn_XO};

#endif /* end ifndef ATL_TXOVER_H */
