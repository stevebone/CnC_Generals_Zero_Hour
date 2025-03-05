#ifndef __J2K__LZH__HuffStat_CPP__
#define __J2K__LZH__HuffStat_CPP__

void shellSort( HuffStatTmpStruct* a, int N );

HuffStat::HuffStat() 
{
  stat = new HUFFINT[ NHUFFSYMBOLS ];
  memset( stat, 0, sizeof(HUFFINT) * NHUFFSYMBOLS );
}

HuffStat::~HuffStat() 
{
  delete [] stat;
}

int HuffStat::makeSortedTmp( HuffStatTmpStruct* s ) 
{
  int total = 0;
  for( int j = 0; j < NHUFFSYMBOLS ; j++ ) {
    s[ j ].i = j;
    s[ j ].n = stat[ j ];
    total += stat[ j ];
    stat[ j ] = HUFFRECALCSTAT( stat[ j ] );
  }

  //qsort( s, NHUFFSYMBOLS, sizeof(HuffStatTmpStruct), _cmpStat );
  shellSort( s - 1, NHUFFSYMBOLS );
  return total;
}

#endif
