#! /usr/bin/python

import sys
import fkocmnd
import l1cmnd

optT = "-X 1 1 -Y 1 1 -Fx 16 -Fy 16"
#
# Given set of arrs that are write-only (no uses), tries using non-temporal
# writes
#
def ifko_writeNT(ATLdir, ARCH, KF0, fko, rout, pre, l1bla, N, wnt):
#
#  Time the default case
#
   warrs = []
   fkocmnd.callfko(fko, KF0)
   [t0,m0] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                         "gcc", "-x assembler-with-cpp", opt=opt)
   print "WNT none : %.2f" % (m0)
   for wa in wnt:
      KFN = KF0 + " -W " + wa
      fkocmnd.callfko(fko, KFN)
      [tN,mN] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                            "gcc", "-x assembler-with-cpp", opt=opt)
      print "WNT %s : %2.f" % (wa, mN)
      if mN > m0:
         KF0 = KFN
         m0 = mN
         warrs.append(wa)
      
   return [m0,KF0,warrs]
#
#  Given a set of flags, try differing pf inst for read & write arrays
#
def ifko_pftype(ATLdir, ARCH, KF0, ncache, fko, rout, pre, blas, N,
                info, pfarrs, pfsets):
#
#  Time the default case
#
   fkocmnd.callfko(fko, KF0)
   [t0,m0] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                         "gcc", "-x assembler-with-cpp", opt=opt)
   assert(t0 > 0.0)
   print "   base mf = %f.2" % m0
   KF = KF0
#
#  If there are output arrays, varying inst used for writes
#
   SETS = 0
   for i in pfsets:
      if i:
         SETS = 1
         break

   if SETS:
#
#     Try using 3DNow's prefetchw for all writes
#
      KF = KF0 + " -Paw 3"
      fkocmnd.callfko(fko, KF)
      [t1,m1] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                            "gcc", "-x assembler-with-cpp", opt=opt)
      if (m1 > 0.0):
         print "   prefetchw speedup: %.3f !" %  (m1/m0)
#
#     Try temporal prefetch
#
      KF1 = KF0 + " -Paw 0"
      fkocmnd.callfko(fko, KF1)
      [t2,m2] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                            "gcc", "-x assembler-with-cpp", opt=opt)
      print "   prefetchw speedup: %.3f !" %  (m2/m0)

      if m2 > m1:
         m1 = m2
         KF = KF1
      if m1 > m0:
         m0 = m1
         KF0 = KF
#
#  If we've got read-only arrays, try a varying pref inst for reads
#
   READO = 0
   for i in pfsets:
      if not i:
         READO = 1
         break
   if READO:
      KF = KF0 + " -Par 0"
      fkocmnd.callfko(fko, KF)
      [t1,m1] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                            "gcc", "-x assembler-with-cpp", opt=opt)
      print "   prefetchr speedup: %.3f !" %  (m1/m0)
      if m1 > m0:
         KF0 = KF
         m0 = m1
       
#
#  For each array, find best cache level to fetch to
#
   NC = info[0]
   LS = info[1]
   for arr in pfarrs:
      j = 1
      while j < NC:
         KF = " -P %s %d %d" % (arr, j, LS[j])
         KF = KF0 + KF
         fkocmnd.callfko(fko, KF)
         [t1,m1] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                               "gcc", "-x assembler-with-cpp", opt=opt)
         print "   lvl %d %s speedup: %.3f !" %  (j, arr, m1/m0)
         if m1 > m0:
            KF0 = KF
            m0 = m1
   return [m0,KF0]

#
# attempt to find best prefetch distance for given array
#
def FindPFD(ATLdir, ARCH, KF0, fko, rout, pre, blas, N, info, arr,
            pfd0=0, pfdN=2048, pfdinc=0):
   st = "-P %s " % (arr)
   j = KF0.find(st)
   if j == -1:
      j = KF0.find("-P all ")
      assert(j != -1)
      j += 7
   else:
      j += 4 + arr.len()
   words = KF0[j:].split()
   pflvl = int(words[0])
   LS = info[1][pflvl];
   if not pfd0: pfd0 = LS
   if not pfdinc: pfdinc = LS
   print "\n   Finding PFD for %s in [%d:%d:%d]" % (arr, pfd0, pfdN, pfdinc)
   ipd = int(words[1])
   pfd = pfd0
   mfM = 0.0
   pfdM = 0
   KF0 = KF0 + " -Ps b A 0 1"
   while pfd <= pfdN:
      KFn = KF0 + " -P %s %d %d" % (arr, pflvl, pfd)
      fkocmnd.callfko(fko, KFn)
      [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                           "gcc", "-x assembler-with-cpp", opt=opt)
#      mfs.append(mf)
      print "      %s : PFD = %d mflop = %.2f" % (arr, pfd, mf)
#
#     Demand higher PFD is at least 1.0001 faster
#
      if mf > mfM*1.0001:
         mfM = mf
         pfdM = pfd
      pfd += LS
   print "\n   BEST prefetch distance = %d (%.2f)" % (pfdM, mfM)
#
#  Try not prefetching array at all
#
   KFn = KF0 + " -P %s -1 0" % (arr)
   print KFn
   fkocmnd.callfko(fko, KFn)
   [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                        "gcc", "-x assembler-with-cpp", opt=opt)
   print "      %s : NO PREFETCH:   mflop = %.2f" % (arr, mf)
   if mf >= mfM:
      KF0 = KF0 + " -P %s -1 0" % (arr)
      mfM = mf
   elif pfdM != ipd:
      KF0 = KF0 + " -P %s %d %d" % (arr, pflvl, pfdM)
   return [mfM,KF0]

def FindUR(ATLdir, ARCH, KF0, fko, rout, pre, blas, N, info, UR0=1, URN=64):

   print "   Finding best unroll:"
#
#  Get rid of default unrolling so we can add our own
#
   j = KF0.find("-U ")
   if j != -1:
      words = KF0[j:].split()
      if (j != 0): KF0 = KF0[0:j]
      else : KF0 = ""
      for word in words[2:]:
         KF0 = KF0 + " "  + word
   UR = UR0
   mf0 = 0
   URB = 1
   while UR <= URN:
      KFn = KF0 + " -U %d" % (UR)
      fkocmnd.callfko(fko, KFn)
      [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, blas, N, "fkorout.s", 
                           "gcc", "-x assembler-with-cpp", opt=opt)
      print "      UR=%d, mflop=%.2f" % (UR, mf)
#
#     Demand that higher unrollings get at least 1% better
#
      if (mf >= mf0*1.01):
         URB = UR
         mf0 = mf
      UR *= 2

   KF0 = KF0 + " -U %d" % URB
   return [mf0,KF0]

#
# Returns array of indexes in st0 that are also in st1
#
def FindMatchList(st0, st1):
   n0 = len(st0)
   n1 = len(st1)
   i = 0
   matches = []
   while i < n0:
      j = 0
      while j < n1:
         if st0[i] == st1[j] or \
            (len(st0[i]) == len(st1[j]) and st0[i].find(st1[j]) != -1):
            matches.append(i)
         j += 1
      i += 1
   return(matches)
def ifko0(l1bla, pre, N):
   (IFKOdir, fko) = fkocmnd.GetFKOinfo()
   (ATLdir, ARCH) = fkocmnd.FindAtlas(IFKOdir)
   rout =  IFKOdir + '/blas/' + pre + l1bla + '.b'
   outf =  ATLdir + '/tune/blas/level1/' + l1bla.upper() + '/fkorout.s'
   info = fkocmnd.info(fko, rout)
   ncache = info[0]
   (fparrs, fpsets, fpuses) = fkocmnd.GetFPInfo(info)
   nfp = len(fparrs)
   KFLAGS = fkocmnd.GetStandardFlags(fko, rout, pre)
   KFLAGS = KFLAGS + " -o " + str(outf) + " " + rout
   mflist = []
   testlist = []
#
#  Find performance of default case
#
   j = KFLAGS.find("-V")
   if j != -1 :
      KFn = KFLAGS[0:j-1] + KFLAGS[j+2:]
      fkocmnd.callfko(fko, KFn)
      [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, l1bla, N, "fkorout.s", 
                           "gcc", "-x assembler-with-cpp", opt=opt)
      mflist.append(mf)
      testlist.append("default")
      fkocmnd.callfko(fko, KFLAGS)
      [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, l1bla, N, "fkorout.s", 
                           "gcc", "-x assembler-with-cpp", opt=opt)
   else :
      fkocmnd.callfko(fko, KFLAGS)
      [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, l1bla, N, "fkorout.s", 
                           "gcc", "-x assembler-with-cpp", opt=opt)
      testlist.append("default")
      mflist.append(mf)
   mflist.append(mf)
   testlist.append("vect")
#
#  Eventually, want to try both -V and scalar, but for now, use -V whenever
#  possible

#
#  Find if we want to use cache-through writes on any arrays
#
   n = len(fpsets)
   i = 0
   wnt = []
   while i < n:
      if fpsets[i] > 0 and fpuses[i] == 0:
         wnt.append(fparrs[i])
      i += 1
   if len(wnt) > 0:
      [mf,KFLAGS,wnt] = ifko_writeNT(ATLdir, ARCH, KFLAGS, fko, rout, pre,
                                     l1bla, N, wnt)
   mflist.append(mf)
   testlist.append("writeNT")
#
#  Don't try prefetching non-temporal arrays
#
   if len(wnt) > 0:
      mat = FindMatchList(fparrs, wnt)
      i = 0;
      n = len(fparrs)
      pfarrs = []
      pfsets = []
      while i < n:
         if wnt.count(i) == 0:
            pfarrs.append(fparrs[i])
            pfsets.append(fpsets[i])
         i += 1
      print "\n   FLAGS so far =", fkocmnd.RemoveFilesFromFlags(l1bla, KFLAGS)
   else :
      pfarrs = fparrs
      pfsets = fpsets
#
#  Find best pf type
#
   [mf,KFLAGS] = ifko_pftype(ATLdir, ARCH, KFLAGS, ncache, fko, rout, pre, 
                             l1bla, N, info, pfarrs, pfsets)
   mflist.append(mf)
   testlist.append("pftype")
   print "\n   FLAGS so far =", fkocmnd.RemoveFilesFromFlags(l1bla, KFLAGS)
#
#  Find best PFD for each pfarr
#
   for arr in pfarrs:
      [mf,KFLAGS] = FindPFD(ATLdir, ARCH, KFLAGS, fko, rout, pre,l1bla, N, 
                            info, arr)
   mflist.append(mf)
   testlist.append("pfdist")
   KFLAGS = fkocmnd.RemoveRedundantPrefFlags(KFLAGS, pfarrs)
#
#  Find best unroll
#
   [mf,KFLAGS] = FindUR(ATLdir, ARCH, KFLAGS, fko, rout, pre, l1bla, N, info)
   mflist.append(mf)
   testlist.append("unroll")
#
#  Find performance of best case
#
#   fkocmnd.callfko(fko, KFLAGS)
#   [t,mf] = l1cmnd.time(ATLdir, ARCH, pre, l1bla, N, "fkorout.s", 
#                        "gcc", "-x assembler-with-cpp", opt=opt)
   print "\n\n   BEST FLAGS FOUND (%f.2) = %s" % (mf,
         fkocmnd.RemoveFilesFromFlags(l1bla, KFLAGS))
   res = fkocmnd.GetOptVals(KFLAGS, pfarrs, pfsets)
   tst = l1cmnd.test(ATLdir, ARCH, pre, l1bla, N, "fkorout.s",
                     cc="gcc", ccf="-x assembler-with-cpp", opt=optT)
   return(res, KFLAGS, mf, tst, testlist, mflist)

def ifko(routs, pres, N):
   if routs.find("default") != -1:
      routlist = l1cmnd.GetDefaultBlas()
   else:
      words = routs.split(",")
      routlist = []
      for word in words:
          routlist.append(word)
   if pres.find("default") != -1:
      prelist = l1cmnd.GetDefaultPre()
   else:
      words = pres.split(",")
      prelist = []
      for word in words:
         prelist.append(word)

   reslist = []
   blalist = []
   mflist = []
   tstlist = []
   ideclist = []
   idecmflist = []
   for l1bla in routlist:
      for pre in prelist:
         print "\niFKO TUNING %s" % (pre + l1bla)
         (res,flags,mf,tst,dec,decmf) = ifko0(l1bla, pre, N)
         reslist.append(res)
         blalist.append(pre + l1bla)
         mflist.append(mf)
         tstlist.append(tst)
         ideclist.append(dec)
         idecmflist.append(decmf)
   i = 0
   n = len(reslist)
   while i < n :
      (vec, UR, npf, pfinst, pfd) = reslist[i]
      if vec: sv = "Yes"
      else : sv = "No"
      pfdX = pfd[0]
      if pfinst[0].find("none") != -1: pfIX = pfinst[0]
      else : pfIX = r"{\tt " + pfinst[0] + "}"
      if npf == 2 :
         pfdY = pfd[1]
         if pfinst[1].find("none") != -1: pfIY = pfinst[1]
         else : pfIY = r"{\tt " + pfinst[1] + "}"
      else :
         pfdY = 0
         pfIY = "N/A"
      print "%10s &%3s &%4d &%5d &%17s &%5d &%17s\\\\\\hline" % \
            (r"{\tt " + blalist[i]+"}", sv, UR, pfdX, pfIX, pfdY, pfIY)
      i += 1
   i = 0
   print "\n"
   while i < n :
      if tstlist[i] : tst = "FAIL"
      else : tst = "PASS"
      print "%10s : %5.5s %9.2f" % (blalist[i], tst, mflist[i])
      i += 1
   i = 0
   print "\n"
   m = len(ideclist[0])
   st = "%7.7s" % ("BLAS")
   j = 1
   while j < m:
      st = st + " %6.6s" % (ideclist[0][j])
      j += 1
   print st
   while i < n :
      st = "%7.7s" % blalist[i]
      j = 1
      while j < m :
         st = st + " %6.2f" % (idecmflist[i][j] / idecmflist[i][j-1])
         j += 1
      print st
      i += 1

nargs = len(sys.argv)
blas = "asum"
pre  = "s"
N = 80000
N = 1024
uopt =""
if (nargs > 1):
   blas = sys.argv[1]
   if (nargs > 2):
      pre = sys.argv[2]
      if (nargs > 3):
         N = int(sys.argv[3])
         if (nargs > 4):
            uopt = sys.argv[4]
opt = "-X 1 -Y 1 -Fx 16 -Fy 16 " + uopt
print opt
ifko(blas, pre, N)
