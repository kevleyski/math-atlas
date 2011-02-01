/* This file generated by /home/whaley/TEST/ATLAS3.9.25.6/obj64/..//tune/blas/gemm/txover.c
*/
#ifndef ATL_TXOVER_H
#define ATL_TXOVER_H 1

#define ATL_PDIM 7
static const int ATL_tmmNN_SQmnk_XO[7] =
{0,0,101,222,762,0,0};
static const int ATL_tmmNT_SQmnk_XO[7] =
{0,0,93,98,160,180,662};
static const int ATL_tmmTN_SQmnk_XO[7] =
{0,76,85,0,210,0,0};
#define ATL_tmmTT_SQmnk_XO ATL_tmmNN_SQmnk_XO
static const int *ATL_tmm_SQmnk_XO[4] =
{ATL_tmmNN_SQmnk_XO, ATL_tmmNT_SQmnk_XO,
ATL_tmmTN_SQmnk_XO, ATL_tmmTT_SQmnk_XO};
static const int ATL_tmmNN_SmnLk_XO[63] =
{0,0,0,0,0,0,0,0,0,3889,0,0,0,0,0,0,3889,0,0,0,0,0,0,1423,4993,0,0,0,0,0,600,1453,0,0,0,0,0,242,7386,0,0,0,0,144,0,219,5396,7501,0,0,0,20,0,0,0,0,0,0,20,0,0,5256,0};
static const int ATL_tmmNT_SmnLk_XO[63] =
{0,0,0,0,0,0,0,0,6748,0,0,0,0,0,0,0,6748,0,0,0,0,0,6748,0,0,0,0,0,0,726,0,0,0,0,0,0,0,242,1504,7143,0,0,0,170,0,206,0,0,0,0,0,20,31,0,767,0,0,0,20,168,0,2139,0};
static const int ATL_tmmTN_SmnLk_XO[63] =
{0,0,0,0,0,0,0,0,0,3834,0,0,0,0,0,0,3834,0,0,0,0,0,0,1498,7202,0,0,0,0,0,713,1407,0,0,0,0,0,223,0,3125,0,0,0,0,0,201,549,0,0,0,0,20,56,0,813,0,0,0,20,0,4134,0,0};
#define ATL_tmmTT_SmnLk_XO ATL_tmmNN_SmnLk_XO
static const int *ATL_tmm_SmnLk_XO[4] =
{ATL_tmmNN_SmnLk_XO, ATL_tmmNT_SmnLk_XO,
ATL_tmmTN_SmnLk_XO, ATL_tmmTT_SmnLk_XO};
static const int ATL_tmmNN_SmkLn_XO[63] =
{0,0,7579,0,0,0,0,0,0,5308,0,0,0,0,0,0,5308,0,0,0,0,0,4411,4411,0,0,0,0,0,0,592,0,6416,0,0,0,0,204,639,0,0,0,0,0,84,161,4685,7127,0,0,26,44,84,169,3511,0,0,0,20,45,0,844,0};
static const int ATL_tmmNT_SmkLn_XO[63] =
{0,0,6114,0,0,0,0,0,0,3978,0,0,0,0,0,0,3978,0,0,0,0,0,3710,0,4290,0,0,0,0,0,580,1328,0,0,0,0,0,203,802,5772,0,0,0,0,80,0,0,0,0,0,26,45,568,4042,7376,0,0,0,20,42,94,895,1266};
#define ATL_tmmTN_SmkLn_XO ATL_tmmNN_SmkLn_XO
#define ATL_tmmTT_SmkLn_XO ATL_tmmNT_SmkLn_XO
static const int *ATL_tmm_SmkLn_XO[4] =
{ATL_tmmNN_SmkLn_XO, ATL_tmmNT_SmkLn_XO,
ATL_tmmTN_SmkLn_XO, ATL_tmmTT_SmkLn_XO};
static const int ATL_tmmNN_SnkLm_XO[63] =
{0,0,8000,0,0,0,0,0,0,3361,0,0,0,0,0,0,3361,0,0,0,0,0,0,1685,6485,0,0,0,0,0,549,2935,3712,0,0,0,0,160,498,0,0,0,0,0,82,175,377,0,0,0,20,44,85,229,5131,0,0,0,20,0,82,162,6129};
#define ATL_tmmNT_SnkLm_XO ATL_tmmNN_SnkLm_XO
static const int ATL_tmmTN_SnkLm_XO[63] =
{0,0,0,0,0,0,0,0,3794,5962,0,0,0,0,0,0,3794,0,0,0,0,0,2393,0,0,0,0,0,0,0,525,3106,0,0,0,0,0,171,0,2029,0,0,0,0,81,172,346,0,0,0,20,44,84,169,892,0,0,0,20,44,84,2388,4010};
#define ATL_tmmTT_SnkLm_XO ATL_tmmTN_SnkLm_XO
static const int *ATL_tmm_SnkLm_XO[4] =
{ATL_tmmNN_SnkLm_XO, ATL_tmmNT_SnkLm_XO,
ATL_tmmTN_SnkLm_XO, ATL_tmmTT_SnkLm_XO};
static const int ATL_tmmNN_SmLnk_XO[63] =
{0,0,323,0,652,0,0,0,0,0,323,658,1758,4000,0,0,0,323,717,1557,0,0,0,0,323,652,2161,4000,0,0,0,323,0,1436,2965,0,0,0,323,1221,2164,0,0,0,84,171,401,979,1396,0,33,40,84,160,1602,3130,0,0,26,44,85,252,0};
static const int ATL_tmmNT_SmLnk_XO[63] =
{0,0,204,432,692,0,0,0,204,268,330,821,1843,0,0,0,167,419,671,3041,0,0,0,167,331,0,0,0,0,0,167,0,669,1298,3880,0,167,167,0,645,1414,2894,0,68,101,188,324,778,0,0,35,46,84,162,366,707,0,0,25,42,92,486,1636};
static const int ATL_tmmTN_SmLnk_XO[63] =
{0,0,266,0,0,0,0,0,0,266,345,645,1422,0,0,0,165,329,644,3400,4000,0,0,165,354,0,1545,0,0,122,160,533,649,1697,0,0,122,161,330,0,1567,0,0,60,0,0,0,1297,2515,0,0,41,118,169,392,655,0,36,42,0,308,2134,0};
static const int ATL_tmmTT_SmLnk_XO[63] =
{0,280,0,0,654,4000,0,0,0,176,325,1240,0,3520,0,0,167,0,644,0,3760,0,0,167,401,645,3303,3757,0,125,161,324,0,1403,3273,0,125,171,325,0,1580,0,0,0,80,0,823,3132,0,0,38,45,87,162,381,806,0,31,31,42,80,299,1729};
static const int *ATL_tmm_SmLnk_XO[4] =
{ATL_tmmNN_SmLnk_XO, ATL_tmmNT_SmLnk_XO,
ATL_tmmTN_SmLnk_XO, ATL_tmmTT_SmLnk_XO};
static const int ATL_tmmNN_SnLmk_XO[63] =
{0,0,207,779,1302,0,0,0,207,0,374,1183,1582,3042,0,0,169,0,1275,0,0,0,0,169,0,1623,2908,0,0,123,162,334,645,2351,3878,0,123,168,320,652,0,3509,0,78,83,168,327,647,0,0,0,46,88,831,1592,2270,46,46,0,0,91,251,2134};
static const int ATL_tmmNT_SnLmk_XO[63] =
{0,0,0,1018,1100,1552,0,0,0,0,1018,0,3160,0,0,1018,0,0,2490,3400,0,0,0,166,983,1753,0,0,0,0,166,2662,0,0,3640,0,0,166,0,2000,2900,0,0,0,92,160,335,2143,0,0,0,41,83,177,327,1454,0,0,27,51,122,202,3377};
static const int ATL_tmmTN_SnLmk_XO[63] =
{0,0,0,0,0,1977,0,1977,0,0,0,2255,3880,0,0,0,167,323,0,0,3520,0,167,167,730,2029,0,3030,0,120,162,1211,0,0,0,0,120,160,593,0,0,3632,0,0,80,218,357,886,3261,0,61,72,106,274,320,1518,0,0,30,62,88,314,0};
static const int ATL_tmmTT_SnLmk_XO[63] =
{0,0,0,360,0,0,0,0,0,0,360,1668,2180,0,0,0,360,370,0,0,3090,0,0,360,0,0,0,4000,0,0,0,360,1907,3636,0,0,125,224,336,645,2147,3387,0,0,81,160,760,0,1416,0,63,0,0,168,328,865,0,0,28,0,89,268,0};
static const int *ATL_tmm_SnLmk_XO[4] =
{ATL_tmmNN_SnLmk_XO, ATL_tmmNT_SnLmk_XO,
ATL_tmmTN_SnLmk_XO, ATL_tmmTT_SnLmk_XO};
static const int ATL_tmmNN_SkLmn_XO[63] =
{0,391,441,1164,0,0,4000,0,180,0,2686,0,0,0,0,0,180,0,0,0,0,0,135,817,0,0,2732,3757,0,0,113,143,0,2652,0,0,0,83,168,220,0,3632,0,0,83,97,0,2886,0,0,0,42,86,496,1253,1455,0,28,0,153,0,258,469};
static const int ATL_tmmNT_SkLmn_XO[63] =
{0,0,185,0,590,0,0,0,172,172,285,618,1417,0,0,0,156,0,1337,0,3519,0,0,156,236,450,0,3756,0,0,109,549,0,2759,3510,0,0,80,229,646,0,0,0,0,80,109,0,1532,0,0,0,52,82,172,909,2766,0,0,52,0,170,501,517};
static const int ATL_tmmTN_SkLmn_XO[63] =
{0,0,0,471,0,2676,0,0,0,0,0,471,0,3006,0,0,0,0,471,0,3117,0,471,0,751,828,0,3758,0,136,228,0,262,0,3387,0,0,82,119,598,0,2004,0,70,80,86,0,291,2267,0,0,40,83,168,331,1422,0,0,26,47,166,254,1792};
#define ATL_tmmTT_SkLmn_XO ATL_tmmNN_SkLmn_XO
static const int *ATL_tmm_SkLmn_XO[4] =
{ATL_tmmNN_SkLmn_XO, ATL_tmmNT_SkLmn_XO,
ATL_tmmTN_SkLmn_XO, ATL_tmmTT_SkLmn_XO};

#endif /* end ifndef ATL_TXOVER_H */
