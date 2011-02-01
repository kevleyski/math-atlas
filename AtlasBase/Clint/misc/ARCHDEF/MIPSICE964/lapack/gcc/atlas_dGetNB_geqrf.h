#ifndef ATL_dGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='LOWER'
 * M : 25,50,75,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000
 * N : 25,50,75,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000
 * NB : 1,8,8,12,12,24,24,24,24,24,24,24,24,24,24,36,36,36,36,48,48,48,48,48
 */
#define ATL_dGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 37) (nb_) = 1; \
   else if ((n_) < 87) (nb_) = 8; \
   else if ((n_) < 137) (nb_) = 12; \
   else if ((n_) < 650) (nb_) = 24; \
   else if ((n_) < 1100) (nb_) = 36; \
   else (nb_) = 48; \
}


#endif    /* end ifndef ATL_dGetNB_geqrf */
