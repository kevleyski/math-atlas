#ifndef ATL_cGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='LOWER'
 * M : 25,50,75,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000
 * N : 25,50,75,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000
 * NB : 4,8,8,8,8,12,12,12,12,16,24,32,28,32,32,28,64,64,64,64,64,64,64,80
 */
#define ATL_cGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 37) (nb_) = 4; \
   else if ((n_) < 137) (nb_) = 8; \
   else if ((n_) < 275) (nb_) = 12; \
   else if ((n_) < 325) (nb_) = 16; \
   else if ((n_) < 375) (nb_) = 24; \
   else if ((n_) < 425) (nb_) = 32; \
   else if ((n_) < 475) (nb_) = 28; \
   else if ((n_) < 650) (nb_) = 32; \
   else if ((n_) < 750) (nb_) = 28; \
   else if ((n_) < 1900) (nb_) = 64; \
   else (nb_) = 80; \
}


#endif    /* end ifndef ATL_cGetNB_geqrf */
