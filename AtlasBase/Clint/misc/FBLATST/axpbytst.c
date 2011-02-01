#include "atlas_misc.h"
#include <assert.h>

#define dumb_seed(iseed_) srand(iseed_)
#ifndef RAND_MAX  /* rather dangerous non-ansi workaround */
   #define RAND_MAX ((unsigned long)(1<<30))
#endif
#define dumb_rand() ( 0.5 - ((double)rand())/((double)RAND_MAX) )
#ifdef TEST_F77
   ___main(){} __main(){} MAIN__(){} _MAIN_(){}
#include "atlas_f77blas.h"
static void TEST_AXPBY
   (const int N, const SCALAR alpha, const TYPE *X, const int incX,
    const SCALAR beta, TYPE *Y, const int incY)
{

   #ifdef ATL_FunkyInts
      const F77_INTEGER F77N=N, F77incX=incX, F77incY=incY;
   #else
      const int F77N=N, F77incX=incX, F77incY=incY;
   #endif
   #ifdef TREAL
      F77axpby(&F77N, &alpha, X, &F77incX, &beta, Y, &F77incY);
   #else
      F77axpby(&F77N, alpha, X, &F77incX, beta, Y, &F77incY);
   #endif
}
#else
   #include "cblas.h"
   #define TEST_AXPBY Mjoin(Mjoin(catlas_,PRE),axpby)
#endif

#ifdef TREAL
void good_axpby(const int N, const SCALAR alpha, const TYPE *X, const int incX,
                const SCALAR beta, TYPE *Y, const int incY)
{
   int i;
   for (i=0; i < N; i++, Y += incY, X += incX) *Y = alpha * *X + beta * *Y;
}
int checkY(int N, TYPE *Yg, int incYg, TYPE *Yc, int incYc)
{
   int i, iret=0;
   TYPE eps, diff;
   TYPE Mjoin(PATL, epsilon)(void);
   eps = Mjoin(PATL,epsilon)();

   for (i=0; i < N; i++, Yg += incYg, Yc += incYc)
   {
      diff = *Yg - *Yc;
      diff = Mabs(diff);
      if (diff > 4*eps)
      {
         iret = i;
         fprintf(stderr, "ERROR: Y[%d], correct=%f, computed=%f\n", 
                 i, *Yg, *Yc);
      }
   }
   return(iret);
}
int CheckPad(int npad, TYPE padval, int N, TYPE *Y, int incY)
{
   int i, iret=0;

   incY = Mabs(incY);
   for (i=0; i < npad; i++)
   {
      if (Y[i] != padval)
      {
         iret = i;
         fprintf(stderr, "OVERWRITE %f IN PREPAD %d before beginning of Y!!\n",
                 Y[i], npad-i);
      }
   }
   Y += npad;
   if (incY != 1)
   {
      for (i=0; i < N*incY; i++)
      {
         if (i%incY)
         {
            if (Y[i] != padval)
            {
               iret = i;
               fprintf(stderr, "INTERNAL OVERWRITE %f AT POSITION %d!!\n", 
                       Y[i], i);
            }
         }
      }
   }
   Y += 1 + (N-1)*incY;
   for (i=0; i < npad; i++)
   {
      if (Y[i] != padval)
      {
         iret = i;
         fprintf(stderr, "OVERWRITE %f IN POSTPAD %d past end of Y!!\n", 
                 Y[i], i+1);
      }
   }
   return(iret);
}
#else
void good_axpby(const int N, const SCALAR alpha, const TYPE *X, const int incx,
                const SCALAR beta, TYPE *Y, const int incy)
{
   int i;
   const int incX=incx+incx, incY=incy+incy;
   const register TYPE ra=(*alpha), ia=alpha[1], rb=(*beta), ib=beta[1];
   register TYPE rx, ix, ry, iy;

   for (i=0; i < N; i++, Y += incY, X += incX)
   {
      rx = *X; ix = X[1];
      ry = *Y; iy = Y[1];
      *Y   = rx * ra - ix * ia + rb * ry - ib * iy;
      Y[1] = rx * ia + ix * ra + rb * iy + ib * ry;
   }
}
int checkY(int N, TYPE *Yg, int incYg, TYPE *Yc, int incYc)
{
   int i, iret=0;
   TYPE rdiff, idiff, eps, maxerr;
   TYPE Mjoin(PATL, epsilon)(void);
   eps = Mjoin(PATL,epsilon)();
   maxerr = 9*eps;
   incYg *= 2; incYc *= 2;
   for (i=0; i < N; i++, Yg += incYg, Yc += incYc)
   {
      rdiff = *Yg - *Yc;
      idiff = Yg[1] - Yc[1];
      rdiff = Mabs(rdiff);
      idiff = Mabs(idiff);
      if (rdiff > maxerr) 
      {
         iret = i;
         fprintf(stderr, "ERROR: Y[%d], real, correct=%e, computed=%e\n", 
                 i, *Yg, *Yc);
      }
      if (idiff > maxerr)
      {
         iret = i;
         fprintf(stderr, "ERROR: Y[%d], imag, correct=%e, computed=%e\n", 
                 i, Yg[1], Yc[1]);
      }
   }
   return(iret);
}
int CheckPad(int npad, TYPE padval, int N, TYPE *Y, int incY)
{
   int i, n, iret=0;

   incY = Mabs(incY);
   npad *= 2;
   for (i=0; i < npad; i++)
   {
      if (Y[i] != padval)
      {
         iret = i;
         fprintf(stderr, "OVERWRITE %f IN PREPAD %d before beginning of Y!!\n",
                 Y[i], npad-i);
      }
   }
   Y += npad;
   if (incY != 1)
   {
      for (i=0; i < N*incY; i++)
      {
         if (i%incY)
         {
            if (Y[2*i] != padval)
            {
               iret = i;
               fprintf(stderr, "INTERNAL REAL OVERWRITE %f AT POSITION %d!!\n", 
                       Y[2*i], i);
            }
            if (Y[2*i+1] != padval)
            {
               iret = i+1;
               fprintf(stderr, "INTERNAL IMAG OVERWRITE %f AT POSITION %d!!\n", 
                       Y[2*i+1], i);
            }
         }
      }
   }
   Y += 2 + 2*(N-1)*incY;
   for (i=0; i < npad; i++)
   {
      if (Y[i] != padval)
      {
         iret = i;
         fprintf(stderr, "OVERWRITE %f IN POSTPAD %d past end of Y!!\n", 
                 Y[i], i+1);
      }
   }
   return(iret);
}
#endif

static int CheckY(int npad, TYPE padval, int N, TYPE *Yg, int incYg,
                  TYPE *Yt, int incYt)
{
   int i0, i1;
   incYg = Mabs(incYg);
   incYt = Mabs(incYt);
   i0 = checkY(N, Yg+(npad SHIFT), incYg, Yt+(npad SHIFT), incYt);
   i1 = CheckPad(npad, padval, N, Yt, incYt);
   if (!i0 && !i1) return(0);
   return(1);
}
static void vecset(int N, TYPE alpha, TYPE *X)
{
   int i;
   #ifdef TCPLX
      N *= 2;
   #endif
   for (i=0; i < N; i++) X[i] = alpha;
}

static TYPE *getvec(int npad, TYPE padval, int N, int incX)
{
   TYPE *X, *x;
   int i, n;

   if (N <= 0) return(NULL);
   incX = Mabs(incX);
   n = 2*npad + 1+(N-1)*incX;
   X = malloc( ATL_sizeof*n );
   assert(X);
   vecset(n, padval, X);
   #ifdef TCPLX
      npad *= 2;
      incX *= 2;
   #endif
   x = X + npad;
   for (i=0; i < N; i++, x += incX)
   {
      #ifdef TREAL
         *x = dumb_rand();
      #else
         *x   = dumb_rand();
         x[1] = dumb_rand();
      #endif
   }
   return(X);
}

static void copyvec(int N, const TYPE *X, int incX, TYPE *Y, int incY)
{
   int i;
   #ifdef TREAL
      for (i=0; i < N; i++, X += incX, Y += incY) *Y = *X;
   #else
      incX *= 2; incY *= 2;
      for (i=0; i < N; i++, X += incX, Y += incY) { *Y = *X; Y[1] = X[1]; }
   #endif
}

static TYPE *dupvec(int npad, int N, TYPE *X, int incX)
{
   int i, n;
   TYPE *y;

   incX = Mabs(incX);
   n = 1+(N-1)*incX + 2*npad;
   y = malloc(ATL_sizeof*n);
   assert(y);
   #ifdef TCPLX
      n *= 2;
   #endif
   for (i=0; i < n; i++) y[i] = X[i];
   return(y);
}

static TYPE *gen_dupvec(int N, TYPE padval, int npadX, TYPE *X, int incX,
                        int npadY, int incY)
{
   int i, n;
   TYPE *y, *yy, *xx=X+(npadX SHIFT);

   y = getvec(npadY, padval, N, incY);
   yy = y + (npadY SHIFT);
   if (incY < 1) yy -= ((N-1)SHIFT) * incY;
   if (incX < 1) xx -= ((N-1)SHIFT) * incX;
   copyvec(N, xx, incX, yy, incY);
   return(y);
}

int DoTest(int N, TYPE *alpha0, TYPE *beta0, int incX, int incY)
{
   int iret;
   const int npad=Mmax(4*Mabs(incY), 16);
   const TYPE padval=(-2271.0);
   TYPE *Yg, *Yt, *X, *x, *y;
   #ifdef TREAL
      TYPE alpha = *alpha0, beta = *beta0;
   #else
      TYPE *alpha = alpha0, *beta = beta0;
   #endif

   Yg = getvec(npad, padval, N, incY);
   Yt = dupvec(npad, N, Yg, incY);
   X  = getvec(0, padval, N, incX);  /* no padding for read-only X */

   x = X;
   y = Yg + (npad SHIFT);
   if (incX < 1) x -= ((N-1)SHIFT) * incX;
   if (incY < 1) y -= ((N-1)SHIFT) * incY;
   good_axpby(N, alpha, x, incX, beta, y, incY);
   y = Yt + (npad SHIFT);
   if (incY < 1) y -= ((N-1)SHIFT) * incY;
   TEST_AXPBY(N, alpha, X, incX, beta, Yt+(npad SHIFT), incY);
   iret = CheckY(npad, padval, N, Yg, incY, Yt, incY);
   free(X);
   free(Yg);
   free(Yt);
   return(iret);
}

int DoAllTests(int nN, int *Ns, int nX, int *Xs, int nY, int *Ys, 
               int nalpha, TYPE *alp, int nbeta, TYPE *bet)
{
   int in, ix, iy, ia, ib, iret=0, i=0, j, k;
   char *passfail;

#ifdef TREAL
   char *t1="  ITST         N     alpha      beta  incX  incY    TEST";
   char *t2="======  ========  ========  ========  ====  ====  ======";
#else
   char *t1 =
   "  ITST         N    ralpha   ialpha     rbeta    ibeta  incX  incY    TEST";
   char *t2 =
   "======  ========  ======== ========  ======== ========  ====  ====  ======";
#endif
   fprintf(stdout, "%s\n", t1);
   fprintf(stdout, "%s\n", t2);
   for (in=0; in < nN; in++)
   {
      for (ix=0; ix < nX; ix++)
      {
         for (iy=0; iy < nY; iy++)
         {
            for (ia=0; ia < nalpha; ia++)
            {
               for (ib=0; ib < nbeta; ib++)
               {
                  j = DoTest(Ns[in], alp+(ia SHIFT), bet+(ib SHIFT), 
                             Xs[ix], Ys[iy]);
                  iret += j;
                  if (j == 0) passfail = "PASSED";
                  else passfail = "FAILED";
                  #ifdef TREAL
                     fprintf(stdout, "%6d %9d %9.2f %9.2f %5d %5d  %s\n", i,
                            Ns[in], alp[ia], bet[ib], Xs[ix], Ys[iy], passfail);
                  #else
                     fprintf(stdout, 
                             "%6d %9d  %8.2f %8.2f  %8.2f %8.2f %5d %5d  %s\n", 
                             i, Ns[in], alp[2*ia], alp[2*ia+1],  
                             bet[2*ib], bet[2*ib+1], Xs[ix], Ys[iy], passfail);
                  #endif
                  i++;
               }
            }
         }
      }
   }
   if (iret == 0) fprintf(stdout, "ALL AXPBY SANITY TESTS PASSED.\n\n");
   else fprintf(stdout, "%d of %d AXPBY TESTS FAILED!!\n\n", iret, i);
   return(iret);
}

void PrintUsage(char *nam)
{
   fprintf(stderr, 
      "USAGE: %s -N # n1 ... n# -n <n> -X # x1 ... x# -Y # y1 ... y# -a # alpha1 ... alpha# -b # beta1 ... beta#\n", nam);
   exit(-1);
}

void GetFlags(int nargs, char **args, int *nN, int **Ns, int *nX, int **incXs,
              int *nY, int **incYs, int *nal, TYPE **alphas, 
              int *nbe, TYPE **betas)
{
   int i, j;

   *nal = *nbe = -1;
   *nY = *nX = *nN = -1;

   for (i=1; i < nargs; i++)
   {
      if (args[i][0] != '-') PrintUsage(args[0]);
      if (i == nargs-1) PrintUsage(args[0]);
      switch(args[i][1])
      {
      case 'a':
         *nal = atoi(args[++i]);
         if (*nal > nargs-i) PrintUsage(args[0]);
         *alphas = malloc(ATL_MulBySize(*nal));
         assert(*alphas);
         for (j=0; j < *nal SHIFT; j++) (*alphas)[j] = atof(args[++i]);
         break;
      case 'b':
         *nbe = atoi(args[++i]);
         if (*nbe > nargs-i) PrintUsage(args[0]);
         *betas = malloc(ATL_MulBySize(*nbe));
         assert(*betas);
         for (j=0; j < *nbe SHIFT; j++) (*betas)[j] = atof(args[++i]);
         break;
      case 'Y':
         *nY = atoi(args[++i]);
         if (*nY > nargs-i) PrintUsage(args[0]);
         *incYs = malloc((*nY)*sizeof(int));
         assert(*incYs);
         for (j=0; j < *nY; j++) (*incYs)[j] = atoi(args[++i]);
         break;
      case 'X':
         *nX = atoi(args[++i]);
         if (*nX > nargs-i) PrintUsage(args[0]);
         *incXs = malloc((*nX)*sizeof(int));
         assert(*incXs);
         for (j=0; j < *nX; j++) (*incXs)[j] = atoi(args[++i]);
         break;
      case 'N':
         *nN = atoi(args[++i]);
         if (*nN > nargs-i) PrintUsage(args[0]);
         *Ns = malloc((*nN)*sizeof(int));
         assert(*Ns);
         for (j=0; j < *nN; j++) (*Ns)[j] = atoi(args[++i]);
         break;
      case 'y':
         *nY = 1;
         *incYs = malloc(sizeof(int));
         assert(*incYs);
         **incYs = atoi(args[++i]);
         break;
      case 'x':
         *nX = 1;
         *incXs = malloc(sizeof(int));
         assert(*incXs);
         **incXs = atoi(args[++i]);
         break;
      case 'n':
         *nN = 1;
         *Ns = malloc(sizeof(int));
         assert(*Ns);
         **Ns = atoi(args[++i]);
         break;
      default:
         PrintUsage(args[0]);
      }
   }
   if (*nN < 0)
   {
      *nN = 33;
      *Ns = malloc((*nN)*sizeof(int));
      assert(*Ns);
      **Ns = 777;
      for (i=1; i <= 32; i++) (*Ns)[i] = i;
   }
   if (*nX < 0)
   {
      *nX = 4;
      *incXs = malloc((*nX)*sizeof(int));
      **incXs = 1;
      (*incXs)[1] = 2;
      (*incXs)[2] = -3;
      (*incXs)[3] = 4;
   }
   if (*nY < 0)
   {
      *nY = 4;
      *incYs = malloc((*nY)*sizeof(int));
      assert(*incYs);
      **incYs = 1;
      (*incYs)[1] = 2;
      (*incYs)[2] = -2;
      (*incYs)[3] = 3;
   }
   if (*nal < 1)
   {
      #ifdef TREAL
         *nal = 3;
         *alphas = malloc(ATL_MulBySize(3));
         assert(*alphas);
         (*alphas)[0] = 1.0;
         (*alphas)[1] = -1.0;
         (*alphas)[2] = 0.9;
      #else
         *nal = 4;
         *alphas = malloc(ATL_MulBySize(4));
         assert(*alphas);
         (*alphas)[0] = 1.0;
         (*alphas)[1] = 0.0;
         (*alphas)[2] = -1.0;
         (*alphas)[3] = 0.0;
         (*alphas)[4] = 1.3; 
         (*alphas)[5] = 0.0; 
         (*alphas)[6] = 0.9; 
         (*alphas)[7] = 1.1; 
      #endif
   }
   if (*nbe < 1)
   {
      #ifdef TREAL
         *nbe = 3;
         *betas = malloc(ATL_MulBySize(3));
         assert(*betas);
         (*betas)[0] = 1.0;
         (*betas)[1] = -1.0;
         (*betas)[2] = 0.8;
      #else
         *nbe = 4;
         *betas = malloc(ATL_MulBySize(4));
         assert(*betas);
         (*betas)[0] = 1.0;
         (*betas)[1] = 0.0;
         (*betas)[2] = -1.0;
         (*betas)[3] = 0.0;
         (*betas)[4] = 1.2; 
         (*betas)[5] = 0.0; 
         (*betas)[6] = 1.1; 
         (*betas)[7] = 0.8; 
      #endif
   }
}

main(int nargs, char **args)
{
   int nN, nX, nY, nal, nbe;
   int *Ns, *incXs, *incYs;
   TYPE *alphas=NULL, *betas=NULL;
   int ierr;
   GetFlags(nargs, args, &nN, &Ns, &nX, &incXs, &nY, &incYs, 
            &nal, &alphas, &nbe, &betas);
   ierr = DoAllTests(nN, Ns, nX, incXs, nY, incYs, nal, alphas, nbe, betas);
   if (alphas) free(alphas);
   if (betas) free(betas);
   free(incXs);
   free(incYs);
   exit(ierr);
}
