typedef union {
  char* str;
  MenuElem* mItem;
  AttrStream* aStream;
  unsigned int modifier;
} YYSTYPE;
#define	VARIABLE	257
#define	MENU	258
#define	SHORTCUT	259
#define	APP	260
#define	KEY	261
#define	IND	262
#define	EXITDLG	263
#define	STARTUP	264
#define	ACC	265
#define	VAR	266
#define	STRING	267
#define	FUNC	268
#define	PLUS	269
#define	MINUS	270


extern YYSTYPE yylval;
