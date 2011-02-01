/* This file generated by /home/whaley/TEST/ATLAS3.9.23.0/obj64/..//tune/blas/gemm/txover.c
 */
#ifndef ATL_TXOVER_H
   #define ATL_TXOVER_H 1

   #define ATL_PDIM 3
static const int ATL_tmmNN_SQmnk_XO[3] = 
   {98,98,196};
static const int ATL_tmmNT_SQmnk_XO[3] = 
   {99,99,107};
static const int ATL_tmmTN_SQmnk_XO[3] = 
   {100,100,188};
#define ATL_tmmTT_SQmnk_XO ATL_tmmNN_SQmnk_XO
static const int *ATL_tmm_SQmnk_XO[4] =
{ATL_tmmNN_SQmnk_XO, ATL_tmmNT_SQmnk_XO,
 ATL_tmmTN_SQmnk_XO, ATL_tmmTT_SQmnk_XO};
static const int ATL_tmmNN_SmnLk_XO[27] = 
   {0,4899,0,3866,3866,0,1548,2738,5568,0,926,5969,0,357,4055,111,212,435,97,192,1073,0,48,102,0,0,48};
static const int ATL_tmmNT_SmnLk_XO[27] = 
   {0,3020,0,1360,2293,0,1360,3241,5527,0,809,5020,0,374,2612,164,204,1239,98,196,576,0,48,102,0,0,48};
static const int ATL_tmmTN_SmnLk_XO[27] = 
   {0,0,0,4608,7507,0,0,2751,0,0,992,0,0,392,0,123,202,1062,97,193,339,0,48,2613,0,0,48};
#define ATL_tmmTT_SmnLk_XO ATL_tmmNN_SmnLk_XO
static const int *ATL_tmm_SmnLk_XO[4] =
{ATL_tmmNN_SmnLk_XO, ATL_tmmNT_SmnLk_XO,
 ATL_tmmTN_SmnLk_XO, ATL_tmmTT_SmnLk_XO};
static const int ATL_tmmNN_SmkLn_XO[27] = 
   {0,3453,7748,0,3453,6776,0,3346,5217,3346,6621,0,800,1675,2616,258,493,822,99,199,533,0,48,105,0,0,48};
static const int ATL_tmmNT_SmkLn_XO[27] = 
   {0,5510,0,0,5510,7930,0,3377,5549,3377,6693,0,800,1675,2616,258,496,830,97,195,523,0,48,105,0,0,48};
#define ATL_tmmTN_SmkLn_XO ATL_tmmNN_SmkLn_XO
#define ATL_tmmTT_SmkLn_XO ATL_tmmNT_SmkLn_XO
static const int *ATL_tmm_SmkLn_XO[4] =
{ATL_tmmNN_SmkLn_XO, ATL_tmmNT_SmkLn_XO,
 ATL_tmmTN_SmkLn_XO, ATL_tmmTT_SmkLn_XO};
static const int ATL_tmmNN_SnkLm_XO[27] = 
   {0,0,0,0,6542,0,0,2625,0,2625,6624,10000,808,1661,2745,226,354,918,99,199,533,0,48,100,0,0,48};
#define ATL_tmmNT_SnkLm_XO ATL_tmmNN_SnkLm_XO
static const int ATL_tmmTN_SnkLm_XO[27] = 
   {0,4576,0,2916,2916,0,0,1527,8741,1527,6621,0,800,1588,2503,208,349,899,99,199,533,0,48,397,0,0,48};
#define ATL_tmmTT_SnkLm_XO ATL_tmmTN_SnkLm_XO
static const int *ATL_tmm_SnkLm_XO[4] =
{ATL_tmmNN_SnkLm_XO, ATL_tmmNT_SnkLm_XO,
 ATL_tmmTN_SnkLm_XO, ATL_tmmTT_SnkLm_XO};
static const int ATL_tmmNN_SmLnk_XO[27] = 
   {0,0,244,0,119,233,0,119,233,0,119,290,119,140,213,98,129,224,98,98,210,48,97,105,0,48,105};
static const int ATL_tmmNT_SmLnk_XO[27] = 
   {0,0,245,0,131,199,0,131,221,0,119,233,119,140,213,98,126,213,98,98,210,48,97,105,0,48,105};
static const int ATL_tmmTN_SmLnk_XO[27] = 
   {147,159,249,0,147,216,125,137,227,125,125,215,113,129,224,98,126,213,98,98,210,48,97,105,0,48,105};
static const int ATL_tmmTT_SmLnk_XO[27] = 
   {0,290,479,0,290,479,0,290,568,0,290,601,0,0,290,290,681,1124,113,0,470,77,0,180,54,97,105};
static const int *ATL_tmm_SmLnk_XO[4] =
{ATL_tmmNN_SmLnk_XO, ATL_tmmNT_SmLnk_XO,
 ATL_tmmTN_SmLnk_XO, ATL_tmmTT_SmLnk_XO};
static const int ATL_tmmNN_SnLmk_XO[27] = 
   {145,183,247,0,145,205,126,138,228,126,126,227,112,112,213,0,98,213,98,98,210,48,97,105,0,48,105};
static const int ATL_tmmNT_SnLmk_XO[27] = 
   {0,131,245,0,131,199,0,131,222,0,131,221,119,140,213,98,126,213,98,98,210,48,97,105,0,48,105};
static const int ATL_tmmTN_SnLmk_XO[27] = 
   {148,173,250,0,148,217,126,141,251,0,126,227,112,112,213,98,112,213,98,98,210,48,97,105,0,48,105};
static const int ATL_tmmTT_SnLmk_XO[27] = 
   {0,254,388,0,254,1038,0,254,600,0,205,375,0,0,194,0,0,194,0,0,194,0,0,194,56,83,105};
static const int *ATL_tmm_SnLmk_XO[4] =
{ATL_tmmNN_SnLmk_XO, ATL_tmmNT_SnLmk_XO,
 ATL_tmmTN_SnLmk_XO, ATL_tmmTT_SnLmk_XO};
static const int ATL_tmmNN_SkLmn_XO[27] = 
   {0,0,343,343,463,576,251,336,439,166,238,387,124,133,237,99,127,214,99,99,198,48,97,105,0,48,105};
static const int ATL_tmmNT_SkLmn_XO[27] = 
   {0,177,233,0,177,585,177,332,439,155,232,313,130,141,237,99,127,214,99,99,198,48,97,105,0,48,105};
static const int ATL_tmmTN_SkLmn_XO[27] = 
   {0,0,251,0,0,251,251,336,439,166,238,387,124,133,237,99,127,214,99,99,198,48,97,105,0,48,105};
#define ATL_tmmTT_SkLmn_XO ATL_tmmNN_SkLmn_XO
static const int *ATL_tmm_SkLmn_XO[4] =
{ATL_tmmNN_SkLmn_XO, ATL_tmmNT_SkLmn_XO,
 ATL_tmmTN_SkLmn_XO, ATL_tmmTT_SkLmn_XO};

#endif /* end ifndef ATL_TXOVER_H */
