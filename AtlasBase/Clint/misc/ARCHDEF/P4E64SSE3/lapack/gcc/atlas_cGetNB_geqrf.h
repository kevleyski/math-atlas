#ifndef ATL_cGetNB_geqrf

/*
 * NB selection for GEQRF: Side='RIGHT', Uplo='UPPER'
 * M : 25,152,228,380,836,1672
 * N : 25,152,228,380,836,1672
 * NB : 9,12,76,76,76,76
 */
#define ATL_cGetNB_geqrf(n_, nb_) \
{ \
   if ((n_) < 88) (nb_) = 9; \
   else if ((n_) < 190) (nb_) = 12; \
   else (nb_) = 76; \
}


#endif    /* end ifndef ATL_cGetNB_geqrf */
