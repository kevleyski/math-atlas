#ifndef FKO_SYMTAB_H
#define FKO_SYMTAB_H

#define T_INT        0
#define T_SHORT      1
#define T_FLOAT      2
#define T_DOUBLE     3
#define T_CHAR       4
#define T_FUNC       5
#define T_LABEL      6

#define IS_INT(flag_)  (((flag_) & 0x7) == T_INT)
#define IS_SHORT(flag_)  (((flag_) & 0x7) == T_SHORT)
#define IS_FLOAT(flag_)  (((flag_) & 0x7) == T_FLOAT)
#define IS_DOUBLE(flag_)  (((flag_) & 0x7) == T_DOUBLE)
#define IS_CHAR(flag_)  (((flag_) & 0x7) == T_CHAR)
#define IS_FUNC(flag_)  (((flag_) & 0x7) == T_FUNC)
#define IS_LABEL(flag_)  (((flag_) & 0x7) == T_LABEL)
#define FLAG2TYPE(flag_) ((flag_) & 0x7)

#define PTR_BIT      0x10
#define CONST_BIT    0x20
#define GLOB_BIT     0x40
#define PARA_BIT     0x80
#define VEC_BIT      0x100
#define UNSIGNED_BIT 0x200
#define LOCAL_BIT    0x400
#define DEREF_BIT    0x800

#define IS_PTR(flag_)   ((flag_) & PTR_BIT)
#define IS_CONST(flag_) ((flag_) & CONST_BIT)
#define IS_GLOB(flag_)  ((flag_) & GLOB_BIT)
#define IS_PARA(flag_)  ((flag_) & PARA_BIT)
#define IS_VEC(flag_)   ((flag_) & VEC_BIT)
#define IS_UNSIGNED(flag_)   ((flag_) & UNSIGNED_BIT)
#define IS_LOCAL(flag_) ((flag_) & LOCAL_BIT)
#define IS_DEREF(flag_) ((flag_) & DEREF_BIT)

#define IS_SETUSE(flag_) (IS_LOCAL(flag_))

#define FLAG2PTYPE(flag_) ( IS_PTR(flag_) ? T_INT : ((flag_) & 0x7) )


#define REG_SP   1

#define FKO_DVLEN 2  /* this will later be a variable */
#define FKO_SVLEN 4  /* this will later be a variable */

#ifndef NO_STEXTERN
   extern char         **STname;
   extern union valoff *SToff;
   extern int          *STflag;
#endif

short FindDerefEntry(short ptr, short ireg, short mul, short con);
short AddDerefEntry(short ptr, short reg, short mul, short con);
short STdef(char *name, int flag, int off);
short STdconstlookup(double f);
short STfconstlookup(float f);
short STiconstlookup(int ic);
short STstrlookup(char *str);
void STsetoffi(short i, int off);
void STsetflag(short i, int flag);
void NumberLocalsByType(void);
void CorrectLocalOffsets(int ldist);
int STlen(void);
char *STi2str(short i);
void CreateLocalDerefs(void);
void UpdateLocalDerefs(int);
void AddStaticData(char *name, short align, short len, void *vbytarr);
void KillStaticData(void);
void MarkUnusedLocals(BBLOCK *bbase);
void CorrectParamDerefs(struct locinit *libase, int rsav, int fsize);

#endif
