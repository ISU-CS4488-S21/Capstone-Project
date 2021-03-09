#include "unit_commitment.h"
#include "generator.h"
#include "economic_dispatch.h"

Unit_Commitment::Unit_Commitment(Generator genArray[], int pLoad, int tc){
  overallGenArray = genArray;
  predictedLoad = pLoad;
  timeCycle = tc;
}

Generator * Unit_Commitment::getOptimizedArray(){
  //Where we implement the algorithm
  return optimizedGenArray;
}

int Unit_Commitment::getEconomicDispatch(){
  ecoDis = new Economic_Dispatch(overallGenArray,predictedLoad);
  return ecoDis;
}
