#ifndef ATL_sGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='LOWER'
 * M : 25,50,75,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000
 * N : 25,50,75,100,125,150,175,200,250,300,350,400,450,500,600,700,800,900,1000,1200,1400,1600,1800,2000
 * NB : 4,8,8,8,8,12,12,12,12,24,24,32,40,40,40,40,40,40,96,96,96,64,96,96
 */
#define ATL_sGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 37) (nb_) = 4; \
   else if ((n_) < 137) (nb_) = 8; \
   else if ((n_) < 275) (nb_) = 12; \
   else if ((n_) < 375) (nb_) = 24; \
   else if ((n_) < 425) (nb_) = 32; \
   else if ((n_) < 950) (nb_) = 40; \
   else if ((n_) < 1500) (nb_) = 96; \
   else if ((n_) < 1700) (nb_) = 64; \
   else (nb_) = 96; \
}


#endif    /* end ifndef ATL_sGetNB_geqrf */
