/***
**** make sure add/sub/mult int type would not overflow.
***/
/* from 2.30*/
int tadd_ok(int x, int y)
{
  return !(
    (x > 0 && y > 0 && x + y <= 0) ||
    (x < 0 && y < 0 && x + y >= 0)
  );
}

/* from 2.32*/
int tsub_ok(int x, int y){
    int w = sizeof(int)<<3;
    int t = x - y;
    x = x >> (w-1);    /* get sign bit*/
    y = y >> (w-1);
    t = t >> (w-1);
    return !((x != y) && (y == t));
}

/* from 2.35*/
int tmult_ok(int x, int y){
  int p = x*y;
  return !x || (p/x == y);
}
/* using long long in instead of divide*/
int tmult_ok(int x, int y){
  long long pll = (long long) x*y;   /* (long long) here is necessary for avoid 32(int) mult*/
  return pll == pll;
}
